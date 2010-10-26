#include "dmenu.h"
#include "dmenu_p.h"

DMenu::DMenu( QWidget* parent ) :
    QMenu( parent ), d_ptr( new DMenuPrivate )
{
}

DMenu::~DMenu()
{
}

DMenu::DMenu( DMenuPrivate &d, QWidget* parent ) :
    QMenu( parent ), d_ptr( &d )
{
}
