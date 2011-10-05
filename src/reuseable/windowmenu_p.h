#ifndef WINDOWMENU_P_H
#define WINDOWMENU_P_H

#include "windowmenu.h"

class WindowMenuPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(WindowMenu)

public:
    WindowMenuPrivate( QMdiArea* area = 0 );
    ~WindowMenuPrivate();

    const QMdiArea* area() const;
    void            setArea( QMdiArea* area );
    void            redrawMenu();
    void            init();

    QPointer<QMdiArea>            area_v;
    QActionGroup*                 group;
    QMap<QAction*,QMdiSubWindow*> window_list;
    WindowMenu*                   q_ptr;
public slots:
    void windowSelectCatcher( QAction* act );
};

#endif /* WINDOWMENU_P_H */

