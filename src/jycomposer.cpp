#include <QDebug>
#include <QString>
#include "jycomposer.h"
#include "falgorithms.h"

void JYComposer( const VectorTable* table, QTextStream &stream,
                                                    const QStringList& columns )
{
    QString delim = "\t";
    if ( ! stream.device()->isWritable() )
        return;

    QStringList tags = table->getTags();

    QVector<int> index;

    if ( ! columns.isEmpty() )
        foreach( QString str, columns )
            index << tags.indexOf( str );

    bool state = index.isEmpty();

    stream << ( state ? tags.join(delim) :
                                fp::rebuild( tags, index ).join(delim) ) << endl;

    for ( int i = 0, j = table->getHeight(); i < j; i++ )
    {
        QVector<double> vec = state ? table->getRow( i ) :
                                    fp::rebuild( table->getRow( i ), index );

        stream << vec.first();

        for ( QVector<double>::iterator i = vec.begin() + 1, j = vec.end(); i != j; i++ )
            stream << delim << *i;

        stream << endl;
    }
}
