#include <stdexcept>
#include "jyparser.h"

JYTable::JYTable( const QStringList& head )
{
    if ( head.isEmpty() )
        throw std::invalid_argument( "JYTable: creating empty table" );

    this->size = head.size();
    this->head = head;
    for ( int i = 0; i < this->size - 1; i++ )
        table << new QVector<qreal>();
}

JYTable::~JYTable()
{
}

const QVector<qreal>* JYTable::getColumn( const QString& name ) const
{
    return this->table.at( this->head.indexOf( name ) );
}

const QString& JYTable::getColumnName( int i ) const
{
    return this->head[i];
}

int JYTable::getSize() const
{
    return this->size;
}

JYTable& JYTable::operator<< ( const QStringList& list )
{
    if ( list.size() != this->size )
        throw std::invalid_argument( "JYTable: added bad row" );

    for ( int i = 0; i < this->size - 1; i++ )
        *this->table[i] << list.at(i).toDouble();

    return *this;
}

/*
JYTable& JYTable::operator= ( const JYTable& table )
{
    this->size = table.getSize();
    for ( int i = 0; i < this->size - 1; i++    )
    {
        this->head << table.getColumnName( i );
        this->table << new QVector<qreal>( *table.getColumn( i ) );
    }

    return *this;
}
*/

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
}

const JYTable& JYParser::getTable() const
{
    return *this->table;
}
