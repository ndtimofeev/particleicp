#include "windowmenu.h"
#include "windowmenu_p.h"

WindowMenu::WindowMenu( QWidget* parent ) :
    DMenu( parent ), windowmenu_ptr( new WindowMenuPrivate )
{
    Q_D(WindowMenu);
    d->q_ptr = this;
    d->init();
}

WindowMenu::WindowMenu( QMdiArea* area, QWidget* parent ) :
    DMenu( parent ), windowmenu_ptr( new WindowMenuPrivate( area ) )
{
    Q_D(WindowMenu);
    d->q_ptr = this;
    d->init();
}

WindowMenu::WindowMenu( WindowMenuPrivate &d_ptr, QWidget* parent ) :
    DMenu( parent ), windowmenu_ptr( &d_ptr )
{
    Q_D(WindowMenu);
    d->q_ptr = this;
    d->init();
}

WindowMenu::~WindowMenu()
{
    delete this->windowmenu_ptr;
}

const QMdiArea* WindowMenu::area() const
{
    Q_D(const WindowMenu);
    return d->area();
}

void WindowMenu::setArea( QMdiArea* area )
{
    Q_D(WindowMenu);
    d->setArea( area );
}

void WindowMenu::redrawMenu()
{
    Q_D(WindowMenu);
    d->redrawMenu();
}

