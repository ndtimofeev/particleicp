#include <QDebug>
#include "spectrumsettingswizard.h"
#include "spectrumsettings.h"
#include "curvesettings.h"

SpectrumSettingsWizard::SpectrumSettingsWizard( const QMap<Spectrum::Settings,QVariant>& settings,
                                                const QMap<Spectrum::Limits,QVariant>& limits,
                                                QWidget* parent ) :
    QWizard( parent ),
    pages( settings[Spectrum::CurveSettings].toMap().keys() ),
    curves( settings[Spectrum::CurveSettings].toMap() )
{
    this->setModal( true );
    this->setOptions( QWizard::NoBackButtonOnStartPage );
    this->addPage( new SpectrumSettings( settings, limits, this ) );

    foreach( QString str, this->pages )
        if ( settings[Spectrum::CurveSettings].toMap().value( str ).toBool() )
            this->setPage( this->getPageId( str ), new CurveSettings( str, this ) );

    connect( this->page( 0 ), SIGNAL( pageStateChanged( QString ) ), this, SLOT( pageEdit( QString ) ) );
}

SpectrumSettingsWizard::~SpectrumSettingsWizard()
{
}

void SpectrumSettingsWizard::pageEdit( const QString& pageName )
{
    if ( this->curves.value( pageName ).toBool() )
        this->removePage( this->getPageId( pageName ) );
    else
        this->setPage( this->getPageId( pageName ), new CurveSettings( pageName, this ) );

    this->curves[pageName] = this->curves[pageName].toBool() ? false : true;

    this->setPage( this->pages.size() + 1, new CurveSettings( "hack", this ) );
    this->removePage( this->pages.size() + 1 );
}

int SpectrumSettingsWizard::getPageId( const QString& str ) const
{
    return this->pages.indexOf( str ) + 1;
}
