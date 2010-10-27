#ifndef DMENU_P_H
#define DMENU_P_H

#include <QObject>
#include "dmenu.h"

class DMenuPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(DMenu)
public:
    DMenuPrivate();
    virtual ~DMenuPrivate();

    DMenu* q_ptr;

    void redrawMenu();
};

#endif /* DMENU_P_H */

