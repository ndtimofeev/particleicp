#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMdiArea>
#include "selectrecentmenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void fileOpened( QString path );

public:
    MainWindow( QWidget* parent = 0 );
    virtual ~MainWindow();

protected:
    SelectRecentMenu* rofptr;
    QMdiArea*    mdiarea;

protected slots:
    void selectFile();
    void openFile( const QString& path );
    void aboutQt();
    void aboutQwt();
    void aboutGMP();
    void about();
};

#endif /* MAINWINDOW_H */

