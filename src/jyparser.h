#ifndef JYPARSER_H
#define JYPARSER_H

#include <QMap>
#include <QObject>
#include <QStringList>
#include <QTextStream>
#include <QVector>
#include "jytable.h"

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
