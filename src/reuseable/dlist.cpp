/*

#include "dlist.h"

Dlist<T>::Dlist<T>() : public QList<T>()
{}

Dlist::~Dlist()
{
    this->clear();
}

void DList::clear()
{
    int max = this->size() - 1;
    for ( int i = 0; i < max; i++ )
        delete this[i];

    QList::clear();
}

*/
