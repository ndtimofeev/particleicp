#ifndef ROFSELECTOR_H
#define ROFSELECTOR_H

#include <QMenu>
#include <QList>
#include <QString>
#include <QWidget>

class ROFSelector : public QMenu
{
    Q_OBJECT

public:
    ROFSelector( QWidget* parent = 0 );
    virtual ~ROFSelector();

public slots:
    void addFile( const QString& path );
    void clear();

signals:
    fileSelected( const QString& path );

protected:
    int             max_count;
    QList<QString*> history;
};

#endif /* ROFSELECTOR_H */

