#include <qwt_series_data.h>
#include <qwt_plot_renderer.h>
#include "jycomposer.h"
#include "rescaledialog.h"
#include "histogramwindow.h"
#include "falgorithms.h"
#include "ui_histogram.h"

HistogramWindow::HistogramWindow( const VectorTable& table,
    const QVariantMap& settings, QWidget* parent ) :
    QWidget( parent ), hist( new QwtPlotHistogram ), e_data( NULL )
{
    Ui::Histogram ui;
    ui.setupUi( this );

    this->plot     = ui.qwtPlot;
    this->spinbox  = ui.doubleSpinBox;
    this->combobox = ui.comboBox;

    this->hist->attach( this->plot );

    foreach( QString tag, settings["Spectrums"].toStringList() )
    {
        this->combobox->addItem(tag, settings[QString("%1_DeltaEpsilon").arg(tag)]);
        this->s_data[tag] = new QVector<double>( *table.getColumn( tag ) );
        qSort( *this->s_data[tag] );
    }

    this->redrawPlot();
    this->spinbox->setValue( this->combobox->itemData(
                                this->combobox->currentIndex() ).toDouble() );

    connect( this->combobox, SIGNAL( currentIndexChanged( int ) ),
             this,           SLOT( histogramChanged( int ) ) );

    connect( this->spinbox, SIGNAL( valueChanged( double ) ),
             this,          SLOT( deltaEpsilonChanged( double ) ) );

    connect( this->spinbox, SIGNAL( editingFinished() ),
             this,          SLOT( redrawPlot() ) );

    connect( this->combobox, SIGNAL( currentIndexChanged( int ) ),
             this,           SLOT( redrawPlot() ) );

    this->contextMenu = new QMenu( this );
    this->contextMenu->addAction( tr("&Rescale spectrum"), this,
                                                           SLOT(rescalePlot()));

    this->contextMenu->addAction(tr("&Export image"), this, SLOT(exportImage()));
    this->contextMenu->addAction(tr("Export &data"), this, SLOT(exportData()));

    this->addActions( this->contextMenu->actions() );
}

HistogramWindow::~HistogramWindow()
{
    if ( this->e_data )
        delete this->e_data;
}

void HistogramWindow::rescalePlot()
{
    RescaleDialog::rescale( this->plot, this );
    this->plot->replot();
}

void HistogramWindow::contextMenuEvent( QContextMenuEvent* event )
{
    this->contextMenu->exec( event->globalPos() );
}

void HistogramWindow::redrawPlot()
{
    double deltaEpsilon =
        this->combobox->itemData( this->combobox->currentIndex() ).toDouble();

    if ( this->e_data )
        delete this->e_data;

    this->e_data = new QVector<QwtIntervalSample>;

    if ( deltaEpsilon )
    {
        const QVector<double>* vec = this->s_data[this->combobox->currentText()];
        double s = deltaEpsilon * ( 1 + (int) vec->first() / deltaEpsilon );
        int    v = 0;

        for ( QVector<double>::const_iterator i = vec->begin(), j = vec->end();
                                              i != j; i++ )
        {
            if ( *i < s )
                v++;
            else
            {
                *(this->e_data) << QwtIntervalSample( v, s, s + deltaEpsilon );
                s += deltaEpsilon;
                v = 1;
            }
        }

        if ( v )
            *(this->e_data) << QwtIntervalSample( v, s, s + deltaEpsilon );
    }

    hist->setSamples( *(this->e_data) );
    this->plot->replot();
}

void HistogramWindow::exportData()
{
    QString filename = QFileDialog::getSaveFileName(
                    this, tr("Save data as"), QString(), tr("JY files(*.jy)") );

    QFile file( filename );
    if (!file.open( QIODevice::WriteOnly | QIODevice::Text))
        return;

        QStringList list;
        list << "I" << "N";

        VectorTable tbl( list );

        foreach( QwtIntervalSample interval, *(this->e_data) )
        {
            QVector<double> vec;
            vec << interval.interval.minValue() << interval.value;
            tbl << vec;
        }

        QTextStream stream( &file );
        JYComposer( &tbl, stream );

    file.close();
}

void HistogramWindow::exportImage()
{
    QString filename = QFileDialog::getSaveFileName(
        this, tr("Save image as"), QString(), tr("PNG(*.png);;JPEG(*.jpeg);;PDF(*.pdf)") );

    if ( ! filename.isEmpty() )
    {
        QwtPlotRenderer renderer;
        renderer.renderDocument( this->plot, filename, QSizeF( 300, 200 ), 85 );
    }
}

void HistogramWindow::histogramChanged( int index )
{
    this->spinbox->setValue( this->combobox->itemData( index ).toDouble() );
}

void HistogramWindow::deltaEpsilonChanged( double value )
{
    this->combobox->setItemData( this->combobox->currentIndex(), value );
}
