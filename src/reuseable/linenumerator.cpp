#include "linenumerator.h"

LineNumerator::LineNumerator() : line_number( 0 )
{
}

LineNumerator::~LineNumerator()
{
}

QString LineNumerator::getLine( const QString& str )
{
    this->line_number++;
    return QString( "&%1 &2" ).arg(line_number).arg( str );
}
