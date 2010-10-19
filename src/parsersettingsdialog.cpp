#include <QCheckBox>
#include <QIODevice>
#include <QTextStream>
#include "parsersettingsdialog.h"
#include "ui_parsersettingsdialog.h"

ParserSettingsDialog::ParserSettingsDialog( const QTextStream& stream, QWidget* parent ) :
    QDialog( parent )
{
    Ui::Dialog ui;
    ui.setupUi( this );

    if ( ! stream.device()->isReadable() )
        qFatal( "ParserSettingsDialog: stream is not Readable" );

    this->group = new QButtonGroup( this );
    this->group->setExclusive( false );

    this->list = new QSet<QString>;

    QStringList head = QTextStream( stream.device() ).readLine().split("\t");

    *this->list << head.takeFirst();

    qSort( head );

    foreach( QString tag, head )
    {
        QCheckBox* cb = new QCheckBox( tag );
        this->group->addButton( cb );
        ui.verticalLayout_3->addWidget( cb );
    }

    connect( this->group, SIGNAL( buttonPressed( QAbstractButton* ) ),
             this,        SLOT( stateCatcher( QAbstractButton* ) ) );
}

ParserSettingsDialog::~ParserSettingsDialog()
{
    delete this->list;
    delete this->group;
}

void ParserSettingsDialog::restoreState( const QSet<QString>& list )
{
    foreach( QAbstractButton* bt, this->group->buttons() )
    {
        if ( list.contains( bt->text() )  )
        {
            bt->setChecked( true );
            *this->list << bt->text();
        }
    }
}

const QSet<QString>& ParserSettingsDialog::getState() const
{
    return *this->list;
}

void ParserSettingsDialog::stateCatcher( QAbstractButton* bt )
{
    if ( this->list->contains( bt->text() ) )
        this->list->remove( bt->text() );
    else
        *this->list << bt->text();
}

QSet<QString> ParserSettingsDialog::getSettings( QTextStream& stream, const QString& path, QWidget* parent, Settings* settings )
{
    QSet<QString> value;
    ParserSettingsDialog dlg( stream, parent );
    if ( settings )
        dlg.restoreState( settings->value( path ).toStringList().toSet() );

    if ( dlg.exec() == QDialog::Accepted )
    {
        value = dlg.getState();
        if ( settings )
            settings->setValue( path, QVariant(value.toList()) );
    }

    return value;
}

