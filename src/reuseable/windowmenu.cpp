#include <QAction>
#include "windowmenu.h"

WindowMenu::WindowMenu( QWidget* parent ) :
    QMenu( parent ), area_v( 0 )
{
    this->init();
}

WindowMenu::WindowMenu( QMdiArea* area, QWidget* parent ) :
    QMenu( parent ), area_v( area )
{
    this->init();
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

void WindowMenu::init()
{
    this->addAction( tr("&Close") );
    this->addAction( tr("C&lose All") );
    this->addSeparator();
    this->addAction( tr("&Tile") );
    this->addAction( tr("C&ascade") );
    this->addSeparator();
    this->addAction( tr("&Next") );
    this->addAction( tr("&Previous") );
}
