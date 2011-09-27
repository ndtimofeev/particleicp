#include <QDebug>
#include <QRectF>
#include <qwt_plot_item.h>
#include "rescaledialog.h"
#include "plotrect.h"
#include "ui_rescaledialog.h"

RescaleDialog::RescaleDialog( QwtPlot* plot, QWidget* parent ) :
    QDialog( parent ), plot( plot )
{
    Ui::RescaleDialog ui;
    ui.setupUi( this );

    this->checkBoxX = ui.checkBoxX;
    this->checkBoxY = ui.checkBoxY;
    this->rangeBoxX = ui.rangeBoxX;
    this->rangeBoxY = ui.rangeBoxY;

    connect( this->checkBoxY, SIGNAL( toggled( bool ) ),
             this->rangeBoxY, SLOT( setDisabled( bool ) ) );

    connect( this->checkBoxX, SIGNAL( toggled( bool ) ),
             this->rangeBoxX, SLOT( setDisabled( bool ) ) );

    this->checkBoxX->setChecked( plot->axisAutoScale( QwtPlot::xBottom ) );
    this->checkBoxY->setChecked( plot->axisAutoScale( QwtPlot::yLeft ) );

    QRectF rect = plotRect( plot );

    this->rangeBoxX->setRange( rect.left(), rect.right() );

    this->rangeBoxX->setMinValue( plot->canvasMap( QwtPlot::xBottom ).s1() );
    this->rangeBoxX->setMaxValue( plot->canvasMap( QwtPlot::xBottom ).s2() );

    this->rangeBoxY->setRange( rect.top(), rect.bottom() );

    this->rangeBoxY->setMinValue( plot->canvasMap( QwtPlot::yLeft ).s1() );
    this->rangeBoxY->setMaxValue( plot->canvasMap( QwtPlot::yLeft ).s2() );
}

RescaleDialog::~RescaleDialog()
{
}

void RescaleDialog::setState()
{
    if ( this->checkBoxX->isChecked() )
        this->plot->setAxisAutoScale( QwtPlot::xBottom );
    else
        this->plot->setAxisScale( QwtPlot::xBottom, this->rangeBoxX->minValue(),
                                                this->rangeBoxX->maxValue() );

    if ( this->checkBoxY->isChecked() )
        this->plot->setAxisAutoScale( QwtPlot::yLeft );
    else
        this->plot->setAxisScale( QwtPlot::yLeft, this->rangeBoxY->minValue(),
                                                this->rangeBoxY->maxValue() );
}

void RescaleDialog::rescale( QwtPlot* plot, QWidget* parent )
{
    RescaleDialog dlg( plot, parent );

    if ( dlg.exec() == QDialog::Accepted )
        dlg.setState();
}
