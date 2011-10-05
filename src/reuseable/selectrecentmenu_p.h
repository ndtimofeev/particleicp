#ifndef SELECTRECENTMENU_P_H
#define SELECTRECENTMENU_P_H

#include <QActionGroup>
#include "selectrecentmenu.h"
#include "history.h"

class SelectRecentMenuPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(SelectRecentMenu)

signals:
    void elementSelected_p( QString str );

public:
    SelectRecentMenuPrivate();
    ~SelectRecentMenuPrivate();

    int         max() const;
    void        setMax( int i );
    QStringList saveState() const;
    void        restoreState( const QStringList& list );
    void        addElement( QString str );
    void        removeAllElements();
    void        redrawMenu();
    void        init();

    int               max_v;
    History<QString>* history;
    QActionGroup*     group;

    SelectRecentMenu* q_ptr;

public slots:
    void emitElementSelectedSignal( QAction* act );

};

#endif /* SELECTRECENTMENU_P_H */

