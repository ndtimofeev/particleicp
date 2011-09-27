#ifndef HNYWINDOW_H
#define HNYWINDOW_H

#include <QtGui>
#include <qwt_plot.h>
#include <qwt_plot_histogram.h>
#include <qwt_interval.h>
#include "vectortable.h"

class HNYWindow : public QWidget
{
    Q_OBJECT

public:
    HNYWindow( const VectorTable& table, const QVariantMap& settings,
            QWidget* parent = 0 );

    virtual ~HNYWindow();

protected slots:
    void redrawPlot();
    void rescalePlot();
    void exportData();
    void exportImage();
    void contextMenuEvent( QContextMenuEvent* event );

private:
    QMenu*                      contextMenu;
    QwtPlot*                    plot;
    QwtPlotHistogram*           hist;
    QDoubleSpinBox*             spinbox;
    QStringList                 tags;
    const QVector<double>*      data;
    QVector<QwtIntervalSample>* h_data;
};

#endif /* HNYWINDOW_H */

