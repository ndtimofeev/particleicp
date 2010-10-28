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
    q->connect( q, SIGNAL( aboutToShow() ), q, SLOT( redrawMenu() ) );
    this->nullAction_ptr = new QAction( nullText, q );
    this->nullAction_ptr->setEnabled( false );
}

void DMenuPrivate::redrawMenu()
{
    Q_Q(DMenu);
    q->removeAllActions();
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

void DMenuPrivate::removeAllActions()
{
    Q_Q(DMenu);
    foreach( QAction* ptr, q->actions() )
        q->removeAction( ptr );
}
