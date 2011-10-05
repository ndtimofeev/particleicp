#ifndef SPECTRUMSETTINGS_H
#define SPECTRUMSETTINGS_H

#include <QAbstractButton>
#include <QMap>
#include <QWizardPage>
#include <QWizard>
#include <QVBoxLayout>
#include <QAbstractButton>
#include "spectrumwindow.h"

class SpectrumSettings : public QWizardPage
{
    Q_OBJECT

signals:
    void pageStateChanged( QString pageName );

public:
    SpectrumSettings( const QMap<QString,QVariant>& settings,
                      const QMap<QString,QVariant>& limits,
                      QWizard* parent );

    virtual ~SpectrumSettings();

    void init();

private slots:
    void stateChanged( QAbstractButton* bt );

private:
    QMap<QString,QVariant> settings;
};

#endif /* SPECTRUMSETTINGS_H */

