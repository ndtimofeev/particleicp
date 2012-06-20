#include <QtConcurrentMap>
#include <QVector>
#include <QDebug>
#include <gmpxx.h>
#include "edittable.h"
#include "falgorithms.h"

// The function returns the table, which contain the in-put table (table) data
// with background level substraction, taken from the settings parameters
// (settings).

// The functional part, which allows to work with MapReduce and accelerate the
// calculation procedure due to the concurrent processes...
class delta_mp
{
public:
    delta_mp(double b) : b_v( b ) {}

    typedef double result_type;

// ...which is calculatind as difference between in-put value and value a;
// the program performe this procedure with any value of the deviation, this
// allows to decrease the errors accumulation.
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
// The table (containing one column, which is equal to zero column of in-put
// table) is created. Tha table has the same name.
    VectorTable result( table.getTags().first(), *table.getColumn( 0 ) );

// For each column of the in-put table (exept column one)...
    foreach( QString tag, fp::tail( table.getTags() ) )
    {

// ...substract the average value of background from the each value, containing
// into the column for each column 
        QVector<double> vec = QtConcurrent::blockingMapped( *table.getColumn(tag),
            delta_mp(settings[QString("%1_AverageNoise").arg(tag)].toDouble()));

// ...and add the obtained column to the table
        result.addColumn( tag, vec );
    }

// The out-put table is done.
    return result;
}
