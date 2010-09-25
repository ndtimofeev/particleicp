#ifndef JYPARSER_H
#define JYPARSER_H

#include <QMap>
#include <QObject>
#include <QStringList>
#include <QTextStream>
#include <QVector>

class JYTable
{

public:
    JYTable( const QStringList& head );
    virtual ~JYTable();

    const QVector<qreal>* getColumn( const QString& name ) const;
    const QString&        getColumnName( int i ) const;
    int                   getSize() const;

    JYTable& operator<< ( const QStringList& list );
    JYTable& operator=  ( const JYTable& table );

private:
    int                    size;
    QStringList            head;
    QList<QVector<qreal>*> table;
};

class JYParser : public QObject
{
    Q_OBJECT

public:
    JYParser( QTextStream* stream, QObject* parent = 0 );
    virtual ~JYParser();

    const JYTable& getTable() const;

private:
//  void     parse( )
    JYTable* table;
};

#endif // JYPARSER_H
