#ifndef ABSTRACTTABLE_H
#define ABSTRACTTABLE_H

#include <QVariant>
#include <QVector>
#include <QPair>
#include <QMap>

typedef QPair<int,int> Position;

template <typename T>
class AbstractTable
{
public:
    AbstractTable();
    virtual ~AbstractTable();

    void               setValue( int x, int y, const T& value );
    void               removeValue( int x, int y );
    void               clear();
    bool               isEmpty() const;
    virtual const T    getValue( int x, int y ) const;
    virtual QVector<T> getColumn( int x ) const;
    virtual QVector<T> getRow( int y ) const;

protected:
    QMap<Position,T> table;
    int              wight;
    int              hight;
};

template <typename T>
AbstractTable<T>::AbstractTable()
{
    this->wight = 0;
    this->hight = 0;
}

template <typename T>
AbstractTable<T>::~AbstractTable()
{
}

template <typename T>
void AbstractTable<T>::setValue( int x, int y, const T& value )
{
    if ( x > this->wight )
        this->wight = x;

    if ( y > this->hight )
        this->hight = y;

    this->table[Position( x, y )] = value;
}

template <typename T>
void AbstractTable<T>::removeValue( int x, int y )
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

template <typename T>
void AbstractTable<T>::clear()
{
    this->table.clear();
    this->wight = 0;
    this->wight = 0;
}

template <typename T>
bool AbstractTable<T>::isEmpty() const
{
    return this->table.isEmpty();
}

template <typename T>
const T AbstractTable<T>::getValue( int x, int y ) const
{
    return this->table[Position( x, y )];
}

template <typename T>
QVector<T> AbstractTable<T>::getColumn( int x ) const
{
    if ( x > this->wight )
        qFatal( "AbstractTable: column does not exists" );

    QVector<T> vector( this->hight );
    for ( int i = 0; i < this->hight - 1; i++ )
        if ( this->table.contains( Position( x, i ) ) )
            vector.replace( i, this->table.value( Position( x, i ) ) );

    return vector;
}

template <typename T>
QVector<T> AbstractTable<T>::getRow( int y ) const
{
    if ( y > this->hight )
        qFatal( "AbstractTable: row does not exists" );

    QVector<T> vector( this->wight );
    for ( int i = 0; i < this->wight - 1; i++ )
        if ( this->table.contains( QPair<int, int>( i, y ) ) )
            vector.replace( i, this->table.value( Position( i, y ) ) );

    return vector;
}

#endif /* ABSTRACTTABLE_H */
