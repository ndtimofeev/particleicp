#include <QDebug>
#include "dmenu_p.h"

DMenuPrivate::DMenuPrivate() : nullText( "empty" )
{
}

DMenuPrivate::~DMenuPrivate()
{
    delete this->nullAction_ptr;
}

void DMenuPrivate::init()
{
    Q_Q(DMenu);
    q->connect( q, SIGNAL( aboutToShow() ), q, SLOT( updateMenu() ) );
    this->nullAction_ptr = new QAction( nullText, q );
    this->nullAction_ptr->setEnabled( false );
}

void DMenuPrivate::redrawMenu()
{
    Q_Q(DMenu);
    q->addAction( this->nullAction_ptr );
}

QString DMenuPrivate::nullActionText() const
{
    return this->nullText;
}

void DMenuPrivate::setNullActionText( const QString& str )
{
    this->nullText = str;
}

QAction* DMenuPrivate::nullAction() const
{
    return this->nullAction_ptr;
}

void DMenuPrivate::updateMenu()
{
    Q_Q(DMenu);

    if ( q->actions().contains( this->nullAction_ptr ) )
        q->removeAction( this->nullAction_ptr );

    q->clear();
    q->redrawMenu();
}
