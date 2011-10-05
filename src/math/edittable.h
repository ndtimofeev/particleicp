#ifndef EDITTABLE_H
#define EDITTABLE_H

#include <QVariantMap>
#include "vectortable.h"

// Функции данного пространства имён производят операции над таблицами чисел
// двойной точности (double) имеющими именованные столбцы. При чтении входного
// файла программа преобразует данные в такую таблицу, где столбцы - данные для
// различных элементов.

namespace edt {

    VectorTable cuttable( const VectorTable& table, double start, double finish );
    VectorTable filtertable( const VectorTable& table, const QVariantMap& settings );
    VectorTable correcttable( const VectorTable& table, const QVariantMap& settings );

}

#endif /* EDITTABLE_H */

