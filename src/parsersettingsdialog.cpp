#include <QCheckBox>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "parsersettingsdialog.h"
#include "falgorithms.h"
#include "ui_parsersettingsdialog.h"

ParserSettingsDialog::ParserSettingsDialog( const QString& path, QWidget* parent ) :
    QDialog( parent )
{
    Ui::Dialog ui;
    ui.setupUi( this );

    this->group = new QButtonGroup( this );
    this->group->setExclusive( false );

    this->list = new QStringList();

    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QStringList head = stream.readLine().split("\t");
    *this->list << head.takeFirst();
    qSort( head );
    foreach( QString tag, head )
    {
        QCheckBox* cb = new QCheckBox( tag );
        this->group->addButton( cb );
        ui.verticalLayout_3->addWidget( cb );
    }
    connect( this->group, SIGNAL( buttonPressed( QAbstractButton* ) ),
             this, SLOT( stateCatcher( QAbstractButton* ) ) );

    file.close();
}

ParserSettingsDialog::~ParserSettingsDialog()
{
    delete this->list;
}

void ParserSettingsDialog::restoreState( const QStringList& list )
{
    foreach( QAbstractButton* bt, this->group->buttons() )
        if ( fp::elem( bt->text(), list ) )
        {
            bt->setChecked( true );
            *this->list << bt->text();
        }
}

QStringList ParserSettingsDialog::saveState() const
{
    return *this->list;
}

const QStringList& ParserSettingsDialog::getReturn() const
{
    return *this->list;
}

void ParserSettingsDialog::stateCatcher( QAbstractButton* bt )
{
    if ( fp::elem( bt->text(), *this->list ) )
        this->list->removeAll( bt->text() );
    else
        *this->list << bt->text();
}

QStringList ParserSettingsDialog::getSettings( const QString& path, QWidget* parent, Settings* settings )
{
    QStringList value;
    ParserSettingsDialog dlg( path, parent );
    if ( settings )
        dlg.restoreState( settings->value( path ).toStringList() );

    if ( dlg.exec() == QDialog::Accepted )
    {
        value = dlg.getReturn();
        if ( settings )
            settings->setValue( path, dlg.saveState() );
    }

    return value;
}

