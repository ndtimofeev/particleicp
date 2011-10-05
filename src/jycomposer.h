#ifndef JYCOMPOSER_H
#define JYCOMPOSER_H

#include <QStringList>
#include <QTextStream>
#include "vectortable.h"

void JYComposer( const VectorTable* table, QTextStream &stream,
                                const QStringList& columns = QStringList() );

#endif /* JYCOMPOSER_H */

