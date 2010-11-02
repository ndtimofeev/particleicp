#ifndef SPECTRUMWINDOW_H
#define SPECTRUMWINDOW_H

#include <QMap>
#include <QMdiSubWindow>
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "vectortable.h"

namespace Spectrum {

    enum Settings {
        DownTime,
        UpTime,
        MaxNoise,
        AverageNoise,
        HistogramStep,
        CurveSettings
    };

    enum Limits {
        MinTime,
        MaxTime//,
//        MaxNoise
    };
}

namespace Curve {

    enum Settings {
        MaxNoise,
        AverageNoise
    };

}

class SpectrumWindow : public QwtPlot
{
    Q_OBJECT

public:
    SpectrumWindow( const VectorTable& table, const QString& path, const QSet<QString>& head, QWidget* parent = 0 );
    virtual ~SpectrumWindow();

protected:
    void contextMenuEvent( QContextMenuEvent* event );

private slots:
    void setSettings();
    void start();
    void printdlg();
    void toggleCurve( QwtPlotItem* curve, bool on );

private:
    QMap<Spectrum::Settings,QVariant> settings;
    QMap<Spectrum::Limits,QVariant>   limits;
    QMap<QString,QVariant>            report;
};

#endif // SPECTRUMWINDOW_H
