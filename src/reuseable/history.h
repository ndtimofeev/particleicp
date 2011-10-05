#ifndef HISTORY_H
#define HISTORY_H

#include <QList>
#include "falgorithms.h"

template <typename T>
class History : public QList<T>
{
public:
    History( int length = 0 );
    History( const QList<T>& list, int length = 0 );
    virtual ~History();

    int  length() const;
    void setLength( int length );
    void push( const T& value );

//    History<T>  mid( int pos, int length = -1 ) const;

private:
    int  length_v;
};

template <typename T>
History<T>::History( int length ) : QList<T>()
{
    this->length_v = length;
}

template <typename T>
History<T>::History( const QList<T>& list, int length ) : QList<T>( list )
{
    this->length_v = length;
    *this = fp::uniq( *this );
}

template <typename T>
History<T>::~History()
{
}

template <typename T>
int History<T>::length() const
{
    return this->length_v;
}

template <typename T>
void History<T>::setLength( int length )
{
    this->length_v = length;
}

template <typename T>
void History<T>::push( const T& value )
{
    if ( this->length_v > 0 )
    {
        if ( ! this->isEmpty() )
        {
            if ( fp::elem( value, *this ) )
                this->removeAll( value );
        }
        this->prepend( value );
        if ( this->size() > this->length_v )
           *this = fp::take( this->length_v, *this );
    }
}

/*
template <typename T>
History<T> History<T>::mid( int pos, int length ) const
{
    return History<T>( this->mid( pos, length ), this->length_v );
}
*/

#endif /* HISTORY_H */

