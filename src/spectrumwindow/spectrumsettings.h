#ifndef SPECTRUMSETTINGS_H
#define SPECTRUMSETTINGS_H

#include <QAbstractButton>
#include <QMap>
#include <QWizardPage>
#include <QWizard>
#include <QVBoxLayout>
#include "spectrumwindow.h"

class SpectrumSettings : public QWizardPage
{
    Q_OBJECT

public:
    SpectrumSettings( const QMap<Spectrum::Settings,QVariant>& settings,
                      const QMap<Spectrum::Limits,QVariant>& limits,
                      QWizard* parent );

    virtual ~SpectrumSettings();

    void init();

private slots:
    void stateChanged( QAbstractButton* bt );

private:
    QWizard*                          parent;
    QMap<Spectrum::Settings,QVariant> settings;
};

#endif /* SPECTRUMSETTINGS_H */

