#include <QtAlgorithms>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include <qwt_plot_renderer.h>
#include "falgorithms.h"
#include "exportplotimage.h"
#include "ui_spectrumwindow.h"
#include "jycomposer.h"
#include "edittable.h"
#include "rescaledialog.h"
#include "spectrumwindow.h"
#include "histogramwindow.h"
#include "hnywindow.h"
#include "spectrumsettingswizard.h"

SpectrumWindow::SpectrumWindow( const VectorTable& table, QWidget* parent ) :
    QWidget( parent ),
    settings( SpectrumWindow::getSettings( table ) ),
    limits( SpectrumWindow::getLimits( table ) ),
    contextMenu( NULL ),
    table( new VectorTable( table ) ),
    plot( NULL )
{
    Ui::SpectrumWindow ui;
    ui.setupUi( this );

    this->plot = ui.plot;

    this->plot->setAxisTitle( QwtPlot::yLeft, "I, parrots" );
    this->plot->setAxisTitle( QwtPlot::xBottom, "t, sec" );

    QwtLegend* legend = new QwtLegend( this->plot );
    legend->setItemMode( QwtLegend::CheckableItem );
    this->plot->insertLegend( legend );

    foreach( QString str, this->settings["Spectrums"].toStringList() )
    {
        QwtPlotCurve* curve = new QwtPlotCurve( str );
        curve->attach( this->plot );
        curve->setSamples(
                table.getColumn( this->settings["Time"].toString() )->data(),
                table.getColumn( str )->data(),
                table.getHeight()
                );
    }

    this->contextMenu = new QMenu( this );
    this->contextMenu->addAction( tr( "&Rescale spectrum" ), this,
                                                        SLOT( rescalePlot() ) );

    this->contextMenu->addAction( tr( "S&tart" ), this, SLOT( start() ) );
    this->contextMenu->addAction(
                           tr( "&Export image" ), this, SLOT( exportImage() ) );

    this->contextMenu->addAction( tr("Export &data"), this, SLOT( exportData() ) );

    this->addActions( this->contextMenu->actions() );

    connect( this->plot, SIGNAL( legendChecked( QwtPlotItem*, bool ) ),
             this,       SLOT( toggleCurve( QwtPlotItem*, bool ) ) );
}

SpectrumWindow::~SpectrumWindow()
{
    delete this->table;
}

QVariantMap SpectrumWindow::getSettings( const VectorTable& table )
{
    QVariantMap settings;

    settings["Time"]      = table.getTags().first();
    settings["Spectrums"] = fp::tail( table.getTags() );
    settings["UpTime"]    = table.getColumn(
                                        settings["Time"].toString() )->last();

    settings["DownTime"]  = table.getColumn(
                                        settings["Time"].toString() )->first();

    foreach( QString str, settings["Spectrums"].toStringList() )
    {
        settings[QString("%1_MaxNoise").arg(str)] = 0.0;
        settings[QString("%1_AverageNoise").arg(str)] = 0.0;
        settings[QString("%1_DeltaEpsilon").arg(str)] = 0.0;
        settings[QString("%1_State").arg(str)] = true;
    }

    return settings;
}

QVariantMap SpectrumWindow::getLimits( const VectorTable& table )
{
    QVariantMap limits;

    limits["MaxTime"] = table.getColumn( table.getTags().first() )->last();
    limits["MinTime"] = table.getColumn( table.getTags().first() )->first();

    return limits;
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

        qDebug() << this->settings;

        VectorTable tbl = edt::cuttable( *this->table,
                                         this->settings["DownTime"].toDouble(),
                                         this->settings["UpTime"].toDouble() );

        tbl = edt::filtertable( tbl, this->settings );
        tbl = edt::correcttable( tbl, this->settings );

        double n = tbl.getHeight() / ( this->settings["UpTime"].toDouble()
                                    - this->settings["DownTime"].toDouble() );

        HistogramWindow* hw = new HistogramWindow( tbl, this->settings );
        HNYWindow* hnyw     = new HNYWindow( tbl, this->settings );

        QMdiArea* area =
                    static_cast<QMdiArea*>( this->parent()->parent()->parent() );

        area->addSubWindow( hw )->showMaximized();
        area->addSubWindow( hnyw )->showMaximized();
    }
}

void SpectrumWindow::rescalePlot()
{
    RescaleDialog::rescale( this->plot, this );
    this->plot->replot();
}

void SpectrumWindow::toggleCurve( QwtPlotItem* curve, bool on )
{
    on = on ? false : true;
    curve->setVisible( on );
    this->settings[QString("%1_State").arg(curve->title().text())] = on;
    this->plot->replot();
}

void SpectrumWindow::printdlg()
{
}

void SpectrumWindow::exportImage()
{
    exportPlotImage( this->plot, this );
}

void SpectrumWindow::exportData()
{
    QString filename = QFileDialog::getSaveFileName(
                    this, tr("Save data as"), QString(), tr("JY files(*.jy)") );

    QFile file( filename );
    if (!file.open( QIODevice::WriteOnly | QIODevice::Text))
        return;

        VectorTable tbl = edt::cuttable(
                                *this->table,
                                this->plot->canvasMap( QwtPlot::xBottom ).s1(),
                                this->plot->canvasMap( QwtPlot::xBottom ).s2()
                                );

        QTextStream stream( &file );

        QStringList columns( this->settings["Time"].toString() );

        foreach( QString str, this->settings["Spectrums"].toStringList() )
            if ( this->settings[QString("%1_State").arg(str)].toBool() )
                columns += str;

        JYComposer( &tbl, stream, columns );

    file.close();
}
