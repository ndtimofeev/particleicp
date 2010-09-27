#ifndef JYTABLE_H
#define JYTABLE_H

#include <QStringList>
#include "abstracttable.h"

class JYTable : public AbstractTable<qreal>
{
public:
    JYTable( const QStringList& head );
    virtual ~JYTable();

    virtual QVector<qreal> getColumn( const QString& name ) const;
    virtual QVector<qreal> getColumn( int i ) const;

    JYTable& operator<< ( const QStringList& list );
    JYTable& operator<< ( const QList<qreal>& list );

private:
    QStringList head;
};


#endif /* JYTABLE_H */

