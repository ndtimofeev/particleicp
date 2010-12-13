#ifndef HISTOGRAMWINDOW_H
#define HISTOGRAMWINDOW_H

#include <QWidget>
#include <QContextMenuEvent>
#include <QVector>
#include <QMap>
#include <QMenu>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QVariantMap>
#include <qwt_plot.h>
#include <qwt_plot_histogram.h>
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

};

#endif /* HISTOGRAMWINDOW_H */

