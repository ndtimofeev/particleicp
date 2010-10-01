#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget* parent = 0 );
    virtual ~MainWindow();

signals:
    void fileSelected( const QString& path );

protected slots:
    void selectFile();
    void openFile( const QString& path );
    void aboutQt();
};

#endif /* MAINWINDOW_H */

