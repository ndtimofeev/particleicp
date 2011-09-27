#include <qwt_plot_renderer.h>
#include "exportplotimage.h"

void exportPlotImage( QwtPlot* plot, QWidget* parent, const QString& name )
{
    QString filename = QFileDialog::getSaveFileName(
                            parent,
                            QObject::tr("Save image as"),
                            name,
                            QObject::tr("PNG(*.png);;JPEG(*.jpeg);;PDF(*.pdf)")
                            );

    if ( ! filename.isEmpty() )
    {
        QwtPlotRenderer renderer;
        renderer.renderDocument( plot, filename, QSizeF( 300, 200 ), 85 );
    }
}
