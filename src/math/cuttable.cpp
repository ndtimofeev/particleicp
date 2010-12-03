#include "edittable.h"

VectorTable edt::cuttable( const VectorTable& table, double start, double finish )
{
    if ( start >= finish )
        qFatal( "cuttable: start >= finish" );

    const QVector<double>* scale = table.getColumn( table.getTags().first() );

    int pos = -1, length = -1;

    for ( QVector<double>::const_iterator i = scale->begin(), j = scale->end(),
                                                            k = i; i != j; i++ )
    {
        if (( pos == -1 ) && ( *i > start ))
            pos = i - k;

        if (( pos != -1 ) && ( *i > finish ))
        {
            length = i - k - pos - 1;
            break;
        }
    }

    return table.mid( pos, length );
}
