#ifndef PARSERSETTINGSDIALOG_H
#define PARSERSETTINGSDIALOG_H

#include <QDialog>
#include <QString>
#include <QWidget>
#include <QButtonGroup>
#include <QAbstractButton>
#include "settings.h"

class ParserSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    ParserSettingsDialog( const QString& path, QWidget* parent = 0 );
    virtual ~ParserSettingsDialog();

    static QStringList getSettings( const QString& path, QWidget* parent, Settings* settings = 0 );
    void               restoreState( const QStringList& list );
    QStringList        saveState() const;

protected:
    QButtonGroup*      group;
    QStringList*       list;
    const QStringList& getReturn() const;

protected slots:
    void stateCatcher( QAbstractButton* bt );
};

#endif /* PARSERSETTINGSDIALOG_H */

