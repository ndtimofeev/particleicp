#ifndef POLYGON_H
#define POLYGON_H

#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "pointf.h"

class Polygon
{
public:
    Polygon();
    Polygon( const QVector<qreal>* x, const QVector<qreal>* y );
    Polygon( const QVector<qreal>& x, const QVector<qreal>& y );
    Polygon( const Polygon& pol );
    virtual ~Polygon();

    const QVector<qreal>* getX() const;
    const QVector<qreal>* getY() const;
    int                   getSize() const;
    Polygon*              getInterval( qreal min, qreal max ) const;
    Polygon*              getMoreThen( qreal val ) const;

    Polygon& operator<< ( const QPointF& point );
    Polygon& operator<< ( const QPolygonF& pol );
    Polygon& operator<< ( const QVector<PointF>& pol );
    Polygon& operator= ( const Polygon& pol );

private:
    QVector<qreal>* x;
    QVector<qreal>* y;
};

#endif /* POLYGON_H */

