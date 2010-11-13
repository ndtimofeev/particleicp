#ifndef RANGEBOX_H
#define RANGEBOX_H

#include <QWidget>
#include <QObject>
#include <QPair>
#include <QString>
#include <QHBoxLayout>
#include <QDoubleSpinBox>

class RangeBox : public QWidget
{
    Q_OBJECT
    Q_PROPERTY( double max READ maxValue WRITE setMaxValue )
    Q_PROPERTY( double min READ minValue WRITE setMinValue )

signals:
    void maxValueChanged( double val );
    void minValueChanged( double val );

public:
    RangeBox( QWidget* parent = 0 );
    virtual ~RangeBox();

    int     decimals() const;
    double  maximum() const;
    double  minimum() const;
    QString prefix() const;
    void    setDecimals( int prec );
    void    setMaximum( double max );
    void    setMinimum( double min );
    void    setPrefix( const QString& prefix );
    void    setRange( double minimum, double maximum );
    void    setSingleStep( double val );
    void    setSuffix( const QString& suffix );
    double  singleStep() const;
    QString suffix() const;
    double  maxValue() const;
    double  minValue() const;
    QDoubleSpinBox* min_ptr;
    QDoubleSpinBox* max_ptr;

public slots:
    void setMaxValue( double max );
    void setMinValue( double min );

private slots:
    void setMinimumForMax( double min );
    void setMaximumForMin( double max );

//private:
};

#endif /* RANGEBOX_H */
