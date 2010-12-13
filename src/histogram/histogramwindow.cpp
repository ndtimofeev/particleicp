#include <QDebug>
#include <QString>
#include <qwt_plot_curve.h>
#include <qwt_interval.h>
#include <qwt_series_data.h>
#include "rescaledialog.h"
#include "histogramwindow.h"
#include "falgorithms.h"
#include "ui_histogram.h"

HistogramWindow::HistogramWindow( const VectorTable& table,
    const QVariantMap& settings, QWidget* parent ) : QWidget( parent ), hist( NULL )
{
    Ui::Histogram ui;
    ui.setupUi( this );

    this->plot     = ui.qwtPlot;
    this->spinbox  = ui.doubleSpinBox;
    this->combobox = ui.comboBox;

    this->hist = new QwtPlotHistogram;
    this->hist->attach( this->plot );

    foreach( QString tag, fp::tail( table.getTags() ) )
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

    this->contextMenu->addAction( tr("&Export image") );
    this->contextMenu->addAction( tr("Export &data") );

    this->addActions( this->contextMenu->actions() );
}

HistogramWindow::~HistogramWindow()
{
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

    QVector<QwtIntervalSample> data;

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
                data << QwtIntervalSample( v, s, s + deltaEpsilon );
                s += deltaEpsilon;
                v = 1;
            }
        }

        if ( v )
            data << QwtIntervalSample( v, s, s + deltaEpsilon );
    }

    hist->setSamples( data );
    this->plot->replot();
}

void HistogramWindow::histogramChanged( int index )
{
    this->spinbox->setValue( this->combobox->itemData( index ).toDouble() );
}

void HistogramWindow::deltaEpsilonChanged( double value )
{
    this->combobox->setItemData( this->combobox->currentIndex(), value );
}
