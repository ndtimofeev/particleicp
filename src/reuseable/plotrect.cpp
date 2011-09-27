#include <qwt_plot_item.h>
#include "plotrect.h"

QRectF plotRect( QwtPlot* plot )
{
    QRectF rect;
    foreach( QwtPlotItem* item, plot->itemList() )
        rect |= item->boundingRect();

    return rect;
}
