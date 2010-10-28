#include <QAction>
#include <QMdiSubWindow>
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

void WindowMenu::redrawMenu()
{
    this->removeAllActions();
    if ( this->area_v && this->area_v->currentSubWindow() )
        this->addAction( "shaded", this->area_v->currentSubWindow(), SLOT( showShaded() ) );
    else
        this->addAction( this->nullAction() );
}
