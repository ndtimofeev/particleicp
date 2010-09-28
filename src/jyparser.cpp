#include <stdexcept>
#include "jyparser.h"

JYParser::JYParser( QTextStream* stream, QObject* parent  ) : QObject( parent )
{
    if ( ! stream->device()->isReadable() )
        throw std::invalid_argument( "JYParser: input stream is not readable" );

    this->table = new JYTable( stream->readLine().split("\t") );

    for ( QString str = stream->readLine(); str != ""; str = stream->readLine() )
        *this->table << str.split("\t");
}

JYParser::~JYParser()
{
    delete this->table;
}

const JYTable& JYParser::getTable() const
{
    return *this->table;
}
