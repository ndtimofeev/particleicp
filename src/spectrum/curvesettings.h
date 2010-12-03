#ifndef CURVESETTINGS_H
#define CURVESETTINGS_H

#include <QWizard>
#include <QWizardPage>
#include <QString>
#include <QVariant>
#include <QMap>

class CurveSettings : public QWizardPage
{
    Q_OBJECT

public:
    CurveSettings( const QString& str,
                   const QMap<QString,QVariant>& settings,
                   QWizard* parent = 0 );

    virtual ~CurveSettings();
};

#endif /* CURVESETTINGS_H */

