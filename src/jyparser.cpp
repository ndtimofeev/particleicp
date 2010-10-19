#include <QStringList>
#include <QVector>
#include "jyparser.h"
#include "falgorithms.h"

JYTable JYParser( const QSet<QString>& head, const QTextStream& stream  )
{
    if ( ! stream.device()->isReadable() )
        qFatal( "JYParser: input stream is not readable" );

    if ( head.size() < 2 )
        qFatal( "JYParser: table must have two or more columns" );

    QTextStream  c_stream( stream.device() );
    QStringList  list = c_stream.readLine().split("\t");
    QVector<int> index;

    foreach( QString tag, head )
        index << list.indexOf( tag );

    qSort( index );

    JYTable table( fp::rebuild( list, index ) );

    for ( QString str = c_stream.readLine(); str != ""; str = c_stream.readLine() )
        table << fp::rebuild( str.split("\t"), index );

    return table;
}

