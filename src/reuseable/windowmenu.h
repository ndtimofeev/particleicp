#ifndef WINDOWMENU_H
#define WINDOWMENU_H

#include <QActionGroup>
#include <QAction>
#include <QMdiSubWindow>
#include <QMap>
#include <QWidget>
#include <QMdiArea>
#include <QPointer>
#include "dmenu.h"

class WindowMenuPrivate;

class WindowMenu : public DMenu
{
    Q_OBJECT

public:
    WindowMenu( QWidget* parent = 0 );
    WindowMenu( QMdiArea* area, QWidget* parent = 0 );
    virtual ~WindowMenu();

    const QMdiArea* area() const;
    void            setArea( QMdiArea* area );

protected:
    WindowMenu( WindowMenuPrivate &d_ptr, QWidget* parent = 0 );

    virtual void redrawMenu();

    WindowMenuPrivate* windowmenu_ptr;

private:
    Q_DECLARE_PRIVATE_D(windowmenu_ptr,WindowMenu);
};

#endif /* WINDOWMENU_H */

