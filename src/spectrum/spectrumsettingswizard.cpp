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
            this->setPage( this->getPageId( str ), new CurveSettings( str, settings, this ) );

    connect( this->page( 0 ), SIGNAL( pageStateChanged( QString ) ),
             this,            SLOT( wizardEdit( QString ) ) );

    connect( this->button( QWizard::FinishButton ), SIGNAL( clicked() ),
             this, SLOT( saveState() ) );

    this->button( QWizard::FinishButton )->hide();
}

SpectrumSettingsWizard::~SpectrumSettingsWizard()
{
}

QMap<QString,QVariant>
SpectrumSettingsWizard::getSpectrumSettings( const QMap<QString,QVariant>& settings,
                                             const QMap<QString,QVariant>& limits,
                                             QWidget* parent )
{
    QMap<QString,QVariant> value;
    SpectrumSettingsWizard dlg( settings, limits, parent );

    if ( dlg.exec() == QDialog::Accepted )
        value = dlg.getState();

    return value;
}

QMap<QString,QVariant> SpectrumSettingsWizard::getState() const
{
    return this->settings;
}

void SpectrumSettingsWizard::wizardEdit( const QString& pageName )
{
    bool state = this->settings[QString("%1_State").arg(pageName)].toBool();

    if ( state )
    {
        this->settings[QString("%1_AverageNoise").arg(pageName)] =
                        this->field(QString("%1_AverageNoise").arg(pageName));

        this->settings[QString("%1_MaxNoise").arg(pageName)] =
                        this->field(QString("%1_MaxNoise").arg(pageName));

        this->settings[QString("%1_DeltaEpsilon").arg(pageName)] =
                        this->field(QString("%1_DeltaEpsilon").arg(pageName));

        this->deletePage( this->getPageId( pageName ) );
    }
    else
    {
        this->setPage( this->getPageId( pageName ),
                       new CurveSettings( pageName, settings, this ) );

        this->setPage( this->pages.size() + 1, new QWizardPage( this ) );
        this->deletePage( this->pages.size() + 1 );
    }

    this->settings[QString("%1_State").arg(pageName)] = state ? false : true;

    this->button( QWizard::FinishButton )->hide();
}

void SpectrumSettingsWizard::saveState()
{
    this->settings["UpTime"] = this->field("UpTime");
    this->settings["DownTime"] = this->field("DownTime");

    foreach( QString str, this->settings["Curves"].toStringList() )
    {
        if ( this->settings[QString("%1_State").arg(str)].toBool() )
        {
            this->settings[QString("%1_AverageNoise").arg(str)] =
                            this->field(QString("%1_AverageNoise").arg(str));

            this->settings[QString("%1_MaxNoise").arg(str)] =
                            this->field(QString("%1_MaxNoise").arg(str));

            this->settings[QString("%1_DeltaEpsilon").arg(str)] =
                            this->field(QString("%1_DeltaEpsilon").arg(str));
        }
    }
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

