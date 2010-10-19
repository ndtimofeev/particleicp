#ifndef JYPARSER_H
#define JYPARSER_H

#include <QTextStream>
#include <QString>
#include <QSet>
#include "jytable.h"

JYTable JYParser( const QSet<QString>& head, const QTextStream& stream );

#endif // JYPARSER_H
