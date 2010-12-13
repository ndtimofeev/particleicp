#ifndef RESCALEDIALOG_H
#define RESCALEDIALOG_H

#include <QCheckBox>
#include <QDialog>
#include <QVariantMap>
#include <QWidget>
#include <qwt_plot.h>
#include "rangebox.h"

class RescaleDialog : public QDialog
{
    Q_OBJECT

public:
    RescaleDialog( QwtPlot* plot, QWidget* parent );
    virtual ~RescaleDialog();

    void setState();
    static void rescale( QwtPlot* plot, QWidget* parent );

private:
    QCheckBox* checkBoxX;
    QCheckBox* checkBoxY;
    RangeBox*  rangeBoxX;
    RangeBox*  rangeBoxY;
    QwtPlot*   plot;
};

#endif /* RESCALEDIALOG_H */

