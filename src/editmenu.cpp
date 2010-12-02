#include <QDebug>
#include <QMdiSubWindow>
#include "editmenu.h"

EditMenu::EditMenu( QWidget* parent ) : DMenu( parent ), area_v( 0 )
{
}

EditMenu::EditMenu( QMdiArea* area, QWidget* parent ) :
    DMenu( parent ), area_v( area )
{
}

EditMenu::~EditMenu()
{
}

const QMdiArea* EditMenu::area() const
{
    return this->area_v.data();
}

void EditMenu::setArea( QMdiArea* area )
{
    this->area_v = area;
}

void EditMenu::redrawMenu()
{
    if ( this->area_v && this->area_v->activeSubWindow() )
        this->addActions( this->area_v->activeSubWindow()->widget()->actions() );
    else
        this->addAction( this->nullAction() );
}
