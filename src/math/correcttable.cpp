#include <QtConcurrentMap>
#include <QVector>
#include <QDebug>
#include <gmpxx.h>
#include "edittable.h"
#include "falgorithms.h"

class delta_mp
{
public:
    delta_mp(double b) : b_v( b ) {}

    typedef double result_type;

    double operator()( double a )
    {
        mpf_class a_mp = a, b_mp = b_v, c_mp = a_mp - b_mp;
        return c_mp.get_d();
    }

    double b_v;
};

VectorTable edt::correcttable( const VectorTable& table,
        const QVariantMap& settings )
{
    VectorTable result( table.getTags().first(), *table.getColumn( 0 ) );

    foreach( QString tag, fp::tail( table.getTags() ) )
    {
        QVector<double> vec = QtConcurrent::blockingMapped( *table.getColumn(tag),
            delta_mp(settings[QString("%1_AverageNoise").arg(tag)].toDouble()));
        result.addColumn( tag, vec );
    }

    return result;
}
