#include <QDebug>
#include <QString>
#include <QStringList>
#include "jycomposer.h"

void JYComposer( const VectorTable* table, QTextStream &stream )
{
    QString delim = "\t";
    if ( ! stream.device()->isWritable() )
        return;

    QStringList tags = table->getTags();
    stream << tags.join(delim) << endl;

    for ( int i = 0, j = table->getHeight(); i < j; i++ )
    {
        QVector<double> vec = table->getRow( i );
        stream << vec.first();

        for ( QVector<double>::iterator i = vec.begin() + 1, j = vec.end(); i != j; i++ )
            stream << delim << *i;

        stream << endl;
    }
}
