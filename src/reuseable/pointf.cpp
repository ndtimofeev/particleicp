#include "pointf.h"

PointF::PointF() : QPointF()
{
}

PointF::PointF( qreal x, qreal y ) : QPointF( x, y )
{
}

PointF::~PointF()
{
}

bool PointF::operator< ( const PointF& pt ) const
{
    return this->x() < pt.x();
}
