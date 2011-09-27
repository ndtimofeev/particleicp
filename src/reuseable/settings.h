#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QString>
#include <QMutex>

class Settings : public QSettings
{
public:
    static Settings* init( const QString& organization, const QString& application );
    static Settings* instance();

private:
    Settings( const QString& organization, const QString& application );
    Settings( const Settings& );
    Settings& operator = ( const Settings& );
    virtual ~Settings();

    static Settings* instance_value;
};

#endif /* SETTINGS_H */

