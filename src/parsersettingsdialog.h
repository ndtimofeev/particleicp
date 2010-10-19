#ifndef PARSERSETTINGSDIALOG_H
#define PARSERSETTINGSDIALOG_H

#include <QDialog>
#include <QString>
#include <QWidget>
#include <QButtonGroup>
#include <QAbstractButton>
#include "settings.h"
#include <QTextStream>

class ParserSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    ParserSettingsDialog( const QTextStream& stream, QWidget* parent = 0 );
    virtual ~ParserSettingsDialog();

    static QSet<QString> getSettings( QTextStream& stream, const QString& path, QWidget* parent, Settings* settings = 0 );
    void                 restoreState( const QSet<QString>& list );
    const QSet<QString>& getState() const;

protected:
    QButtonGroup*        group;
    QSet<QString>*       list;

protected slots:
    void stateCatcher( QAbstractButton* bt );
};

#endif /* PARSERSETTINGSDIALOG_H */

