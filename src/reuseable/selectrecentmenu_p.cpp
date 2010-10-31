#include "selectrecentmenu_p.h"

SelectRecentMenuPrivate::SelectRecentMenuPrivate() :
    history( new History<QString>(0) )
{
}

SelectRecentMenuPrivate::~SelectRecentMenuPrivate()
{
    delete this->history;
}

void SelectRecentMenuPrivate::init()
{
    Q_Q(SelectRecentMenu);
    this->group = new QActionGroup( q );
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
            this->group->addAction(QString("&%1 %2").arg(i++).arg(str))->setData( str );

        q->addActions( this->group->actions() );
        q->addSeparator();
        q->addAction( QObject::tr("&Clear List"), q, SLOT( clearHistory() ) );
    }
}

