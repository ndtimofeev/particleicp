#ifndef FALGORITHMS_H
#define FALGORITHMS_H

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
}

#endif /* FALGORITHMS_H */
