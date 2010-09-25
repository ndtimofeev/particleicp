#ifndef DLIST_H
#define DLIST_H

#include <QList>

template <class T> class DList<T*> : public QList<T*>
{
public:
            DList() {}
//            DList( const DList<T> & other );
//            DList( const QList<T> & other );
    virtual ~DList() { this->clear(); }

//       void append( const DList<T> & value );
       void clear() {
           if ( ! this->isEmpty )
           {
               int max = this->size() - 1;
               for ( int i = 0; i < max; i++ )
                   delete this[i];

               QList<T*>::clear();
           }
       }
//   iterator erase( iterator pos );
//   iterator erase( iterator begin, iterator end );
//       void pop_back();
//       void pop_front();
//        int removeAll( const T & value );
//       void removeAt( int i );
//       void removeFirst();
//       void removeLast();
//       bool removeOne( const T & value );
//       void replace( int i, const T & value );
//       void swap( int i, int j );
//          T takeAt( int i );
//          T takeFirst();
//          T takeLast();

};

#endif // DLIST_H
