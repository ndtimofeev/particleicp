#include <QDebug>
#include <QVector>
#include <QString>
#include <QMap>
#include <QStringList>
#include "falgorithms.h"
#include "edittable.h"

// The function creates the subtable, which contains all values of in-put table
// (table) greater than the maximal background deviation (settings).

VectorTable edt::filtertable( const VectorTable& table, const QVariantMap& settings )
{
// The empty subtable, containing the names of columns from the original table,
// is created. 
    VectorTable result( table.getTags() );

// Define the list of lines, which keep the names of the chosen columns of
// in-put table.
    QStringList tags;

// Define the list of pairs key-value for keeping of maximal background
// deviation associated with in-put table colums names.
    QMap<QString,double> limits;

// For each column name from whole lists of column names of in-put table (exept
// first column, where do we have the X values, which are out of our
// interest)...
    foreach( QString tag, fp::tail( table.getTags() ) )
    {
// ...if it is marked in settings that the signals should be analysed...
        if ( settings[QString("%1_State").arg(tag)].toBool() )
        {
// ...to add the column name to the list of chosen column of the in-put table...
            tags << tag;
// ...and associate the limit value for this column (taken from settings) with
// the name of this column.
            limits[tag] = settings[QString("%1_MaxNoise").arg(tag)].toDouble();
        }
    }

// For each line of the in-put table...
    for ( int i = 0, j = table.getHeight(); i < j; i++ )
    {
// ...we assume that into the each cell the signal value is contained
        bool check = true;

// For each column of interest...
        foreach( QString tag, tags )
        {
// ...if the value in the cell on the intersection of the cell of interest and
// column of interest is lower than the background deviation for the respective
// column...
            if ( table.getColumn(tag)->at(i) < limits[tag] )
            {
// ...the signal value of all cell of this line corresponds to the background
// deviation...
                check = false;
// ...and the searching continious through the next line.
                break;
            }
        }

// If the cells contain the measured signal...
        if ( check )
// ...than the line is added to the out-put subtable
            result << table.getRow(i);
    }

// The out-put small-table is created.
    return result;
}
