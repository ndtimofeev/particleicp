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

    connect( this->page( 0 ), SIGNAL( pageStateChanged( QString, bool ) ), this, SLOT( wizardEdit( QString, bool ) ) );
}

SpectrumSettingsWizard::~SpectrumSettingsWizard()
{
}

void SpectrumSettingsWizard::wizardEdit( const QString& pageName, bool state )
{
    if ( state )
        this->deletePage( this->getPageId( pageName ) );
    else
    {
        this->setPage( this->getPageId( pageName ), new CurveSettings( pageName, this ) );
        this->setPage( this->pages.size() + 1, new CurveSettings( "hack", this ) );
        this->deletePage( this->pages.size() + 1 );
    }

    this->curves[pageName] = state;

}

int SpectrumSettingsWizard::getPageId( const QString& str ) const
{
    return this->pages.indexOf( str ) + 1;
}

void SpectrumSettingsWizard::deletePage( int id )
{
    QWizardPage* wp_ptr = this->page( id );
    this->removePage( id );
    delete wp_ptr;
}

