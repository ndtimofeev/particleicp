#ifndef SPECTRUMSETTINGSWIZARD_H
#define SPECTRUMSETTINGSWIZARD_H

#include <QtGui>

class SpectrumSettingsWizard : public QWizard
{
    Q_OBJECT

public:
    SpectrumSettingsWizard( const QMap<QString,QVariant>& settings,
                            const QMap<QString,QVariant>& limits,
                            QWidget* parent );

    virtual ~SpectrumSettingsWizard();

    static QMap<QString,QVariant>
    getSpectrumSettings( const QMap<QString,QVariant>& settings,
                         const QMap<QString,QVariant>& limits,
                         QWidget* parent );

    QMap<QString,QVariant> getState() const;

private slots:
    void wizardEdit( const QString& pageName );
    void saveState();

private:
    int  getPageId( const QString& str ) const;
    void deletePage( int id );

    QStringList            pages;
    QMap<QString,QVariant> settings;
};

#endif /* SPECTRUMSETTINGSWIZARD_H */

