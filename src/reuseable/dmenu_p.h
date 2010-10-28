#ifndef DMENU_P_H
#define DMENU_P_H

#include <QObject>
#include "dmenu.h"

class DMenuPrivate
{
    Q_DECLARE_PUBLIC(DMenu)
public:
    DMenuPrivate();
    virtual ~DMenuPrivate();

    void     init();
    void     redrawMenu();
    QString  nullActionText() const;
    void     setNullActionText( const QString& str );

    DMenu*   q_ptr;
    QAction* nullAction;
    QString  nullText;
};

#endif /* DMENU_P_H */

