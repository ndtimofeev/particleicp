#ifndef ROFSELECTOR_H
#define ROFSELECTOR_H

#include <QAction>
#include <QMenu>
#include <QString>
#include <QWidget>
#include "history.h"

class ROFSelector : public QMenu
{
    Q_OBJECT

signals:
    void fileSelected( QString path );

public:
    ROFSelector( QWidget* parent = 0 );
    virtual ~ROFSelector();

    int         max() const;
    QStringList saveState() const;
    void        restoreState( const QStringList& list );

public slots:
    void addFile( QString path );
    void clearHistory();
    void setMax( int num );

protected:
    History<QString>* history;

protected slots:
    void redrawMenu();
    void sendSignal( QAction* act );
};

#endif /* ROFSELECTOR_H */

