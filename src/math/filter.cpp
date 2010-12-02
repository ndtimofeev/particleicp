#include <QPointF>
#include <QString>
#include "filter.h"

QPolygonF filter( const QVector<double>* oX, const QVector<double>* oY, double value )
{
    if ( oX->size() != oY->size() )
        qFatal( "oX->size() != oY->size()" );

    QPolygonF result;

    QVector<double>::const_iterator j = oX->begin();

    for ( QVector<double>::const_iterator i = oY->begin(); i != oY->end(); i++ )
        if ( *i > value )
            result << QPointF( *( oX->begin() + ( i - oY->begin() ) ), *i );

    return result;
}
