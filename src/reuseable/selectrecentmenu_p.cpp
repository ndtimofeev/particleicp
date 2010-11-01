#include "selectrecentmenu_p.h"

SelectRecentMenuPrivate::SelectRecentMenuPrivate() :
    QObject(), history( new History<QString>(0) )
{
    this->group = new QActionGroup( this );
}

SelectRecentMenuPrivate::~SelectRecentMenuPrivate()
{
    delete this->history;
}

void SelectRecentMenuPrivate::init()
{
    Q_Q(SelectRecentMenu);
    connect( this->group, SIGNAL(triggered(QAction*)), this, SLOT(emitElementSelectedSignal(QAction*)));
    connect( this, SIGNAL(elementSelected_p(QString)), q, SIGNAL(elementSelected(QString)));
}

int SelectRecentMenuPrivate::max() const
{
    return this->history->length();
}

void SelectRecentMenuPrivate::setMax( int i )
{
    this->history->setLength( i );
}

QStringList SelectRecentMenuPrivate::saveState() const
{
    return this->history->mid(0);
}

void SelectRecentMenuPrivate::restoreState( const QStringList& list )
{
    *this->history = list;
}

void SelectRecentMenuPrivate::addElement( QString str )
{
    if ( str.isEmpty() )
        qFatal( "SelectRecentMenu: add null path" );

    this->history->push( str );
}

void SelectRecentMenuPrivate::removeAllElements()
{
    Q_Q(SelectRecentMenu);
    this->history->clear();
    q->updateMenu();
}

void SelectRecentMenuPrivate::redrawMenu()
{
    Q_Q(SelectRecentMenu);
    if ( this->history->isEmpty() )
        q->addAction( q->nullAction() );
    else
    {
        int i = 1;

        foreach( QString str, *this->history )
        {
            QAction* action = q->addAction(QString("&%1 %2").arg(i++).arg(str));
            action->setData( str );
            this->group->addAction( action );
        }

        q->addSeparator();
        q->addAction( tr("&Clear List"), q, SLOT( removeAllElements() ) );
    }
}

void SelectRecentMenuPrivate::emitElementSelectedSignal( QAction* act )
{
    if ( act )
        emit elementSelected_p( act->data().toString() );
}
