#include <QVariant>
#include "spectrumsettingswizard.h"
#include "spectrumsettings.h"
#include "curvesettings.h"

SpectrumSettingsWizard::SpectrumSettingsWizard( const QMap<Spectrum::Settings,QVariant>& settings,
                                                const QMap<Spectrum::Limits,QVariant>& limits,
                                                QWidget* parent ) :
    QWizard( parent ),
    pages( settings[Spectrum::CurveSettings].toMap().keys() )
{
    this->setModal( true );
    this->setOptions( QWizard::NoBackButtonOnStartPage );
    this->addPage( new SpectrumSettings( settings, limits, this ) );

    foreach( QString str, this->pages )
        if ( settings[Spectrum::CurveSettings].toMap().value( str ).toBool() )
            this->setPage( this->getPageId( str ), new CurveSettings( str, this ) );
}

SpectrumSettingsWizard::~SpectrumSettingsWizard()
{
}

int SpectrumSettingsWizard::getPageId( const QString& str ) const
{
    return this->pages.indexOf( str ) + 1;
}
