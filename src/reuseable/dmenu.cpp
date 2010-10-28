#include "dmenu.h"
#include "dmenu_p.h"

DMenu::DMenu( QWidget* parent ) :
    QMenu( parent ), d_ptr( new DMenuPrivate )
{
    Q_D(DMenu);
    d->q_ptr = this;
    d->init();
}

DMenu::~DMenu()
{
    delete this->d_ptr;
}

QString DMenu::nullActionText() const
{
    Q_D(const DMenu);
    return d->nullActionText();
}

void DMenu::setNullActionText( const QString& str )
{
    Q_D(DMenu);
    d->setNullActionText( str );
}

QAction* DMenu::nullAction() const
{
    Q_D(const DMenu);
    return d->nullAction();
}

DMenu::DMenu( DMenuPrivate &pimpl, QWidget* parent ) :
    QMenu( parent ), d_ptr( &pimpl )
{
    Q_D(DMenu);
    d->q_ptr = this;
    d->init();
}

void DMenu::removeAllActions()
{
    Q_D(DMenu);
    d->removeAllActions();
}

void DMenu::redrawMenu()
{
    Q_D(DMenu);
    d->redrawMenu();
}