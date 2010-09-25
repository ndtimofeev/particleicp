#include "dispensationwindow.h"

DispensationWindow::DispensationWindow( const Polygon& pol, QWidget* parent ) :
    QMdiSubWindow( parent )
{
    this->setWindowTitle( tr("Dispensation I window" ) );
    this->polygon = new Polygon( pol );
    this->plot = new QwtPlot( this );
    this->setWidget( this->plot );
    this->curve = new QwtPlotCurve();
    this->curve->attach( this->plot );
    this->curve->setRawData( this->polygon->getX()->data(),
                             this->polygon->getY()->data(),
                             this->polygon->getSize() );
    this->curve->setStyle( QwtPlotCurve::Sticks );
}

DispensationWindow::~DispensationWindow()
{
}
