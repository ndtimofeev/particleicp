#include <QAction>
#include <QMdiSubWindow>
#include "windowmenu.h"

WindowMenu::WindowMenu( QWidget* parent ) :
    DMenu( parent ), area_v( 0 )
{
    this->group = new QActionGroup( this );
    this->group->setExclusive( true );
}

WindowMenu::WindowMenu( QMdiArea* area, QWidget* parent ) :
    DMenu( parent ), area_v( area )
{
    this->group = new QActionGroup( this );
    this->group->setExclusive( true );
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

void WindowMenu::redrawMenu()
{
    if ( this->area_v && this->area_v->currentSubWindow() )
    {
        this->addAction(tr("&Close"), this->area_v, SLOT(closeActiveSubWindow()), QKeySequence::Close);
        if ( this->area_v->subWindowList().size() > 1 )
            this->addAction(tr("Close &All"), this->area_v, SLOT(closeAllSubWindows()));
        this->addSeparator();
        this->addAction(tr("&Tile"), this->area_v, SLOT(tileSubWindows()));
        this->addAction(tr("Ca&scade"), this->area_v, SLOT(cascadeSubWindows()));
        if ( this->area_v->subWindowList().size() > 1 )
        {
            this->addSeparator();
            this->addAction(tr("&Next"), this->area_v, SLOT(activateNextSubWindow()));
            this->addAction(tr("&Previous"), this->area_v, SLOT(activatePreviousSubWindow()));
            foreach( QMdiSubWindow* ptr, this->area_v->subWindowList() )
            {
                QAction* act = this->addAction( ptr->widget()->windowTitle() );
                this->group->addAction( act );
                if ( ptr == this->area_v->activeSubWindow() )
                    act->setChecked( true );
            }

        }
    }
    else
        this->addAction( this->nullAction() );
}
