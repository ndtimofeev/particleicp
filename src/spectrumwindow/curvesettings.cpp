#include <QDebug>
#include "curvesettings.h"
#include "ui_curvesettings.h"

CurveSettings::CurveSettings( const QString& str, QWizard* parent ) :
    QWizardPage( parent )
{
    Ui::CurveSettings ui;
    ui.setupUi( this );

    this->setTitle( QString("%1 settings").arg(str) );

    this->registerField(QString("%1_AverageNoise").arg(str), ui.averageNoiseDoubleSpinBox, "value", SIGNAL(valueChanged(double)));
    this->registerField(QString("%1_MaxNoise").arg(str), ui.maximumNoiseDoubleSpinBox, "value", SIGNAL(valueChanged(double)));
    this->registerField(QString("%1_DeltaEpsilon").arg(str), ui.deltaEpsilonDoubleSpinBox, "value", SIGNAL(valueChanged(double)));
}

CurveSettings::~CurveSettings()
{
}

