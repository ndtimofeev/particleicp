#include "rofselector.h"

ROFSelector::ROFSelector( QWidget* parent ) : QMenu( parent )
{
    this->history = new History<QString>( 0 );
    connect( this, SIGNAL( aboutToShow() ), this, SLOT( redrawMenu() ) );
    connect( this, SIGNAL( triggered( QAction* ) ),
             this, SLOT( sendSignal( QAction* ) ) );
}

ROFSelector::~ROFSelector()
{
    delete this->history;
}

int ROFSelector::max() const
{
    return this->history->length();
}

QStringList ROFSelector::saveState() const
{
    return this->history->mid(0);
}

void ROFSelector::restoreState( const QStringList& list )
{
    *this->history = list;
}

void ROFSelector::addFile( QString path )
{
    if ( path.isEmpty() )
        qFatal( "ROFSelector: add null path" );

    this->history->push( path );
}

void ROFSelector::clearHistory()
{
    this->history->clear();
    this->redrawMenu();
}

void ROFSelector::setMax( int num )
{
    this->history->setLength( num );
}

void ROFSelector::redrawMenu()
{
    this->clear();

    if ( this->history->isEmpty() )
        this->addAction( tr("empty") )->setDisabled( true );
    else
    {
        int i = 1;

        foreach( QString str, *this->history )
            this->addAction( QString( "&" ) += QString::number(i++).append( " " )
                    += str )->setData( str );

        this->addSeparator();
        this->addAction( tr("&Clear"), this, SLOT( clearHistory() ) );
    }
}

void ROFSelector::sendSignal( QAction* act )
{
    emit fileSelected( act->data().toString() );
}

