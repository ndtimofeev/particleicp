#include <QDebug>
#include "rofselector.h"

ROFAction::ROFAction( QString& path, QObject* parent ) :
    QAction( path, parent )
{
    this->path = new QString( path );
    this->connect( this, SIGNAL( triggered() ), this, SLOT( emit_engine() ) );
}

ROFAction::~ROFAction()
{
    delete this->path;
}

void ROFAction::emit_engine()
{
    emit triggered( *this->path );
}

ROFSelector::ROFSelector( QWidget* parent ) : QMenu( parent )
{
    connect( this, SIGNAL( aboutToShow() ), this, SLOT( update() ) );
    this->empty = new QAction( "empty", this );
    this->empty->setDisabled( true );
    this->addAction( this->empty );
}

ROFSelector::ROFSelector( const QStringList* history, QWidget* parent ) :
    QMenu( parent )
{
    connect( this, SIGNAL( aboutToShow() ), this, SLOT( update() ) );
    this->history = history;
    this->empty = new QAction( "empty", this );
    this->empty->setDisabled( true );
    this->addAction( this->empty );
}

ROFSelector::ROFSelector( const QStringList* history, const QString &title, QWidget* parent ) :
    QMenu( title, parent )
{
    connect( this, SIGNAL( aboutToShow() ), this, SLOT( update() ) );
    this->history = history;
    this->empty = new QAction( "empty", this );
    this->empty->setDisabled( true );
    this->addAction( this->empty );
}

ROFSelector::~ROFSelector()
{
    delete this->empty;
}

int ROFSelector::getMaxStrNum() const
{
    return this->max_str_num;
}

void ROFSelector::setMaxStrNum( int i )
{
    this->max_str_num = i;
}

void ROFSelector::update()
{
    if ( ! (*this->history).isEmpty() )
    {
        this->clear();

        QStringList list = *this->history;
        list.removeDuplicates();

        foreach ( QString path, list.mid( 0, this->max_str_num - 1 ) )
        {
            ROFAction* act = new ROFAction( path, this );
            connect( act, SIGNAL( triggered( QString& ) ),
                     this, SIGNAL( selectedFile( QString& ) ) );

            this->addAction( act );
        }
    }
}

