#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QMutex>

class Settings : public QSettings
{
public:
    static Settings* instance();

private:
    Settings();
    Settings( const Settings& );
    Settings& operator = ( const Settings& );
    virtual ~Settings();

    static Settings* instance_value;
};

#endif /* SETTINGS_H */

