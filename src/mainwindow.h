#ifndef MAINWINDOW
#define MAINWINDOW

#include <QMdiArea>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QMenu>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0 );
    ~MainWindow();
    QStringList history;

private:
    QMdiArea*   mdiArea;

private slots:
    void fileSelect();
    void fileRead( QString& path );

};

#endif // MAINWINDOW
