#include <QtAlgorithms>
#include <QFileInfo>
#include "rofselector.h"

ROFSelector::ROFSelector( QWidget* parent ) : QMenu( parent )
{
}

ROFSelector::~ROFSelector()
{
    qDeleteAll( this->history );
}

void ROFSelector::addFile( const QString& path )
{
    if ( path.isEmpty() )
        qFatal( "ROFSelector: add null path" );

    if ( *this->history.first() != path )
        this->history << new QString( path );


}
