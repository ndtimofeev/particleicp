#ifndef JYPARSER_H
#define JYPARSER_H

#include <QTextStream>
#include <QString>
#include <QSet>
#include "vectortable.h"

VectorTable JYParser( const QSet<QString>& head, QTextStream& stream );

#endif // JYPARSER_H
