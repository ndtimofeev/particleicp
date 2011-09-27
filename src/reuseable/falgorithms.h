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
    inline void uniq( iterator first, iterator last, T& list )
    {
        for ( iterator i = first; i != last; i++ )
            if ( ! elem( *i, first, i ) )
                list << *i;
    }

    template <typename T>
    inline T uniq( const T& list )
    {
        T result;
        uniq( list.begin(), list.end(), result );
        return result;
    }

    template <typename T, class iterator>
    inline void tail( iterator first, iterator last, T& result )
    {
        for ( iterator i = first + 1; i != last; i++ )
            result << *i;
    }

    template <typename T>
    inline T tail( const T& list )
    {
        T result;
        tail( list.begin(), list.end(), result );

        return result;
    }

    template <typename T, class iterator>
    inline void take( int length, iterator first, iterator last, T& result )
    {
        while ( first != last && length > 0 )
        {
            result << *first;
            first++;
            length--;
        }
    }

    template <typename T>
    inline T take( int length, const T& list )
    {
        T result;
        take( length, list.begin(), list.end(), result );

        return result;
    }

    template <class iterator>
    inline iterator maximum( iterator first, iterator last )
    {
        iterator max = first;
        for ( iterator i = first; i != last; i++ )
            if ( *max < *i )
                max = i;

        return max;
    }

    template <typename T, template <typename> class C>
    inline T maximum( const C<T>& list )
    {
        return *maximum( list.begin(), list.end() );
    }

    template <class iterator>
    inline iterator index( iterator first, iterator last, int i )
    {
        if ( last - first < i || i < 0 )
            throw std::invalid_argument( "index: bad index" );

        return first + i;
    }

    template <typename T, template <typename> class C>
    inline T index( const C<T>& list, int i )
    {
        if ( list.size() - 1 < i || i < 0 )
            throw std::invalid_argument( "index: bad index" );

        return *(list.begin() + i);
    }

    template <typename T, class iterator, class iterator1>
    inline void rebuild( iterator first, iterator last, iterator1 first1, iterator1 last1, T& value )
    {
        for ( iterator1 i = first1; i != last1; i++ )
            value << *index( first, last, *i );
    }

    template <typename T, template <typename> class C>
    inline T rebuild( const T& list, const C<int>& ilist )
    {
        if ( list.size() < maximum( ilist ) )
            throw std::invalid_argument( "rebuild: bad index" );

        T result;
        rebuild( list.begin(), list.end(), ilist.begin(), ilist.end(), result );
        return result;
    }
}

#endif /* FALGORITHMS_H */
