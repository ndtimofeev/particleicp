#ifndef FILTER_H
#define FILTER_H

#include <QVector>
#include <QPolygonF>

QPolygonF filter( const QVector<double>* oX, const QVector<double>* oY, double value );

#endif /* FILTER_H */

