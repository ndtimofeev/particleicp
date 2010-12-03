#include <QString>
#include "histogramwindow.h"
#include "falgorithms.h"
#include "ui_histogram.h"

HistogramWindow::HistogramWindow( const VectorTable& table,
    const QVariantMap& settings, QWidget* parent ) : QWidget( parent )
{
    Ui::Histogram ui;
    ui.setupUi( this );

    this->plot     = ui.qwtPlot;
    this->spinbox  = ui.doubleSpinBox;
    this->combobox = ui.comboBox;

    foreach( QString tag, fp::tail( table.getTags() ) )
        this->combobox->addItem(tag, settings[QString("%1_DeltaEpsilon").arg(tag)]);

    connect( this->combobox, SIGNAL( currentIndexChanged( int ) ),
             this,           SLOT( histogramChanged( int ) ) );

    connect( this->spinbox, SIGNAL( valueChanged( double ) ),
             this,          SLOT( deltaEpsilonChanged( double ) ) );
}

HistogramWindow::~HistogramWindow()
{
}

void HistogramWindow::histogramChanged( int index )
{
    this->spinbox->setValue( this->combobox->itemData( index ).toDouble() );
}

void HistogramWindow::deltaEpsilonChanged( double value )
{
    this->combobox->setItemData( this->combobox->currentIndex(), value );
}
