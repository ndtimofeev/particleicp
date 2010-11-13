#include <QDebug>
#include <QMenu>
#include <QPrintDialog>
#include <QPrinter>
#include <QMdiArea>
#include <QtAlgorithms>
#include <QContextMenuEvent>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include "spectrumwindow.h"
#include "spectrumsettingswizard.h"

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

// Очень некрасиво!
    foreach( QWidget* w, legend->legendItems() )
        ((QwtLegendItem*)w)->setChecked( true );

    connect( this, SIGNAL( legendChecked( QwtPlotItem*, bool ) ),
             this, SLOT( toggleCurve( QwtPlotItem*, bool ) ) );

    this->limits["MinTime"] = table.getColumn("X")->first();
    this->limits["MaxTime"] = table.getColumn("X")->last();

    this->settings["UpTime"] = this->limits["MaxTime"];
    this->settings["DownTime"] = this->limits["MinTime"];
    QStringList list = set.values();
    this->settings["Curves"] = list;

    QMap<QString,QVariant> map;
    foreach( QString str, set )
    {
        this->settings[QString("%1_MaxNoise").arg(str)] = 0.0;
        this->settings[QString("%1_AverageNoise").arg(str)] = 0.0;
        this->settings[QString("%1_DeltaEpsilon").arg(str)] = 0.0;
        this->settings[QString("%1_State").arg(str)] = true;
    }

//    this->data_all = new Polygon( table.getColumn( "X" ), table.getColumn( "Al1" ) );
//    this->data = this->data_all;

//    this->dispensationwindow = NULL;
//    this->reportwindow = NULL;
}

SpectrumWindow::~SpectrumWindow()
{
}

void SpectrumWindow::contextMenuEvent( QContextMenuEvent* event )
{
    QMenu* contextMenu = new QMenu( this );
//    contextMenu->addAction( tr( "P&rint" ), this, SLOT( printdlg() ) );
    contextMenu->addAction( tr( "S&tart" ), this, SLOT( start() ) );
    contextMenu->exec( event->globalPos() );
}

void SpectrumWindow::start()
{
    this->settings = SpectrumSettingsWizard::getSpectrumSettings( this->settings, this->limits, this );
    qDebug() << this->settings["UpTime"] << this->settings["DownTime"];
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
