#ifndef VECTORTABLE_H
#define VECTORTABLE_H

#include <QVector>
#include <QStringList>
#include <QString>
#include <QMap>

class VectorTable
{
public:
    VectorTable( const QStringList& tags  );
    VectorTable( const VectorTable& table );
    virtual ~VectorTable();

    int                    getWidth() const;
    int                    getHeight() const;
    QVector<double>        getRow( int i ) const;
    const QVector<double>* getColumn( const QString& str ) const;
    const QStringList&     getTags() const;
    void                   addRow( const QStringList& row );

    VectorTable& operator = ( const VectorTable& table );
    VectorTable& operator << ( const QStringList& table );

private:
    int                            width;
    int                            height;
    QMap<QString,QVector<double>*> table;
    QStringList                    tags;
};

#endif /* VECTORTABLE_H */

