#ifndef POINTF_H
#define POINTF_H

#include <QPointF>

class PointF : public QPointF
{
public:
    PointF();
    PointF( qreal x, qreal y );
    virtual ~PointF();

    bool operator< ( const PointF& pt ) const;
};

#endif /* POINTF_H */

