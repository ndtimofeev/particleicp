#include <QCheckBox>
#include <QDebug>
#include <QButtonGroup>
#include "spectrumsettings.h"
#include "curvesettings.h"
#include "ui_spectrumsettings.h"

SpectrumSettings::SpectrumSettings( const QMap<QString,QVariant>& settings,
                                    const QMap<QString,QVariant>& limits,
                                    QWizard* parent ) :
    QWizardPage( parent ),
    settings( settings )
{
    Ui::SpectrumSettings ui;
    ui.setupUi( this );

    ui.timeRangeWidget->setSingleStep( 100 );
    ui.timeRangeWidget->setDecimals( 1 );
    ui.timeRangeWidget->setSuffix( " sec" );

    ui.timeRangeWidget->setRange( limits["MinTime"].toDouble(),
                                  limits["MaxTime"].toDouble() );

    ui.timeRangeWidget->setMinValue( settings["DownTime"].toDouble() );
    ui.timeRangeWidget->setMaxValue( settings["UpTime"].toDouble() );

    QButtonGroup* group = new QButtonGroup( this );

    group->setExclusive( false );

    foreach( QString str, settings["Spectrums"].toStringList() )
    {
        QCheckBox* cb = new QCheckBox( str, this );

        group->addButton( cb );

        if ( settings[QString("%1_State").arg(str)].toBool() )
            cb->setCheckState( Qt::Checked );

        ui.checkBoxLayout->addWidget( cb );
    }

    ui.checkBoxLayout->addStretch();

    this->registerField( "UpTime",   ui.timeRangeWidget,
                         "max",      SIGNAL(maxValueChanged(double)));

    this->registerField( "DownTime", ui.timeRangeWidget,
                         "min",      SIGNAL(minValueChanged(double)));

    connect( group, SIGNAL( buttonPressed( QAbstractButton* ) ),
             this,  SLOT( stateChanged( QAbstractButton* ) ) );
}

SpectrumSettings::~SpectrumSettings()
{
}

void SpectrumSettings::stateChanged( QAbstractButton* bt )
{
    if ( bt->isCheckable() )
        emit pageStateChanged( bt->text() );
}

