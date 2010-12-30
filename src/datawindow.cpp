#include "datawindow.h"

DataWindow::DataWindow( const VectorTable& table, QWidget* parent ) :
    QWidget( parent ), plot( NULL ), table( new VectorTable( table ) )
{}

DataWindow::DataWindow( const VectorTable* table, QWidget* parent ) :
    QWidget( parent ), plot( NULL ), table( table )
{}
