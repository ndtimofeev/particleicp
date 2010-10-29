#ifndef DMENU_H
#define DMENU_H

#include <QAction>
#include <QMenu>
#include <QWidget>
#include <QString>

class DMenuPrivate;

class DMenu : public QMenu
{
    Q_OBJECT
    Q_PROPERTY( QString nullActionText READ nullActionText WRITE setNullActionText )
public:
    DMenu( QWidget* parent = 0 );
    virtual ~DMenu();

    QString  nullActionText() const;
    void     setNullActionText( const QString& str );

    QAction* nullAction() const;

protected:
    DMenu( DMenuPrivate &d, QWidget* parent = 0 );

    virtual void redrawMenu();

    DMenuPrivate* d_ptr;

protected slots:
    void updateMenu();

private:
    Q_DECLARE_PRIVATE(DMenu)
};

#endif /* DMENU_H */
