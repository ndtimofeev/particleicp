#include <QAction>
#include "windowmenu.h"

WindowMenu::WindowMenu( QWidget* parent ) :
    DMenu( parent ), area_v( 0 )
{
}

WindowMenu::WindowMenu( QMdiArea* area, QWidget* parent ) :
    DMenu( parent ), area_v( area )
{
}

WindowMenu::~WindowMenu()
{
}

const QMdiArea* WindowMenu::area() const
{
    return this->area_v.data();
}

void WindowMenu::setArea( QMdiArea* area )
{
    this->area_v = area;
}

