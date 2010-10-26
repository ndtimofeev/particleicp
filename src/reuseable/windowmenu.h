#ifndef WINDOWMENU_H
#define WINDOWMENU_H

#include <QWidget>
#include <QMenu>
#include <QMdiArea>
#include <QPointer>

class WindowMenu : public QMenu
{
    Q_OBJECT

public:
    WindowMenu( QWidget* parent = 0 );
    WindowMenu( QMdiArea* area, QWidget* parent = 0 );
    virtual ~WindowMenu();

    const QMdiArea* area() const;
    void            setArea( QMdiArea* area );

protected:
    void init();

private:
    QPointer<QMdiArea> area_v;
};

#endif /* WINDOWMENU_H */

