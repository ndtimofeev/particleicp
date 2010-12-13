#ifndef SPECTRUMWINDOW_H
#define SPECTRUMWINDOW_H

#include <QMap>
#include <QMenu>
#include <QMdiSubWindow>
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "vectortable.h"

class SpectrumWindow : public QwtPlot
{
    Q_OBJECT

public:
    SpectrumWindow( const VectorTable& table, const QString& path, const QSet<QString>& head, QWidget* parent = 0 );
    virtual ~SpectrumWindow();

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
    QMap<QString,QVariant> settings;
    QMap<QString,QVariant> limits;
    QMap<QString,QVariant> report;
    QMenu*                 contextMenu;
    VectorTable*           table;
};

#endif // SPECTRUMWINDOW_H
