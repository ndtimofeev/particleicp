#include "rangebox.h"

RangeBox::RangeBox( QWidget* parent ) : QWidget( parent )
{
    QHBoxLayout* layout = new QHBoxLayout( this );

    this->min_ptr = new QDoubleSpinBox;
    layout->addWidget( this->min_ptr );

    this->max_ptr = new QDoubleSpinBox;
    layout->addWidget( this->max_ptr );

    connect( this->min_ptr, SIGNAL( valueChanged( double ) ), this, SLOT( setMinimumForMax( double ) ) );
    connect( this->max_ptr, SIGNAL( valueChanged( double ) ), this, SLOT( setMaximumForMin( double ) ) );

    connect( this->max_ptr, SIGNAL( valueChanged( double ) ), this, SIGNAL( maxValueChanged( double ) ) );
    connect( this->min_ptr, SIGNAL( valueChanged( double ) ), this, SIGNAL( minValueChanged( double ) ) );
}

RangeBox::~RangeBox()
{
}

int RangeBox::decimals() const
{
    return this->min_ptr->decimals();
}

double RangeBox::maximum() const
{
    return this->max_ptr->maximum();
}

double RangeBox::minimum() const
{
    return this->max_ptr->minimum();
}

QString RangeBox::prefix() const
{
    return this->min_ptr->prefix();
}

void RangeBox::setDecimals( int prec )
{
    this->min_ptr->setDecimals( prec );
    this->max_ptr->setDecimals( prec );
}

void RangeBox::setMaximum( double max )
{
    this->max_ptr->setMaximum( max );
}

void RangeBox::setMinimum( double min )
{
    this->min_ptr->setMinimum( min );
}

void RangeBox::setPrefix( const QString& prefix )
{
    this->min_ptr->setPrefix( prefix );
    this->max_ptr->setPrefix( prefix );
}

void RangeBox::setRange( double minimum, double maximum )
{
    this->min_ptr->setMinimum( minimum );
    this->max_ptr->setMaximum( maximum );
    this->min_ptr->setMaximum( this->max_ptr->minimum() );
    this->max_ptr->setMinimum( this->min_ptr->maximum() );
}

void RangeBox::setSingleStep( double val )
{
    this->min_ptr->setSingleStep( val );
    this->max_ptr->setSingleStep( val );
}

void RangeBox::setSuffix( const QString& suffix )
{
    this->min_ptr->setSuffix( suffix );
    this->max_ptr->setSuffix( suffix );
}

double RangeBox::singleStep() const
{
    return this->min_ptr->singleStep();
}

QString RangeBox::suffix() const
{
    return this->min_ptr->suffix();
}

double RangeBox::maxValue() const
{
    return this->max_ptr->value();
}

double RangeBox::minValue() const
{
    return this->min_ptr->value();
}

void RangeBox::setMaxValue( double max )
{
    this->max_ptr->setValue( max );
}

void RangeBox::setMinValue( double min )
{
    this->min_ptr->setValue( min );
}

void RangeBox::setMinimumForMax( double min )
{
    this->max_ptr->setMinimum( min );
}

void RangeBox::setMaximumForMin( double max )
{
    this->min_ptr->setMaximum( max );
}

