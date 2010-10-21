#include <QDebug>
#include <QCoreApplication>
#include <QStringList>
#include <QVector>
#include "falgorithms.h"
#include "jyparser.h"

VectorTable JYParser( const QSet<QString>& head, QTextStream& stream  )
{
    if ( ! stream.device()->isReadable() )
        qFatal( "JYParser: input stream is not readable" );

    if ( head.size() < 2 )
        qFatal( "JYParser: table must have two or more columns" );

    QStringList  list = stream.readLine().split("\t");
    QVector<int> index;

    foreach( QString tag, head )
        index << list.indexOf( tag );

    qSort( index );

    VectorTable table( fp::rebuild( list, index ) );

    for ( QString str = stream.readLine(); str != ""; str = stream.readLine() )
    {
        table << fp::rebuild( str.split("\t"), index );
        qApp->processEvents();
    }

    return table;
}

