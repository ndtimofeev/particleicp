#include "settings.h"

Settings* Settings::instance_value = 0;

Settings::Settings( const QString& organization, const QString& application ) :
    QSettings( organization, application )
{
}

Settings::~Settings()
{
}

Settings* Settings::init( const QString& organization, const QString& application )
{
    static QMutex mutex;

    if ( instance_value )
        qFatal( "Settings: settings already inited" );
    else
    {
        mutex.lock();

        if ( instance_value )
            qFatal( "Settings: settings already inited" );

        static Settings obj( organization, application );
        instance_value = &obj;

        mutex.unlock();
    }

    return instance_value;
}

Settings* Settings::instance()
{
    if ( ! instance_value )
        qFatal( "Settings: settings not yet inited" );

    return instance_value;
}
