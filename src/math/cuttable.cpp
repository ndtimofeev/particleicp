#include "cuttable.h"

VectorTable cuttable( const VectorTable& table, double start, double finish )
{
    if ( start >= finish )
        qFatal( "cuttable: start >= finish" );

    const QVector<double>* scale = table.getColumn( table.getTags().first() );

    int pos = -1, length = -1;

    for ( QVector<double>::const_iterator i = scale->begin();
                                          i != scale->end(); i++ )
    {
        if (( pos == -1 ) && ( *i > start ))
            pos = i - scale->begin();

        if (( pos != -1 ) && ( *i > finish ))
        {
            length = i - scale->begin() - pos - 1;
            break;
        }
    }

    return table.mid( pos, length );
}
