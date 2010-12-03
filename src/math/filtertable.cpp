#include <QVector>
#include <QString>
#include <QMap>
#include <QStringList>
#include "falgorithms.h"
#include "edittable.h"

VectorTable edt::filtertable( const VectorTable& table, const QVariantMap& settings )
{
    VectorTable result( table.getTags() );
    QStringList tags;
    QMap<QString,double> limits;

    foreach( QString tag, fp::tail( table.getTags() ) )
    {
        if ( settings[QString("%1_State").arg(tag)].toBool() )
        {
            tags << tag;
            limits[tag] = settings[QString("%1_MaxNoise").arg(tag)].toDouble();
        }
    }

    for ( int i = 0, j = table.getHeight(); i < j; i++ )
    {
        bool check = true;
        foreach( QString tag, tags )
        {
            if ( table.getColumn(tag)->at(i) < limits[tag] )
            {
                check = false;
                break;
            }
        }
        if ( check )
            result << table.getRow(i);
    }

    return result;
}
