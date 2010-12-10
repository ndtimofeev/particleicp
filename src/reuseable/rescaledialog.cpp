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

    ui.rangeBoxX->setEnabled( plot->axisAutoScale( QwtPlot::xBottom ) );
}

RescaleDialog::~RescaleDialog()
{
}

QVariantMap RescaleDialog::getState()
{
    return;
}
