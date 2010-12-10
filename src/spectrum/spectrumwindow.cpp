#include <QDebug>
#include <QFileDialog>
#include <QPixmap>
#include <QMenu>
#include <QPrintDialog>
#include <QPrinter>
#include <QMdiArea>
#include <QtAlgorithms>
#include <QContextMenuEvent>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include "edittable.h"
#include "rescaledialog.h"
#include "spectrumwindow.h"
#include "histogramwindow.h"
#include "spectrumsettingswizard.h"

SpectrumWindow::SpectrumWindow( const VectorTable& table, const QString& path, const QSet<QString>& head, QWidget* parent ) :
    QwtPlot( parent ), table( new VectorTable( table ) )
{
    this->setWindowTitle( path );
    this->setAttribute(Qt::WA_DeleteOnClose);
    QwtLegend* legend = new QwtLegend;
    legend->setItemMode( QwtLegend::CheckableItem );

    QSet<QString> set = head;
    set.remove( "X" );

    this->setAxisTitle( QwtPlot::yLeft, "I, parrots" );
    this->setAxisTitle( QwtPlot::xBottom, "t, sec" );
    this->insertLegend( legend, QwtPlot::RightLegend );

    foreach( QString str, set )
    {
        QwtPlotCurve* curve = new QwtPlotCurve( str );
        curve->attach( this );
        curve->setSamples( table.getColumn( "X" )->data(), table.getColumn( str )->data(), table.getHeight() );
    }

// Очень некрасиво!
    foreach( QWidget* w, legend->legendItems() )
        ((QwtLegendItem*)w)->setChecked( true );

    connect( this, SIGNAL( legendChecked( QwtPlotItem*, bool ) ),
             this, SLOT( toggleCurve( QwtPlotItem*, bool ) ) );

    this->limits["MinTime"] = table.getColumn("X")->first();
    this->limits["MaxTime"] = table.getColumn("X")->last();

    this->settings["UpTime"] = this->limits["MaxTime"];
    this->settings["DownTime"] = this->limits["MinTime"];
    QStringList list = set.values();
    this->settings["Curves"] = list;

    QMap<QString,QVariant> map;
    foreach( QString str, set )
    {
        this->settings[QString("%1_MaxNoise").arg(str)] = 0.0;
        this->settings[QString("%1_AverageNoise").arg(str)] = 0.0;
        this->settings[QString("%1_DeltaEpsilon").arg(str)] = 0.0;
        this->settings[QString("%1_State").arg(str)] = true;
    }

    this->contextMenu = new QMenu( this );
    this->contextMenu->addAction( tr( "&Rescale spectrum" ), this,
                                                        SLOT( rescalePlot() ) );

    this->contextMenu->addAction( tr( "S&tart" ), this, SLOT( start() ) );
    this->contextMenu->addAction(
                           tr( "&Export image" ), this, SLOT( exportImage() ) );

    this->contextMenu->addAction( tr("Export &data") );

    this->addActions( this->contextMenu->actions() );
}

SpectrumWindow::~SpectrumWindow()
{
    delete this->table;
}

void SpectrumWindow::contextMenuEvent( QContextMenuEvent* event )
{
    this->contextMenu->exec( event->globalPos() );
}

void SpectrumWindow::start()
{
    QVariantMap new_settings = SpectrumSettingsWizard::getSpectrumSettings(
                                            this->settings, this->limits, this );
    if ( ! new_settings.isEmpty() )
    {
        this->settings = new_settings;

        VectorTable tbl = edt::cuttable( *this->table,
                                         this->settings["DownTime"].toDouble(),
                                         this->settings["UpTime"].toDouble() );

        tbl = edt::filtertable( tbl, this->settings );
        tbl = edt::correcttable( tbl, this->settings );

        double n = tbl.getHeight() / ( this->settings["UpTime"].toDouble() - this->settings["DownTime"].toDouble() );
        HistogramWindow* hw = new HistogramWindow( tbl, this->settings );
        hw->show();
    }
}

void SpectrumWindow::rescalePlot()
{
    RescaleDialog* rd = new RescaleDialog( this, this );
    rd->show();
}

void SpectrumWindow::toggleCurve( QwtPlotItem* curve, bool on )
{
    curve->setVisible( on );
    this->replot();
}

void SpectrumWindow::printdlg()
{
}

void SpectrumWindow::exportImage()
{
    QPixmap pixmap =   QPixmap::grabWidget( this, this->geometry() );
    QString filename = QFileDialog::getSaveFileName(
        this, tr("Save image as"), QString(), tr("PNG(*.png);;JPEG(*.jpeg)") );

    if ( ! filename.isEmpty() )
    {
        pixmap.save( filename );
    }
}
