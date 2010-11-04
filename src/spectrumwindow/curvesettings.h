#ifndef CURVESETTINGS_H
#define CURVESETTINGS_H

#include <QWizard>
#include <QWizardPage>

class CurveSettings : public QWizardPage
{
    Q_OBJECT

public:
    CurveSettings( const QString& str, QWizard* parent );
    virtual ~CurveSettings();
};


#endif /* CURVESETTINGS_H */

