#ifndef SPECTRUMSETTINGSDIALOG_H
#define SPECTRUMSETTINGSDIALOG_H

#include <QDialog>
#include <QMap>
#include "spectrumwindow.h"

class SpectrumSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SpectrumSettingsDialog( const QMap<Spectrum::Settings,qreal>& settings,
                            const QMap<Spectrum::Limits,qreal>&   limits,
                            SpectrumWindow* ptr );

    virtual ~SpectrumSettingsDialog();

    const  QMap<Spectrum::Settings,qreal>& getReturn() const;

    static QMap<Spectrum::Settings,qreal>
    getSettings( const QMap<Spectrum::Settings,qreal>& settings,
                 const QMap<Spectrum::Limits,qreal>&   limits,
                 SpectrumWindow* ptr );

private:
    QMap<Spectrum::Settings,qreal> settings;
    QMap<Spectrum::Limits,qreal>   limits;

private slots:
    void set_up_time( int val );
    void set_down_time( int val );
    void set_max_noise( double val );
    void set_average_noise( double val );
};

#endif /* SPECTRUMSETTINGSDIALOG_H */
