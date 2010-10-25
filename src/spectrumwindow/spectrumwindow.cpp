#include <QDebug>
#include <QMenu>
#include <QPrintDialog>
#include <QPrinter>
#include <QMdiArea>
#include <QtAlgorithms>
#include <QContextMenuEvent>
#include "spectrumwindow.h"
#include <qwt_legend.h>
#include <qwt_legend_item.h>

SpectrumWindow::SpectrumWindow( const VectorTable& table, const QString& path, const QSet<QString>& head, QWidget* parent ) :
    QwtPlot( parent )
{
    this->setWindowTitle( path );
    this->setAttribute(Qt::WA_DeleteOnClose);
    QwtLegend* legend = new QwtLegend;
    legend->setItemMode( QwtLegend::CheckableItem );

    QSet<QString> set = head;
    set.remove( "X" );

    this->setAxisTitle( QwtPlot::yLeft, "I, parrots" );
    this->setAxisTitle( QwtPlot::xBottom, "t, sec" );
    this->insertLegend( legend, QwtPlot::RightLegend );

    foreach( QString str, set )
    {

        QwtPlotCurve* curve = new QwtPlotCurve( str );
        curve->attach( this );
        curve->setSamples( table.getColumn( "X" )->data(), table.getColumn( str )->data(), table.getHeight() );
    }

    foreach( QWidget* w, legend->legendItems() )
        ((QwtLegendItem*)w)->setChecked( true );

    connect( this, SIGNAL( legendChecked( QwtPlotItem*, bool ) ),
             this, SLOT( toggleCurve( QwtPlotItem*, bool ) ) );


//    this->data_all = new Polygon( table.getColumn( "X" ), table.getColumn( "Al1" ) );
//    this->data = this->data_all;
//  this->settings[UpTime] = data->getX()->last();
//  this->settings[DownTime] = data->getX()->first();
//  this->settings[MaxTime] = data->getX()->last();
//  this->settings[MinTime] = data->getX()->first();
//  this->settings[MaxNoise] = 0.0;
//  this->settings[AverageNoise] = 0.0;

//    this->curve = new QwtPlotCurve();
//    this->curve->attach( this->plot );
//    this->curve->setRawData( data->getX()->data(),
//                             data->getY()->data(),
//                             data->getSize() );

//    this->dispensationwindow = NULL;
//    this->reportwindow = NULL;
}

SpectrumWindow::~SpectrumWindow()
{
}

void SpectrumWindow::contextMenuEvent( QContextMenuEvent* event )
{
    QMenu* contextMenu = new QMenu( this );
    contextMenu->addAction( tr( "P&rint" ), this, SLOT( printdlg() ) );
    contextMenu->addAction( tr( "&Settings" ), this, SLOT( setSettings() ) ) ;
    contextMenu->addAction( tr( "S&tart" ), this, SLOT( start() ) );
    contextMenu->exec( event->globalPos() );
}

void SpectrumWindow::setSettings()
{
//    this->settings = SpectrumSettingsDialog::getSettings( this->settings, this );
//    this->data = this->data_all->getInterval( this->settings[DownTime],
//                                              this->settings[UpTime] );

//    this->curve->setRawData( this->data->getX()->data(),
//                             this->data->getY()->data(),
//                             this->data->getSize() );

//    this->plot->replot();
}

void SpectrumWindow::start()
{
//    Polygon* sig = this->data->getMoreThen( this->settings[MaxNoise] );
//    this->report["Frequency"] = sig->getSize() /
//                        ( this->settings[UpTime] - this->settings[DownTime] );

  //  QVector<PointF> pol;
//    foreach( qreal val, *sig->getY() )
//    {
//        val -= this->settings[AverageNoise];
//        this->report["SigmaI"] = this->report["SigmaI"].toDouble() + val;
//        bool check = false;
//        for ( int  i = 0; i < pol.size(); i++ )
//        {
//            if ( qAbs( val - pol.at(i).x() ) < 0.02 * val )
//            {
//                check = true;
//                pol[i].ry()++;
//            }
//        }
//        if ( check == false )
//            pol << PointF( val, 1.0 );
//    }
//    qSort( pol );
//    Polygon graph;
//    graph << pol;

//    if ( this->dispensationwindow != NULL )
//        delete this->dispensationwindow;

//    this->dispensationwindow = new DispensationWindow( graph, this );
//    this->mdiArea()->addSubWindow( this->dispensationwindow );
//    this->dispensationwindow->show();//Maximized();

//    if ( this->reportwindow != NULL )
//        delete this->reportwindow;

//    this->reportwindow = new ReportWindow( this->report, this );
//    this->mdiArea()->addSubWindow( this->reportwindow );
//    this->reportwindow->show();//Maximized();
}

void SpectrumWindow::toggleCurve( QwtPlotItem* curve, bool on )
{
    curve->setVisible( on );
    this->replot();
}

void SpectrumWindow::printdlg()
{
//    QPrinter printer;

//    QPrintDialog *dialog = new QPrintDialog(&printer, this);
//    dialog->setWindowTitle(tr("Print Document"));
//    if (dialog->exec() != QDialog::Accepted)
//        return;
//    this->print( printer );
}
