#include "datawindow.h"

DataWindow::DataWindow( const VectorTable& table, QWidget* parent ) :
    QWidget( parent ), plot( NULL ), table( new VectorTable( table ) )
{}

DataWindow::DataWindow( const VectorTable* table, QWidget* parent ) :
    QWidget( parent ), plot( NULL ), table( table )
{}

void DataWindow::drawCurves()
{
    if ( this->plot )
    {
        foreach( QString str, fp::tail( this->table->tags() ) )
        {
            QwtPlotCurve* curve = new QwtPlotCurve( str );
            curve->attach( this->plot );
            curve->setSamples(
                    this->table->getColumn( ) );
        }
    }
}


