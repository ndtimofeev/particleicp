#include "windowmenu_p.h"
#include <QDebug>

WindowMenuPrivate::WindowMenuPrivate( QMdiArea* area ) : QObject(), area_v( area )
{
}

WindowMenuPrivate::~WindowMenuPrivate()
{
}

void WindowMenuPrivate::init()
{
    this->group = new QActionGroup( this );
    this->group->setExclusive( true );
}

const QMdiArea* WindowMenuPrivate::area() const
{
    return this->area_v.data();
}

void WindowMenuPrivate::setArea( QMdiArea* area )
{
    this->area_v = area;
}

void WindowMenuPrivate::redrawMenu()
{
    Q_Q(WindowMenu);
    if ( this->area_v && this->area_v->currentSubWindow() )
    {
        q->addAction(tr("&Close"), this->area_v, SLOT(closeActiveSubWindow()), QKeySequence::Close);
        if ( this->area_v->subWindowList().size() > 1 )
            q->addAction(tr("Close &All"), this->area_v, SLOT(closeAllSubWindows()));

        q->addSeparator();

        q->addAction(tr("&Tile"), this->area_v, SLOT(tileSubWindows()));
        q->addAction(tr("Ca&scade"), this->area_v, SLOT(cascadeSubWindows()));

        if ( this->area_v->subWindowList().size() > 1 )
        {
            q->addSeparator();

            q->addAction(tr("&Next"), this->area_v, SLOT(activateNextSubWindow()));
            q->addAction(tr("&Previous"), this->area_v, SLOT(activatePreviousSubWindow()));

            foreach( QMdiSubWindow* ptr, this->area_v->subWindowList() )
            {
                QAction* act = q->addAction( ptr->widget()->windowTitle() );
                act->setCheckable( true );
                this->group->addAction( act );
                act->setChecked( ptr == this->area_v->activeSubWindow() );
                this->window_list[act] = ptr;
            }

            connect(this->group, SIGNAL(triggered(QAction*)), this, SLOT(windowSelectCatcher(QAction*)));
        }
    }
    else
        q->addAction( q->nullAction() );
}

void WindowMenuPrivate::windowSelectCatcher( QAction* act )
{
    if ( act && this->area_v )
        this->area_v->setActiveSubWindow( this->window_list.value( act ) );
}

