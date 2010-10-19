#include <QSpinBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include "spectrumwindow.h"
#include "spectrumsettingsdialog.h"
#include "ui_spectrumsettingsdialog.h"

SpectrumSettingsDialog::SpectrumSettingsDialog( const QMap<Spectrum::Settings,qreal>& settings,
                                                const QMap<Spectrum::Limits,qreal>&   limits,
                                                SpectrumWindow* parent ) :
    QDialog( parent ),
    settings( settings ),
    limits( limits )
{
    Ui::Dialog ui;
    ui.setupUi( this );

    ui.maxNoiseDoubleSpinBox->setValue( this->settings[Spectrum::MaxNoise] );

    ui.averageNoiseDoubleSpinBox->setValue( this->settings[Spectrum::AverageNoise] );

    ui.upTimeSpinBox->setRange( this->limits[Spectrum::MinTime], this->limits[Spectrum::MaxTime] );
    ui.upTimeSpinBox->setValue( this->settings[Spectrum::UpTime] );

    ui.downTimeSpinBox->setRange( this->limits[Spectrum::MinTime], this->limits[Spectrum::MaxTime] );
    ui.downTimeSpinBox->setValue( this->settings[Spectrum::DownTime] );
}

SpectrumSettingsDialog::~SpectrumSettingsDialog()
{
}

const QMap<Spectrum::Settings,qreal>& SpectrumSettingsDialog::getReturn() const
{
    return this->settings;
}

QMap<Spectrum::Settings,qreal>
SpectrumSettingsDialog::getSettings( const QMap<Spectrum::Settings,qreal>& settings,
                                     const QMap<Spectrum::Limits,qreal>&   limits,
                                     SpectrumWindow* ptr )
{
    QMap<Spectrum::Settings,qreal> result;
    SpectrumSettingsDialog dlg( settings, limits, ptr );

    if ( dlg.exec() == QDialog::Accepted )
        result = dlg.getReturn();
    else
        result = dlg.getReturn();

    return settings;
}

void SpectrumSettingsDialog::set_up_time( int val )
{
    this->settings[Spectrum::UpTime] = val;
}

void SpectrumSettingsDialog::set_down_time( int val )
{
    this->settings[Spectrum::DownTime] = val;
}

void SpectrumSettingsDialog::set_max_noise( double val )
{
    this->settings[Spectrum::MaxNoise] = val;
}

void SpectrumSettingsDialog::set_average_noise( double val )
{
    this->settings[Spectrum::AverageNoise] = val;
}

