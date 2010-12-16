#ifndef SIGNALSWINDOW_H
#define SIGNALSWINDOW_H

#include <QtGui>
#include <qwt_plot.h>
#include "vectortable.h"

class SignalsWindow : public QWidget
{
    Q_OBJECT;
public:
    SignalsWindow( const VectorTable& table, QWidget* parent = NULL );
    virtual ~SignalsWindow();

protected slots:
    void rescalePlot();
    void exportData();
    void exportImage();

private:
    VectorTable* table;
    QwtPlot*     plot;
};

#endif /* SIGNALSWINDOW_H */

