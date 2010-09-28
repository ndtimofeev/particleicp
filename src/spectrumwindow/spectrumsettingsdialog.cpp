#include <QSpinBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include "spectrumsettingsdialog.h"
#include "ui_spectrumsettingsdialog.h"

SpectrumSettingsDialog::SpectrumSettingsDialog( const QMap<Settings,qreal>& map,
                                                SpectrumWindow* parent ) :
    QDialog( parent )
{
    this->settings = map;

    Ui::Dialog ui;
    ui.setupUi( this );

    ui.maxNoiseDoubleSpinBox->setValue( this->settings[MaxNoise] );

    ui.averageNoiseDoubleSpinBox->setValue( this->settings[AverageNoise] );

    ui.upTimeSpinBox->setRange( this->settings[MinTime], this->settings[MaxTime] );
    ui.upTimeSpinBox->setValue( this->settings[UpTime] );

    ui.downTimeSpinBox->setRange( this->settings[MinTime], this->settings[MaxTime] );
    ui.downTimeSpinBox->setValue( this->settings[DownTime] );
}

SpectrumSettingsDialog::~SpectrumSettingsDialog()
{
}

const QMap<Settings,qreal>& SpectrumSettingsDialog::getReturn() const
{
    return this->settings;
}

QMap<Settings,qreal>
SpectrumSettingsDialog::getSettings( const QMap<Settings,qreal>& map,
                                     SpectrumWindow* ptr )
{
    QMap<Settings,qreal> settings;
    SpectrumSettingsDialog dlg( map, ptr );

    if ( dlg.exec() == QDialog::Accepted )
        settings = dlg.getReturn();
    else
        settings = dlg.getReturn();

    return settings;
}

void SpectrumSettingsDialog::set_up_time( int val )
{
    this->settings[UpTime] = val;
}

void SpectrumSettingsDialog::set_down_time( int val )
{
    this->settings[DownTime] = val;
}

void SpectrumSettingsDialog::set_max_noise( double val )
{
    this->settings[MaxNoise] = val;
}

void SpectrumSettingsDialog::set_average_noise( double val )
{
    this->settings[AverageNoise] = val;
}

