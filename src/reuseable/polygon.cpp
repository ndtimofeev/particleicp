#include <QDebug>
#include "polygon.h"

Polygon::Polygon()
{
    this->x = new QVector<qreal>();
    this->y = new QVector<qreal>();
}

Polygon::Polygon( const QVector<qreal>* x, const QVector<qreal>* y )
{
    this->x = new QVector<qreal>( *x );
    this->y = new QVector<qreal>( *y );
}

Polygon::Polygon( const Polygon& pol )
{
    *this = pol;
}

Polygon::~Polygon()
{
    delete this->x;
    delete this->y;
}

const QVector<qreal>* Polygon::getX() const
{
    return this->x;
}

const QVector<qreal>* Polygon::getY() const
{
    return this->y;
}

int Polygon::getSize() const
{
    return this->x->size();
}

Polygon* Polygon::getInterval( qreal min, qreal max ) const
{
    Polygon* polygon = new Polygon();
    int lim = this->getSize() - 1;
    for ( int i = 0; i < lim; i++ )
    {
        if ( this->x->at(i) > max )
            break;
        if ( this->x->at(i) >= min )
            *polygon << QPointF( this->x->at(i), this->y->at(i) );
    }

    return polygon;
}

Polygon* Polygon::getMoreThen( qreal val ) const
{
    Polygon* polygon = new Polygon();
    int lim = this->getSize() - 1;
    for ( int i = 0; i < lim; i++ )
    {
        if ( this->y->at(i) > val )
            *polygon << QPointF( this->x->at(i), this->y->at(i) );
    }

    return polygon;
}

Polygon& Polygon::operator<< ( const QPointF& point )
{
    *this->x << point.x();
    *this->y << point.y();

    return *this;
}

Polygon& Polygon::operator<< ( const QPolygonF& pol )
{
    foreach ( QPointF pt, pol )
    {
        *this->x << pt.x();
        *this->y << pt.y();
    }

    return *this;
}

Polygon& Polygon::operator<< ( const QVector<PointF>& pol )
{
    foreach ( PointF pt, pol )
    {
        *this->x << pt.x();
        *this->y << pt.y();
    }

    return *this;
}

Polygon& Polygon::operator= ( const Polygon& pol )
{
    this->x = new QVector<qreal>( *pol.getX() );
    this->y = new QVector<qreal>( *pol.getY() );

    return *this;
}
