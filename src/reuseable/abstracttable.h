#ifndef ABSTRACTTABLE_H
#define ABSTRACTTABLE_H

#include <QVariant>
#include <QVector>
#include <QPair>
#include <QMap>

typedef QPair<int,int> Position;

class AbstractTable
{
public:
    AbstractTable();
    virtual ~AbstractTable();

    void                      setValue( int x, int y, const QVariant& value );
    void                      removeValue( int x, int y );
    void                      clear();
    bool                      isEmpty() const;
    virtual const QVariant    getValue( int x, int y ) const;
    virtual QVector<QVariant> getColumn( int x ) const;
    virtual QVector<QVariant> getRow( int y ) const;

protected:
    QMap<Position,QVariant> table;
    int                           wight;
    int                           hight;
};

#endif /* ABSTRACTTABLE_H */
