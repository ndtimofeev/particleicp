#include "jyparser.h"
#include "falgorithms.h"

JYParser::JYParser( QTextStream* stream, QObject* parent  ) : QObject( parent )
{
    if ( ! stream->device()->isReadable() )
        qFatal( "JYParser: input stream is not readable" );

    this->table = new JYTable( stream->readLine().split("\t") );

    for ( QString str = stream->readLine(); str != ""; str = stream->readLine() )
        *this->table << str.split("\t");
}


JYParser::JYParser( const QStringList& head, QTextStream* stream, QObject* parent  ) :
    QObject( parent )
{
    if ( ! stream->device()->isReadable() )
        qFatal( "JYParser: input stream is not readable" );

    QStringList list = stream->readLine().split("\t");
    QVector<int> index;

    foreach( QString tag, head )
        index << list.indexOf( tag );

    qSort( index );

    this->table = new JYTable( fp::rebuild( list, index ) );

    for ( QString str = stream->readLine(); str != ""; str = stream->readLine() )
        *this->table << fp::rebuild( str.split("\t"), index );
}

JYParser::~JYParser()
{
    delete this->table;
}

const JYTable& JYParser::getTable() const
{
    return *this->table;
}
