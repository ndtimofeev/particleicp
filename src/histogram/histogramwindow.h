#ifndef HISTOGRAMWINDOW_H
#define HISTOGRAMWINDOW_H

#include <QtGui>
#include <qwt_plot.h>
#include <qwt_plot_histogram.h>
#include <qwt_interval.h>
#include "vectortable.h"

class HistogramWindow : public QWidget
{
    Q_OBJECT

public:
    HistogramWindow( const VectorTable& table, const QVariantMap& settings,
            QWidget* parent = 0 );

    virtual ~HistogramWindow();

protected slots:
    void redrawPlot();
    void rescalePlot();
    void exportData();
    void exportImage();
    void contextMenuEvent( QContextMenuEvent* event );

private slots:
    void histogramChanged( int index );
    void deltaEpsilonChanged( double value );

private:
    QMenu*                         contextMenu;
    QwtPlot*                       plot;
    QwtPlotHistogram*              hist;
    QDoubleSpinBox*                spinbox;
    QComboBox*                     combobox;
    QStringList                    tags;
    QMap<QString,QVector<double>*> s_data;
    QVector<QwtIntervalSample>*    e_data;

};

#endif /* HISTOGRAMWINDOW_H */

