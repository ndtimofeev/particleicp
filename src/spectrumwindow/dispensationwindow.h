#ifndef DISPENSATIONWINDOW_H
#define DISPENSATIONWINDOW_H

#include <QMdiSubWindow>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "polygon.h"

class DispensationWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    DispensationWindow( const Polygon& pol, QWidget* parent = 0 );
    virtual ~DispensationWindow();

private:
    QwtPlot*        plot;
    QwtPlotCurve*   curve;
    Polygon*        polygon;
};


#endif /* DISPENSATIONWINDOW_H */

