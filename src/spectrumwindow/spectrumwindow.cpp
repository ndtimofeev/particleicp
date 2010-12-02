#include <QDebug>
#include <QFileDialog>
#include <QPixmap>
#include <QMenu>
#include <QPrintDialog>
#include <QPrinter>
#include <QMdiArea>
#include <QtAlgorithms>
#include <QContextMenuEvent>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include "cuttable.h"
#include "spectrumwindow.h"
#include "spectrumsettingswizard.h"

SpectrumWindow::SpectrumWindow( const VectorTable& table, const QString& path, const QSet<QString>& head, QWidget* parent ) :
    QwtPlot( parent ), table( new VectorTable( table ) )
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

    this->contextMenu = new QMenu( this );
    this->contextMenu->addAction( tr( "S&tart" ), this, SLOT( start() ) );
    this->contextMenu->addAction(
                        tr( "&Export image" ), this, SLOT( exportImage() ) );

    this->addActions( this->contextMenu->actions() );
}

SpectrumWindow::~SpectrumWindow()
{
    delete this->table;
}

void SpectrumWindow::contextMenuEvent( QContextMenuEvent* event )
{
    this->contextMenu->exec( event->globalPos() );
}

void SpectrumWindow::start()
{
    this->settings = SpectrumSettingsWizard::getSpectrumSettings(
                                        this->settings, this->limits, this );
    qDebug() << this->settings;

    VectorTable tbl = cuttable( *this->table,
                                this->settings["DownTime"].toDouble(),
                                this->settings["UpTime"].toDouble() );

    SpectrumWindow* sw = new SpectrumWindow( tbl, QString("хуй"), tbl.getTags().toSet() );
    sw->show();
}

void SpectrumWindow::toggleCurve( QwtPlotItem* curve, bool on )
{
    curve->setVisible( on );
    this->replot();
}

void SpectrumWindow::printdlg()
{
}

void SpectrumWindow::exportImage()
{
    QPixmap pixmap =   QPixmap::grabWidget( this, this->geometry() );
    QString filename = QFileDialog::getSaveFileName(
        this, tr("Save image as"), QString(), tr("PNG(*.png);;JPEG(*.jpeg)") );

    if ( ! filename.isEmpty() )
    {
        pixmap.save( filename );
    }
}
