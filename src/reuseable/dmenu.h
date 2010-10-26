#ifndef DMENU_H
#define DMENU_H

#include <QMenu>
#include <QWidget>

class DMenuPrivate;

class DMenu : public QMenu
{
    Q_OBJECT
public:
    DMenu( QWidget* parent = 0 );
    virtual ~DMenu();

protected:
    DMenu( DMenuPrivate &d, QWidget* parent = 0 );

    DMenuPrivate* d_ptr;

private:
    Q_DECLARE_PRIVATE(DMenu)
};

#endif /* DMENU_H */
