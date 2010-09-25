#ifndef RDISPENSATIONWINDOW_H
#define RDISPENSATIONWINDOW_H

#include <QMdiSubWindow>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "polygon.h"

class RDispensationWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    RDispensationWindow( const Polygon& pol, QWidget* parent = 0 );
    virtual ~RDispensationWindow();

private:
    QwtPlot*        plot;
    QwtPlotCurve*   curve;
    Polygon*        polygon;
};


#endif /* RDISPENSATIONWINDOW_H */

