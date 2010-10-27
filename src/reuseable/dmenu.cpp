#include "dmenu.h"
#include "dmenu_p.h"

DMenu::DMenu( QWidget* parent ) :
    QMenu( parent ), d_ptr( new DMenuPrivate )
{
}

DMenu::~DMenu()
{
    delete this->d_ptr;
}

DMenu::DMenu( DMenuPrivate &d, QWidget* parent ) :
    QMenu( parent ), d_ptr( &d )
{
}

void DMenu::redrawMenu()
{
    Q_D(DMenu);
    d->redrawMenu();
}
