#ifndef SPECTRUMSETTINGSWIZARD_H
#define SPECTRUMSETTINGSWIZARD_H

#include <QStringList>
#include <QString>
#include <QWizard>
#include <QWidget>
#include <QVariant>

class SpectrumSettingsWizard : public QWizard
{
    Q_OBJECT

public:
    SpectrumSettingsWizard( const QMap<QString,QVariant>& settings,
                            const QMap<QString,QVariant>& limits,
                            QWidget* parent );

    virtual ~SpectrumSettingsWizard();

private slots:
    void wizardEdit( const QString& pageName, bool state );

private:
    int  getPageId( const QString& str ) const;
    void deletePage( int id );

    QStringList            pages;
    QMap<QString,QVariant> settings;
};

#endif /* SPECTRUMSETTINGSWIZARD_H */

