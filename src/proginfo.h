#ifndef PROGINFO_H
#define PROGINFO_H

#include <cstdlib>

class ProgInfo
{
public:
    static ProgInfo* instance();

    void* operator new( size_t size );

private:
    ProgInfo();
    virtual ~ProgInfo();
};

#endif /* PROGINFO_H */

