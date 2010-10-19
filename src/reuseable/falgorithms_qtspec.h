#ifndef FALGORITHMS_QTSPEC_H
#define FALGORITHMS_QTSPEC_H

#include <QStringList>
#include <QString>

namespace fp {

//    template <>
    inline bool elem( const QString& str, const QStringList& list )
    {
        return elem( str, list.begin(), list.end() );
    }
}

#endif /* FALGORITHMS_QTSPEC_H */

