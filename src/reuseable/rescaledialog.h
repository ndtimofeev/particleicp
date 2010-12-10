#ifndef RESCALEDIALOG_H
#define RESCALEDIALOG_H

#include <QDialog>
#include <QVariantMap>
#include <QWidget>
#include <qwt_plot.h>

class RescaleDialog : public QDialog
{
    Q_OBJECT

public:
    RescaleDialog( QwtPlot* plot, QWidget* parent = 0 );
    virtual ~RescaleDialog();

    QVariantMap getState();
};

#endif /* RESCALEDIALOG_H */

