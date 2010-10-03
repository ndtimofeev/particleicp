#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "rofselector.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void fileOpened( QString path );

public:
    MainWindow( QWidget* parent = 0 );
    virtual ~MainWindow();

protected:
    ROFSelector* rofptr;

protected slots:
    void selectFile();
    void openFile( const QString& path );
    void aboutQt();
};

#endif /* MAINWINDOW_H */

