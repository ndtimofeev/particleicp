#include <qswlwindowmenu.h>
#include <qswlwindowmenuprivate.h>

QswlWindowMenu::QswlWindowMenu( QWidget* parent ) :
    QMenu( parent ), d_ptr( *new QswlWindowMenuPrivate )
{
}

QswlWindowMenu::~QswlWindowMenu()
{
}

QswlWindowMenu::QswlWindowMenu( QswlWindowMenuPrivate &d, QWidget* parent ) :
    QMenu( parent ), d_ptr( &d )
{
}
