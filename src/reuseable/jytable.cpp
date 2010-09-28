#include <QDebug>
#include "jytable.h"

JYTable::JYTable( const QStringList& head ) : AbstractTable<qreal>()
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
    int i = this->head.indexOf( name );
    return this->getColumn( i );
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

    this->hight++;

    return *this;
}

JYTable& JYTable::operator<< ( const QStringList& list )
{
    QList<qreal> n_list;
    foreach( QString str, list )
        n_list << str.toDouble();

    return *this << n_list;
}

