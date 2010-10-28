#ifndef WINDOWMENU_H
#define WINDOWMENU_H

#include <QWidget>
#include <QMdiArea>
#include <QPointer>
#include "dmenu.h"

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
    virtual void redrawMenu();

private:
    QPointer<QMdiArea> area_v;
};

#endif /* WINDOWMENU_H */

