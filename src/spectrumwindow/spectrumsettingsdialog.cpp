#include <QDebug>
#include <QCheckBox>
#include "spectrumsettingsdialog.h"
#include "ui_spectrumsettingsdialog.h"

SpectrumSettingsDialog::SpectrumSettingsDialog( const QMap<Spectrum::Settings,QVariant>& settings,
                                                const QMap<Spectrum::Limits,QVariant>&   limits,
                                                SpectrumWindow* parent ) :
    QDialog( parent ),
    settings( settings ),
    limits( limits )
{
    Ui::SpectrumSettingsDialog ui;
    ui.setupUi( this );

    ui.upTimeSpinBox->setRange( limits[Spectrum::MinTime].toInt(), limits[Spectrum::MaxTime].toInt() );
    ui.upTimeSpinBox->setValue( settings[Spectrum::UpTime].toInt() );

    ui.downTimeSpinBox->setRange( limits[Spectrum::MinTime].toInt(), limits[Spectrum::MaxTime].toInt() );
    ui.downTimeSpinBox->setValue( settings[Spectrum::DownTime].toInt() );

    foreach( QString str, settings[Spectrum::CurveSettings].toMap().keys() )
    {
        QCheckBox* cb = new QCheckBox( str, this );

        if ( settings[Spectrum::CurveSettings].toMap().value( str ).toBool() )
            cb->setCheckState( Qt::Checked );

        ui.verticalLayout_4->addWidget( cb );
    }

    ui.verticalLayout_4->addStretch();
}

SpectrumSettingsDialog::~SpectrumSettingsDialog()
{
}

const QMap<Spectrum::Settings,QVariant>& SpectrumSettingsDialog::getReturn() const
{
    return this->settings;
}

QMap<Spectrum::Settings,QVariant>
SpectrumSettingsDialog::getSettings( const QMap<Spectrum::Settings,QVariant>& settings,
                                     const QMap<Spectrum::Limits,QVariant>&   limits,
                                     SpectrumWindow* ptr )
{
    QMap<Spectrum::Settings,QVariant> result;
    SpectrumSettingsDialog dlg( settings, limits, ptr );

    if ( dlg.exec() == QDialog::Accepted )
        result = dlg.getReturn();
    else
        result = settings;

    return result;
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

void SpectrumSettingsDialog::set_histogram_step( double val )
{
    this->settings[Spectrum::HistogramStep] = val;
}

