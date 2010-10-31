#ifndef SELECTRECENTMENU_H
#define SELECTRECENTMENU_H

#include <QString>
#include <QStringList>
#include <QWidget>
#include "dmenu.h"

class SelectRecentMenuPrivate;

class SelectRecentMenu : public DMenu
{
    Q_OBJECT
    Q_PROPERTY( int max READ max WRITE setMax )

signals:
    void elementSelected( QString str );

public:
    SelectRecentMenu( QWidget* parent = 0 );
    virtual ~SelectRecentMenu();

    int         max() const;
    void        setMax( int i );
    QStringList saveState() const;
    void        restoreState( const QStringList& list );

public slots:
    void addElement( QString str );
    void removeAllElements();

protected:
    SelectRecentMenu( SelectRecentMenuPrivate &d_ptr, QWidget* parent = 0 );

    virtual void redrawMenu();

    SelectRecentMenuPrivate* selectrecentmenu;

private:
    Q_DECLARE_PRIVATE_D(selectrecentmenu,SelectRecentMenu)
};

#endif /* SELECTRECENTMENU_H */

