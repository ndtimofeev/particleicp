#ifndef FALGORITHMS_H
#define FALGORITHMS_H

#include <stdexcept>

namespace fp
{
    template <typename T, class iterator>
    inline bool elem( const T& value, iterator first, iterator last )
    {
        for ( iterator i = first; i != last; i++ )
            if ( *i == value )
                return true;

        return false;
    }

    template <typename T, template <typename> class C>
    inline bool elem( const T& value, const C<T>& list )
    {
        return elem( value, list.begin(), list.end() );
    }

    template <typename T, class iterator>
    T uniq( iterator first, iterator last, const T& )
    {
        T null;
        for ( iterator i = first; i != last; i++ )
            if ( ! elem( *i, first, i ) )
                null << *i;

        return null;
    }

    template <typename T>
    T uniq( const T& list )
    {
        return uniq( list.begin(), list.end(), list );
    }

    template <typename T, class iterator>
    T take( int length, iterator first, iterator last, const T& )
    {
        T n_list;
        while ( first != last && length > 0 )
        {
            n_list << *first;
            first++;
            length--;
        }

        return n_list;
    }

    template <typename T>
    T take( int length, const T& list )
    {
        return take( length, list.begin(), list.end(), list );
    }

    template <class iterator>
    iterator maximum( iterator first, iterator last )
    {
        iterator max = first;
        for ( iterator i = first; i != last; i++ )
            if ( *max < *i )
                max = i;

        return max;
    }

    template <typename T, template <typename> class C>
    T maximum( const C<T>& list )
    {
        return *maximum( list.begin(), list.end() );
    }

    template <class iterator>
    iterator index( iterator first, iterator last, int i )
    {
        iterator index = first;
        while ( i-- != 0 && index++ != last )
            ;

        return index;
    }

    template <typename T, template <typename> class C>
    T index( const C<T>& list, int i )
    {
        if ( list.size() - 1 < i )
            throw std::invalid_argument( "index: bad index" );

        return *index( list.begin(), list.end(), i );
    }

    template <typename T, class iterator, class iterator1>
    T rebuild( iterator first, iterator last, iterator1 first1, iterator1 last1, const T& )
    {
        T value;
        for ( iterator1 i = first1; i != last1; i++ )
            value << *index( first, last, *i );

        return value;
    }

    template <typename T, template <typename> class C>
    T rebuild( const T& list, const C<int>& ilist )
    {
        if ( list.size() < maximum( ilist ) )
            throw std::invalid_argument( "rebuild: bad index" );

        return rebuild( list.begin(), list.end(), ilist.begin(), ilist.end(), list );
    }
}

#endif /* FALGORITHMS_H */
