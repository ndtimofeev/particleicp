#include "signalswindow.h"
#include "ui_signalswindow.h"

SignalsWindow::SignalsWindow( const VectorTable& table, QWidget* parent ) :
    QWidget( parent ), table( new VectorTable( table ) ), plot( NULL )
{
    Ui::SignalsWindow ui;
    ui.setupUi( this );

    this->plot = ui.plot;
}

SignalsWindow::~SignalsWindow()
{
    delete this->table;
}

void SignalsWindow::rescalePlot()
{}

void SignalsWindow::exportData()
{}

void SignalsWindow::exportImage()
{}

