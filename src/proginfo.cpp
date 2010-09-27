#include "proginfo.h"

ProgInfo* ProgInfo::instance()
{
    static ProgInfo object;
    return &object;
}

ProgInfo::ProgInfo()
{
}

ProgInfo::~ProgInfo()
{
}

void* ProgInfo::operator new( size_t size )
{
    return ProgInfo::instance();
}
