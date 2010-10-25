#ifndef QSWLWINDOWMENU_H
#define QSWLWINDOWMENU_H

#include <QWidget>
#include <QMenu>

class QswlWindowMenuPrivate;

class QswlWindowMenu : public QMenu
{
    Q_OBJECT
public:
    QswlWindowMenu( QWidget* parent = 0 );
    virtual ~QswlWindowMenu();

protected:
    QswlWindowMenu( QswlWindowMenuPrivate &d, QWidget* parent = 0 );

    const QswlWindowMenuPrivate* d_ptr;

private:
    Q_DECLARE_PRIVATE(QswlWindowMenu);
};


#endif /* QSWLWINDOWMENU_H */

