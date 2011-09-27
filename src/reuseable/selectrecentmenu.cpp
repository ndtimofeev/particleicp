#include "selectrecentmenu.h"
#include "selectrecentmenu_p.h"

SelectRecentMenu::SelectRecentMenu( QWidget* parent ) :
    DMenu( parent ), selectrecentmenu( new SelectRecentMenuPrivate )
{
    Q_D(SelectRecentMenu);
    d->q_ptr = this;
    d->init();
}

SelectRecentMenu::SelectRecentMenu( SelectRecentMenuPrivate &d_ptr, QWidget* parent ) :
    DMenu( parent ), selectrecentmenu( &d_ptr )
{
    Q_D(SelectRecentMenu);
    d->q_ptr = this;
    d->init();
}

SelectRecentMenu::~SelectRecentMenu()
{
    delete this->selectrecentmenu;
}

int SelectRecentMenu::max() const
{
    Q_D(const SelectRecentMenu);
    return d->max();
}

void SelectRecentMenu::setMax( int i )
{
    Q_D(SelectRecentMenu);
    d->setMax( i );
}

QStringList SelectRecentMenu::saveState() const
{
    Q_D(const SelectRecentMenu);
    return d->saveState();
}

void SelectRecentMenu::restoreState( const QStringList& list )
{
    Q_D(SelectRecentMenu);
    d->restoreState( list );
}

void SelectRecentMenu::addElement( QString str )
{
    Q_D(SelectRecentMenu);
    d->addElement( str );
}

void SelectRecentMenu::removeAllElements()
{
    Q_D(SelectRecentMenu);
    d->removeAllElements();
}

void SelectRecentMenu::redrawMenu()
{
    Q_D(SelectRecentMenu);
    d->redrawMenu();
}

