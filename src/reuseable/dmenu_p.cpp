#include "dmenu_p.h"

DMenuPrivate::DMenuPrivate() : QObject()
{
    Q_Q(DMenu);
    connect( q, SIGNAL( aboutToShow() ), q, SLOT( redrawMenu() ) );
}

DMenuPrivate::~DMenuPrivate()
{
}

void DMenuPrivate::redrawMenu()
{
}
