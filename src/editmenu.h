#ifndef EDITMENU_H
#define EDITMENU_H

#include <QWidget>
#include <QPointer>
#include <QMdiArea>
#include "dmenu.h"

class EditMenu : public DMenu
{
    Q_OBJECT

public:
    EditMenu( QWidget* parent );
    EditMenu( QMdiArea* area, QWidget* parent );
    virtual ~EditMenu();

    const QMdiArea* area() const;
    void            setArea( QMdiArea* area );

protected:
    virtual void    redrawMenu();

private:
    QPointer<QMdiArea> area_v;
};

#endif /* EDITMENU_H */

