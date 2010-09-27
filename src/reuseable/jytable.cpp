#include "jytable.h"

JYTable::JYTable( const QStringList& head ) : AbstractTable()
{
    if ( head.isEmpty() )
        qFatal( "JYTable: creating null size table" );

    this->head = head;
    this->wight = head.size();
}

JYTable::~JYTable()
{
}

QVector<qreal> JYTable::getColumn( const QString& name ) const
{
    return this->getColumn( this->head.indexOf( name ) );
}

QVector<qreal> JYTable::getColumn( int x ) const
{
    if ( x > this->wight )
        qFatal( "JYTable: column does not exists" );

    QVector<qreal> vector( this->hight );
    for ( int i = 0; i < this->hight - 1; i++ )
        if ( this->table.contains( Position( x, i ) ) )
            vector.replace( i, this->table.value( Position( x, i ) ) );

    return vector;
}

JYTable& JYTable::operator<< ( const QList<qreal>& list )
{
    if ( list.size() != this->wight )
        qFatal( "JYTable: added bad row" );

    for ( int i = 0; i < this->wight - 1; i++ )
        this->table[Position( i, this->hight )] = list.at(i);

    return *this;
}

JYTable& JYTable::operator<< ( const QStringList& list )
{
    QList<qreal> n_list;
    for ( QString str, list )
        n_list << str.toDouble();

    return *this << n_list;
}

