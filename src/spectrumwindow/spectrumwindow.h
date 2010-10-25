#ifndef SPECTRUMWINDOW_H
#define SPECTRUMWINDOW_H

#include <QMap>
#include <QMdiSubWindow>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "vectortable.h"

namespace Spectrum {

    enum Settings {
        UpTime,
        DownTime,
        MaxNoise,
        AverageNoise
    };

    enum Limits {
        MinTime,
        MaxTime//,
//        MaxNoise
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
    QMap<Spectrum::Settings,qreal> settings;
    QMap<QString,QVariant>         report;
};

#endif // SPECTRUMWINDOW_H
