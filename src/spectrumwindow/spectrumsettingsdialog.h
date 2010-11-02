#ifndef SPECTRUMSETTINGSDIALOG_H
#define SPECTRUMSETTINGSDIALOG_H

#include <QDialog>
#include <QVariant>
#include <QMap>
#include "spectrumwindow.h"

class SpectrumSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SpectrumSettingsDialog( const QMap<Spectrum::Settings,QVariant>& settings,
                            const QMap<Spectrum::Limits,QVariant>&   limits,
                            SpectrumWindow* ptr );

    virtual ~SpectrumSettingsDialog();

    const  QMap<Spectrum::Settings,QVariant>& getReturn() const;

    static QMap<Spectrum::Settings,QVariant>
    getSettings( const QMap<Spectrum::Settings,QVariant>& settings,
                 const QMap<Spectrum::Limits,QVariant>&   limits,
                 SpectrumWindow* ptr );

private:
    QMap<Spectrum::Settings,QVariant> settings;
    QMap<Spectrum::Limits,QVariant>   limits;

private slots:
    void set_up_time( int val );
    void set_down_time( int val );
    void set_max_noise( double val );
    void set_average_noise( double val );
    void set_histogram_step( double val );
};

#endif /* SPECTRUMSETTINGSDIALOG_H */
