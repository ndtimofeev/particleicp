#ifndef EDITTABLE_H
#define EDITTABLE_H

#include <QVariantMap>
#include "vectortable.h"

// the functions of this name space perform the operations with numeric tables
// of double accuracy (double) which contain named columns. Reading the in-put
// file the program convert the data to the table, where the columns represent
// the data for different elements.

namespace edt {

    VectorTable cuttable( const VectorTable& table, double start, double finish );
    VectorTable filtertable( const VectorTable& table, const QVariantMap& settings );
    VectorTable correcttable( const VectorTable& table, const QVariantMap& settings );

}

#endif /* EDITTABLE_H */
