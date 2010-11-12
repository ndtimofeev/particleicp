#ifndef SPECTRUMSETTINGSWIZARD_H
#define SPECTRUMSETTINGSWIZARD_H

#include <QStringList>
#include <QString>
#include <QWizard>
#include <QWidget>
#include <QVariant>
#include "spectrumwindow.h"

class SpectrumSettingsWizard : public QWizard
{
    Q_OBJECT

public:
    SpectrumSettingsWizard( const QMap<Spectrum::Settings,QVariant>& settings,
                            const QMap<Spectrum::Limits,QVariant>& limits,
                            QWidget* parent );

    virtual ~SpectrumSettingsWizard();

private slots:
    void wizardEdit( const QString& pageName, bool state );

private:
    int  getPageId( const QString& str ) const;
    void deletePage( int id );

    QStringList            pages;
    QMap<QString,QVariant> curves;
};

#endif /* SPECTRUMSETTINGSWIZARD_H */

