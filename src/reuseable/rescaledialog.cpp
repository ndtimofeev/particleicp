#include <QDebug>
#include <qwt_plot_dict.h>
#include "rescaledialog.h"
#include "ui_rescaledialog.h"

RescaleDialog::RescaleDialog( QwtPlot* plot, QWidget* parent ) :
    QDialog( parent )
{
    Ui::RescaleDialog ui;
    ui.setupUi( this );
    ui.rangeBoxY->setEnabled( false );
    ui.rangeBoxX->setEnabled( false );

    connect( ui.checkBoxY, SIGNAL( toggled( bool ) ),
             ui.rangeBoxY, SLOT( setDisabled( bool ) ) );

    connect( ui.checkBoxX, SIGNAL( toggled( bool ) ),
             ui.rangeBoxX, SLOT( setDisabled( bool ) ) );

    ui.checkBoxX->setChecked( plot->axisAutoScale( QwtPlot::xBottom ) );
    ui.checkBoxY->setChecked( plot->axisAutoScale( QwtPlot::yLeft ) );

    ui.rangeBoxX->setRange( plot->canvasMap( QwtPlot::xBottom ).s1(),
                                    plot->canvasMap( QwtPlot::xBottom ).s2() );

    ui.rangeBoxX->setMinValue( plot->canvasMap( QwtPlot::xBottom ).s1() );
    ui.rangeBoxX->setMaxValue( plot->canvasMap( QwtPlot::xBottom ).s2() );

    ui.rangeBoxY->setRange( plot->canvasMap( QwtPlot::yLeft ).s1(),
                                    plot->canvasMap( QwtPlot::yLeft ).s2() );

    ui.rangeBoxY->setMinValue( plot->canvasMap( QwtPlot::yLeft ).s1() );
    ui.rangeBoxY->setMaxValue( plot->canvasMap( QwtPlot::yLeft ).s2() );
}

RescaleDialog::~RescaleDialog()
{
}

QVariantMap RescaleDialog::getState()
{
}
