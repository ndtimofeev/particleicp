#ifndef SPECTRUMWINDOW_H
#define SPECTRUMWINDOW_H

#include <QMap>
#include <QMenu>
#include <QMdiSubWindow>
#include <QVector>
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "vectortable.h"

class SpectrumWindow : public QWidget
{
    Q_OBJECT

public:
    SpectrumWindow( const VectorTable& table, QWidget* parent = 0 );
    virtual ~SpectrumWindow();

    static QVariantMap getSettings( const VectorTable& table );
    static QVariantMap getLimits( const VectorTable& table );

protected:
    void contextMenuEvent( QContextMenuEvent* event );

private slots:
    void start();
    void printdlg();
    void exportImage();
    void exportData();
    void rescalePlot();
    void toggleCurve( QwtPlotItem* curve, bool on );

private:
    QVariantMap  settings;
    QVariantMap  limits;
    QVariantMap  report;
    QMenu*       contextMenu;
    VectorTable* table;
    QwtPlot*     plot;
};

#endif // SPECTRUMWINDOW_H
