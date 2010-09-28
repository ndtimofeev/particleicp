#ifndef SPECTRUMWINDOW_H
#define SPECTRUMWINDOW_H

#include <QMap>
#include <QMdiSubWindow>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "jyparser.h"
#include "polygon.h"
#include "dispensationwindow.h"
#include "reportwindow.h"

enum Settings {
    MaxTime,
    UpTime,
    MinTime,
    DownTime,
    MaxNoise,
    AverageNoise
};

class SpectrumWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    SpectrumWindow( const QString& path, const JYTable& table, QWidget* parent = 0 );
    virtual ~SpectrumWindow();

protected:
    void contextMenuEvent( QContextMenuEvent* event );

private slots:
    void setSettings();
    void start();

private:
    QMap<Settings,qreal>   settings;
    QMap<QString,QVariant> report;
    Polygon*               data_all;
    Polygon*               data;
    QwtPlot*               plot;
    QwtPlotCurve*          curve;
    DispensationWindow*    dispensationwindow;
    ReportWindow*          reportwindow;
};

#endif // SPECTRUMWINDOW_H
