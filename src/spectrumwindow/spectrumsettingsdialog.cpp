#include <QSpinBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include "spectrumsettingsdialog.h"

SpectrumSettingsDialog::SpectrumSettingsDialog( const QMap<Settings,qreal>& map,
                                                SpectrumWindow* parent ) :
    QDialog( parent )
{
    this->settings = map;
    this->setModal( true );

    QFormLayout* lay = new QFormLayout( this );

    QDoubleSpinBox* max_noise_spin = new QDoubleSpinBox();
    max_noise_spin->setValue( this->settings[MaxNoise] );
    max_noise_spin->setDecimals( 3 );
    max_noise_spin->setSingleStep( 0.001 );
    lay->addRow( tr( "Max noise" ), max_noise_spin );
    connect( max_noise_spin, SIGNAL( valueChanged( double ) ),
             this, SLOT( set_max_noise( double ) ) );

    QDoubleSpinBox* average_noise_spin = new QDoubleSpinBox();
    average_noise_spin->setValue( this->settings[AverageNoise] );
    average_noise_spin->setDecimals( 3 );
    average_noise_spin->setSingleStep( 0.001 );
    lay->addRow( tr( "Max noise" ), average_noise_spin );
    connect( average_noise_spin, SIGNAL( valueChanged( double ) ),
             this, SLOT( set_average_noise( double ) ) );

    QSpinBox* maxspin = new QSpinBox();
    maxspin->setRange( this->settings[MinTime], this->settings[MaxTime] );
    maxspin->setValue( this->settings[UpTime] );
    maxspin->setSingleStep( 100 );
    maxspin->setSuffix( " sec" );
    connect( maxspin, SIGNAL( valueChanged( int ) ),
             this, SLOT( set_max_time( int ) ) );

    QSpinBox* minspin = new QSpinBox();
    minspin->setRange( this->settings[MinTime], this->settings[MaxTime] );
    minspin->setValue( this->settings[DownTime] );
    minspin->setSingleStep( 100 );
    minspin->setSuffix( " sec" );
    connect( minspin, SIGNAL( valueChanged( int ) ),
             this, SLOT( set_min_time( int ) ) );

    QHBoxLayout* spinslayout = new QHBoxLayout( this );
    spinslayout->addWidget( minspin );
    spinslayout->addWidget( maxspin );

    lay->addRow( tr( "Time range" ), spinslayout );

    QDialogButtonBox* buttonbox = new QDialogButtonBox( QDialogButtonBox::Ok |
                                                        QDialogButtonBox::Cancel,
                                                        Qt::Horizontal,
                                                        this );

    connect( buttonbox, SIGNAL( accepted() ), this, SLOT( accept() ) );
    connect( buttonbox, SIGNAL( rejected() ), this, SLOT( reject() ) );
    lay->addRow( buttonbox );
}

SpectrumSettingsDialog::~SpectrumSettingsDialog()
{
}

const QMap<Settings,qreal>& SpectrumSettingsDialog::getReturn() const
{
    return this->settings;
}

QMap<Settings,qreal>
SpectrumSettingsDialog::getSettings( const QMap<Settings,qreal>& map,
                                     SpectrumWindow* ptr )
{
    QMap<Settings,qreal> settings;
    SpectrumSettingsDialog dlg( map, ptr );

    if ( dlg.exec() == QDialog::Accepted )
        settings = dlg.getReturn();
    else
        settings = dlg.getReturn();

    return settings;
}

void SpectrumSettingsDialog::set_max_time( int val )
{
    this->settings[UpTime] = val;
}

void SpectrumSettingsDialog::set_min_time( int val )
{
    this->settings[DownTime] = val;
}

void SpectrumSettingsDialog::set_max_noise( double val )
{
    this->settings[MaxNoise] = val;
}

void SpectrumSettingsDialog::set_average_noise( double val )
{
    this->settings[AverageNoise] = val;
}

