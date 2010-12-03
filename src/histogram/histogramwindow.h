#ifndef HISTOGRAMWINDOW_H
#define HISTOGRAMWINDOW_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QVariantMap>
#include <qwt_plot.h>
#include "vectortable.h"

class HistogramWindow : public QWidget
{
    Q_OBJECT

public:
    HistogramWindow( const VectorTable& table, const QVariantMap& settings,
            QWidget* parent = 0 );

    virtual ~HistogramWindow();

private slots:
    void histogramChanged( int index );
    void deltaEpsilonChanged( double value );

private:
    QwtPlot*        plot;
    QDoubleSpinBox* spinbox;
    QComboBox*      combobox;
    QStringList     tags;
};

#endif /* HISTOGRAMWINDOW_H */

