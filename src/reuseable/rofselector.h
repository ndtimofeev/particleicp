#ifndef RECENTFILESMENU_H
#define RECENTFILESMENU_H

#include <QMenu>
#include <QAction>

class ROFAction : public QAction
{
    Q_OBJECT

public:
    ROFAction( QString& path, QObject* parent );
    virtual ~ROFAction();

signals:
    void triggered( QString &path );

private:
    QString* path;

private slots:
    void emit_engine();
};


class ROFSelector : public QMenu
{
    Q_OBJECT

public:
    ROFSelector( QWidget* parent = 0 );
    ROFSelector( const QStringList* history, QWidget* parent = 0 );
    ROFSelector( const QStringList* history, const QString &title, QWidget* parent = 0 );
    virtual ~ROFSelector();

    int  getMaxStrNum() const;
    void setMaxStrNum( int i );

signals:
    void selectedFile( QString& path );

private slots:
    void update();

private:
    const QStringList*  history;
    QAction*            empty;
    int                 max_str_num;
};

#endif // RECENTFILESMENU_H
