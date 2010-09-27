#include "abstracttable.h"

AbstractTable::AbstractTable()
{
    this->wight = 0;
    this->hight = 0;
}

AbstractTable::~AbstractTable()
{
}

void AbstractTable::setValue( int x, int y, const QVariant& value )
{
    if ( x > this->wight )
        this->wight = x;

    if ( y > this->hight )
        this->hight = y;

    this->table[Position( x, y )] = value;
}

void AbstractTable::removeValue( int x, int y )
{
    int max_x = 0;
    int max_y = 0;

    foreach( Position pair, this->table.keys() )
    {
        if ( x < pair.first )
        {
            max_x = this->wight;
            break;
        }
        max_x = qMax( max_x, pair.first );
    }

    foreach( Position pair, this->table.keys() )
    {
        if ( y < pair.second )
        {
            max_y = this->hight;
            break;
        }
        max_y = qMax( max_y, pair.second );
    }

    this->wight = max_x;
    this->hight = max_y;

    this->table.remove( Position( x, y ) );
}

void AbstractTable::clear()
{
    this->table.clear();
    this->wight = 0;
    this->wight = 0;
}

bool AbstractTable::isEmpty() const
{
    return this->table.isEmpty();
}

const QVariant AbstractTable::getValue( int x, int y ) const
{
    return this->table.value( Position( x, y ) );
}

QVector<QVariant> AbstractTable::getColumn( int x ) const
{
    if ( x > this->wight )
        qFatal( "AbstractTable: column does not exists" );

    QVector<QVariant> vector( this->hight );
    for ( int i = 0; i < this->hight - 1; i++ )
        if ( this->table.contains( Position( x, i ) ) )
            vector.replace( i, this->table.value( Position( x, i ) ) );

    return vector;
}

QVector<QVariant> AbstractTable::getRow( int y ) const
{
    if ( y > this->hight )
        qFatal( "AbstractTable: row does not exists" );

    QVector<QVariant> vector( this->wight );
    for ( int i = 0; i < this->wight - 1; i++ )
        if ( this->table.contains( QPair<int, int>( i, y ) ) )
            vector.replace( i, this->table.value( Position( i, y ) ) );

    return vector;
}


