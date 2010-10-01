#include <QString>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget* parent ) : QMainWindow( parent )
{
    Ui::MainWindow ui;
    ui.setupUi( this );
}

MainWindow::~MainWindow()
{
}

void MainWindow::selectFile()
{
    QString path = QFileDialog::getOpenFileName( this, tr("Open Image"), "~/", 
            tr("JY Files(*.jy)") );

    if ( ! path.isEmpty() )
        openFile( path );
}

void MainWindow::openFile( const QString& path )
{
    emit fileSelected( path );
}

void MainWindow::aboutQt()
{
    qApp->aboutQt();
}

