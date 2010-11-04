#include "curvesettings.h"
#include "ui_curvesettings.h"

CurveSettings::CurveSettings( const QString& str, QWizard* parent ) : QWizardPage( parent )
{
    Ui::CurveSettings ui;
    ui.setupUi( this );
    this->setTitle( QString( "%1 settings" ).arg( str ) );
}

CurveSettings::~CurveSettings()
{
}

