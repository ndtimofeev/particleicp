#include <QCheckBox>
#include <QButtonGroup>
#include "spectrumsettings.h"
#include "curvesettings.h"
#include "ui_spectrumsettings.h"

SpectrumSettings::SpectrumSettings( const QMap<Spectrum::Settings,QVariant>& settings,
                                    const QMap<Spectrum::Limits,QVariant>& limits,
                                    QWizard* parent ) :
    QWizardPage( parent ),
    settings( settings )
{
    Ui::SpectrumSettings ui;
    ui.setupUi( this );
    ui.timeRangeWidget->setRange( limits[Spectrum::MinTime].toDouble(), limits[Spectrum::MaxTime].toDouble() );
    ui.timeRangeWidget->setMinValue( settings[Spectrum::DownTime].toDouble() );
    ui.timeRangeWidget->setMaxValue( settings[Spectrum::UpTime].toDouble() );
    ui.timeRangeWidget->setSingleStep( 100 );
    ui.timeRangeWidget->setDecimals( 1 );
    ui.timeRangeWidget->setSuffix( " sec" );

    QButtonGroup* group = new QButtonGroup( this );

    group->setExclusive( false );

    foreach( QString str, settings[Spectrum::CurveSettings].toMap().keys() )
    {
        QCheckBox* cb = new QCheckBox( str, this );

        group->addButton( cb );

        if ( settings[Spectrum::CurveSettings].toMap().value( str ).toBool() )
            cb->setCheckState( Qt::Checked );

        ui.checkBoxLayout->addWidget( cb );
    }

    ui.checkBoxLayout->addStretch();

    this->registerField( "UpTime",   ui.timeRangeWidget, "max", SIGNAL(maxValueChanged(double)));
    this->registerField( "DownTime", ui.timeRangeWidget, "min", SIGNAL(minValueChanged(double)));

    connect( group, SIGNAL( buttonPressed( QAbstractButton* ) ), this, SLOT( stateChanged( QAbstractButton* ) ) );
}

SpectrumSettings::~SpectrumSettings()
{
}

void SpectrumSettings::stateChanged( QAbstractButton* bt )
{
    if ( bt->isCheckable() )
        emit pageStateChanged( bt->text(), bt->isChecked() );
}

