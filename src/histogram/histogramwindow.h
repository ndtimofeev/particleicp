#ifndef HISTOGRAMWINDOW_H
#define HISTOGRAMWINDOW_H

#include <QWidget>
#include <QVector>
#include <QMap>
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

private slots:
    void histogramChanged( int index );
    void deltaEpsilonChanged( double value );

private:
    QwtPlot*                       plot;
    QwtPlotHistogram*              hist;
    QDoubleSpinBox*                spinbox;
    QComboBox*                     combobox;
    QStringList                    tags;
    QMap<QString,QVector<double>*> s_data;

};

#endif /* HISTOGRAMWINDOW_H */

