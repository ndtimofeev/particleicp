#include "edittable.h"

// The function substract from the table (table) the defined subtable, which
// corresponds to the X interval, defining by beginning (start) and final
// (finish) values.

VectorTable edt::cuttable( const VectorTable& table, double start, double finish )
{
// At the beginning, the defined interval is verified. If the beginning value
// more or equal to the final value...
    if ( start >= finish )
// ...the program immidiately closes.
        qFatal( "cuttable: start >= finish" );

// The acces to read the file with first column of the table is obtained (where
// the X values are kept). The access is performed due to the constant reference
// to QVector<double>. This reference is made by the invocation of VectorTable
// function.
    const QVector<double>* scale = table.getColumn( table.getTags().first() );

    int pos = -1, length = -1;

// Define: i is a first cell of the column, which contains X values; j is the
// last cell of the same column; k is equal to first i value. Check all cells of
// the column untill i < j.
    for ( QVector<double>::const_iterator i = scale->begin(), j = scale->end(),
                                                            k = i; i != j; i++ )
    {
// For each cell…
//
// If the the number of the firs cell does not change from the beginning of
// searching (e.g. equal to -1) and the value of the cell of interest is higher
// than the interval beginning...
        if (( pos == -1 ) && ( *i > start ))
// ...than the number of the first line of the small cell is equal to the number
// of gaps between first cell and current cell.
            pos = i - k;

// If the the number of the firs cell does change from the beginning of
// searching (e.g. does not equal to -1) and the value of the cess of interest
// is higher than the end of the interval...
        if (( pos != -1 ) && ( *i > finish ))
        {
// ...than the lengths of the obtained table is equal to the cell of interest
// position, minus the position of the first (start) cell, minus 1...
            length = i - k - pos - 1;
// ...and searching is immidiately finishes.
            break;
        }
    }

// The table (converted from the original table) started from pos line and with
// lengths lengths is created. The section of the table is performed due to the
// internal function.
    return table.mid( pos, length );
}
