#include <QDebug>
#include "curvesettings.h"
#include "ui_curvesettings.h"

CurveSettings::CurveSettings( const QString& str,
                              const QMap<QString,QVariant>& settings,
                              QWizard* parent ) :
    QWizardPage( parent )
{
    Ui::CurveSettings ui;
    ui.setupUi( this );

    ui.averageNoiseDoubleSpinBox->setValue(
                    settings[QString("%1_AverageNoise").arg(str)].toDouble() );

    ui.maximumNoiseDoubleSpinBox->setValue(
                    settings[QString("%1_MaxNoise").arg(str)].toDouble() );

    ui.deltaEpsilonDoubleSpinBox->setValue(
                    settings[QString("%1_DeltaEpsilon").arg(str)].toDouble() );

    this->setTitle( QString("%1 settings").arg(str) );

    this->registerField( QString("%1_AverageNoise").arg(str),
                         ui.averageNoiseDoubleSpinBox,
                         "value",
                         SIGNAL(valueChanged(double)) );

    this->registerField( QString("%1_MaxNoise").arg(str),
                         ui.maximumNoiseDoubleSpinBox,
                         "value",
                         SIGNAL(valueChanged(double)) );

    this->registerField( QString("%1_DeltaEpsilon").arg(str),
                         ui.deltaEpsilonDoubleSpinBox,
                         "value",
                         SIGNAL(valueChanged(double)) );
}

CurveSettings::~CurveSettings()
{
}

