#ifndef EDITTABLE_H
#define EDITTABLE_H

#include <QVariantMap>
#include "vectortable.h"

namespace edt {

    VectorTable cuttable( const VectorTable& table, double start, double finish );
    VectorTable filtertable( const VectorTable& table, const QVariantMap& settings );
    VectorTable correcttable( const VectorTable& table, const QVariantMap& settings );

}

#endif /* EDITTABLE_H */

