#include <QDebug>
#include "dmenu_p.h"

DMenuPrivate::DMenuPrivate() : nullText( "empty" )
{
}

DMenuPrivate::~DMenuPrivate()
{
    delete this->nullAction;
}

void DMenuPrivate::init()
{
    Q_Q(DMenu);
    q->connect( q, SIGNAL( aboutToShow() ), q, SLOT( redrawMenu() ) );
    this->nullAction = new QAction( nullText, q );
    this->nullAction->setEnabled( false );
}

void DMenuPrivate::redrawMenu()
{
    Q_Q(DMenu);
    q->addAction( this->nullAction );
}

QString DMenuPrivate::nullActionText() const
{
    return this->nullText;
}

void DMenuPrivate::setNullActionText( const QString& str )
{
    this->nullText = str;
}
