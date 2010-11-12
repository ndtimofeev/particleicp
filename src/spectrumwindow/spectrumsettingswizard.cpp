#include <QDebug>
#include "spectrumsettingswizard.h"
#include "spectrumsettings.h"
#include "curvesettings.h"

SpectrumSettingsWizard::SpectrumSettingsWizard( const QMap<QString,QVariant>& settings,
                                                const QMap<QString,QVariant>& limits,
                                                QWidget* parent ) :
    QWizard( parent ),
    pages( settings["Curves"].toStringList() ),
    settings( settings )
{
    this->setModal( true );
    this->setOptions( QWizard::NoBackButtonOnStartPage | QWizard::HaveHelpButton );
    this->addPage( new SpectrumSettings( settings, limits, this ) );

    foreach( QString str, this->pages )
        if ( settings[QString("%1_State").arg(str)].toBool() )
            this->setPage( this->getPageId( str ), new CurveSettings( str, this ) );

    connect( this->page( 0 ), SIGNAL( pageStateChanged( QString, bool ) ),
             this,            SLOT( wizardEdit( QString, bool ) ) );

    this->button( QWizard::FinishButton )->hide();
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
        this->setPage( this->pages.size() + 1, new QWizardPage( this ) );
        this->deletePage( this->pages.size() + 1 );
    }

    this->settings[QString("%1_State").arg(pageName)] = state;

    this->button( QWizard::FinishButton )->hide();
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

