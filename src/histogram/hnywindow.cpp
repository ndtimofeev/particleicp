#include <qwt_series_data.h>
#include <qwt_plot_renderer.h>
#include "jycomposer.h"
#include "rescaledialog.h"
#include "hnywindow.h"
#include "falgorithms.h"
#include "ui_hny.h"

HNYWindow::HNYWindow( const VectorTable& table, const QVariantMap& settings,
    QWidget* parent ) :
    QWidget( parent ),
    hist( new QwtPlotHistogram ),
    data( new QVector<double>( *table.getColumn( settings["Time"].toString() ) ) ),
    h_data( new QVector<QwtIntervalSample> )
{
    Ui::HNY ui;
    ui.setupUi( this );

    this->plot     = ui.qwtPlot;
    this->spinbox  = ui.doubleSpinBox;

    this->plot->setAxisTitle( QwtPlot::yLeft, "N, units" );
    this->plot->setAxisTitle( QwtPlot::xBottom, "t, sec" );

    this->hist->attach( this->plot );
    this->spinbox->setValue( 0 );
    this->redrawPlot();

    connect( this->spinbox, SIGNAL( editingFinished() ),
             this,          SLOT( redrawPlot() ) );

    this->contextMenu = new QMenu( this );
    this->contextMenu->addAction( tr( "&Rescale spectrum" ), this,
                                                        SLOT( rescalePlot() ) );

    this->contextMenu->addAction( tr( "&Export image" ), this,
                                                        SLOT( exportImage() ) );

    this->contextMenu->addAction( tr( "Export &data" ), this,
                                                        SLOT( exportData() ) );

    this->addActions( this->contextMenu->actions() );
}

HNYWindow::~HNYWindow()
{
    delete this->h_data;
    delete this->data;
    delete this->hist;
}

void HNYWindow::rescalePlot()
{
    RescaleDialog::rescale( this->plot, this );
    this->plot->replot();
}

void HNYWindow::contextMenuEvent( QContextMenuEvent* event )
{
    this->contextMenu->exec( event->globalPos() );
}

void HNYWindow::redrawPlot()
{
    double deltaTime = this->spinbox->value();

    if ( ! this->h_data->isEmpty() )
        this->h_data->clear();

    if ( deltaTime )
    {
        double s = deltaTime *
                    ( 1 + static_cast<int>( this->data->first() / deltaTime ) );

        int v = 0;

        for ( QVector<double>::const_iterator i = this->data->begin(),
                                              j = this->data->end();
                                              i != j;
                                              i++ )
        {
            if ( *i < s )
                v++;
            else
            {
                *(this->h_data) << QwtIntervalSample( v, s, s + deltaTime );
                s += deltaTime;
                v = 1;
            }
        }

        if ( v )
            *(this->h_data) << QwtIntervalSample( v, s, s + deltaTime );
    }

    hist->setSamples( *(this->h_data) );
    qDebug() << *this->data;
    this->plot->replot();
}

void HNYWindow::exportData()
{
    QString filename = QFileDialog::getSaveFileName(
                    this, tr("Save data as"), QString(), tr("JY files(*.jy)") );

    QFile file( filename );
    if (!file.open( QIODevice::WriteOnly | QIODevice::Text))
        return;

        QStringList list;
        list << "t" << "N";

        VectorTable tbl( list );

        foreach( QwtIntervalSample interval, *(this->h_data) )
        {
            QVector<double> vec;
            vec << interval.interval.minValue() << interval.value;
            tbl << vec;
        }

        QTextStream stream( &file );
        JYComposer( &tbl, stream );

    file.close();
}

void HNYWindow::exportImage()
{
    QString filename = QFileDialog::getSaveFileName(
        this, tr("Save image as"), QString(), tr("PNG(*.png);;JPEG(*.jpeg);;PDF(*.pdf)") );

    if ( ! filename.isEmpty() )
    {
        QwtPlotRenderer renderer;
        renderer.renderDocument( this->plot, filename, QSizeF( 300, 200 ), 85 );
    }
}

