#include <QtConcurrentMap>
#include <QVector>
#include <QDebug>
#include <gmpxx.h>
#include "edittable.h"
#include "falgorithms.h"

// Функция возвращающая таблицу содержащую значения сигналов из таблицы (table) за
// вычетом среднеих значений шума содержащихся в объекте настроек (settings).

// Функциональный объект предназначенный для того чтобы воспользоваться
// волшебством MapReduce (за этим в прямом смысле слова в Гугл) и ускорить
// вычисления за счёт параллельности...
class delta_mp
{
public:
    delta_mp(double b) : b_v( b ) {}

    typedef double result_type;

// ...который вычисляет разности входного значения и числа a, причём делает это
// с произвольной точностью, что позволяет избежать накопления погрешности.
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
// Создаётся выходная таблица из одного столбца равному нулевому столбцу входной таблицы
// и с таким же именем.
    VectorTable result( table.getTags().first(), *table.getColumn( 0 ) );

// Для каждого столбца из числа всех столбцов входной таблицы кроме первого...
    foreach( QString tag, fp::tail( table.getTags() ) )
    {

// ...вычитаем из всех значений данного столбца значение среднего шума для
// данного столбца...
        QVector<double> vec = QtConcurrent::blockingMapped( *table.getColumn(tag),
            delta_mp(settings[QString("%1_AverageNoise").arg(tag)].toDouble()));

// ...и добавляем в выходную таблицу полученный столбец
        result.addColumn( tag, vec );
    }

// Возвращается выходная таблица.
    return result;
}
