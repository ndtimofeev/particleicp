#include "settings.h"

Settings* Settings::instance_value = 0;

Settings::Settings() : QSettings()
{
}

Settings::~Settings()
{
}

Settings* Settings::instance()
{
    static QMutex mutex;
    if ( ! instance_value )
    {
        mutex.lock();

        if ( ! instance_value )
            instance_value = new Settings();

        mutex.unlock();
    }

    return instance_value;
}
