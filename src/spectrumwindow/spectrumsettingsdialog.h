#ifndef SPECTRUMSETTINGSDIALOG_H
#define SPECTRUMSETTINGSDIALOG_H

#include <QDialog>
#include <QMap>
#include "spectrumwindow.h"

class SpectrumSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SpectrumSettingsDialog( const QMap<Settings,qreal>& map,
                            SpectrumWindow* ptr );
    virtual ~SpectrumSettingsDialog();

    const QMap<Settings,qreal>& getReturn() const;

    static QMap<Settings,qreal> getSettings( const QMap<Settings,qreal>& map,
                                             SpectrumWindow* ptr );

private:
    QMap<Settings,qreal> settings;

private slots:
    void set_max_time( int val );
    void set_min_time( int val );
    void set_max_noise( double val );
    void set_average_noise( double val );
};

#endif /* SPECTRUMSETTINGSDIALOG_H */
