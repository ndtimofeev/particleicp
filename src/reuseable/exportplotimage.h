#ifndef EXPORTPLOTIMAGE_H
#define EXPORTPLOTIMAGE_H

#include <QtGui>
#include <qwt_plot.h>

void exportPlotImage( QwtPlot* plot, QWidget* parent,
                                            const QString& name = QString() );

#endif /* EXPORTPLOTIMAGE_H */

