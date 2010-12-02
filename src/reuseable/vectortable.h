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
    virtual VectorTable    mid( int pos, int length = -1 ) const;
    virtual void           addRow( const QStringList& row );
    virtual void           addRow( const QVector<double>& row );

    VectorTable& operator = ( const VectorTable& table );
    VectorTable& operator << ( const QStringList& table );
    VectorTable& operator << ( const QVector<double>& table );


private:
    int                            width;
    int                            height;
    QMap<QString,QVector<double>*> table;
    QStringList                    tags;
};

#endif /* VECTORTABLE_H */

