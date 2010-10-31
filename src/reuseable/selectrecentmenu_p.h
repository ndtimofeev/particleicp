#ifndef SELECTRECENTMENU_P_H
#define SELECTRECENTMENU_P_H

#include <QActionGroup>
#include "selectrecentmenu.h"
#include "history.h"

class SelectRecentMenuPrivate
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(SelectRecentMenu)

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

};

#endif /* SELECTRECENTMENU_P_H */

