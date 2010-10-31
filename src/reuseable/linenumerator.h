#ifndef LINENUMERATOR_H
#define LINENUMERATOR_H

#include <QString>

class LineNumerator
{
public:
    LineNumerator();
    virtual ~LineNumerator();

    QString getLine( const QString& str );

private:
    LineNumerator( const LineNumerator& val );
    LineNumerator& operator = ( const LineNumerator& val );

    int line_number;
};

#endif /* LINENUMERATOR_H */

