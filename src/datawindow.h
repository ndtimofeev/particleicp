#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QtGui>
#include <qwt_plot.h>
#include "vectortable.h"

class DataWindow : public QWidget
{
    Q_OBJECT;
public:
    DataWindow( const VectorTable& table, QWidget* parent = 0 );
    DataWindow( const VectorTable* table, QWidget* parent = 0 );
    virtual ~DataWindow() = 0;

    virtual void drawCurves();

protected:
    QPointer<QwtPlot>  plot;
    const VectorTable* table;
};

#endif /* DATAWINDOW_H */

