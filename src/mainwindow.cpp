#include <QString>
#include <QTime>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include "mainwindow.h"
#include "spectrumwindow.h"
#include "settings.h"
#include "parsersettingsdialog.h"
#include "ui_mainwindow.h"
#include "jyparser.h"

MainWindow::MainWindow( QWidget* parent ) : QMainWindow( parent )
{
    Settings* settings = Settings::instance();
    this->restoreGeometry( settings->value("MainWindowGeometry").toByteArray() );

    Ui::MainWindow ui;
    ui.setupUi( this );
    this->rofptr = ui.menu_Recent_Files;
    this->rofptr->restoreState( settings->value("RecentFiles").toStringList() );
    this->rofptr->setMax(5);
}

MainWindow::~MainWindow()
{
    Settings* settings = Settings::instance();
    settings->setValue( "MainWindowGeometry", this->saveGeometry() );
    settings->setValue( "RecentFiles", this->rofptr->saveState() );

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
    QFile file( path );

    if ( ! file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        return;

    QTextStream stream( &file );

    QSet<QString> head =
        ParserSettingsDialog::getSettings( stream, path, this, Settings::instance() );

    if ( head.size() > 1 )
    {
        QFile file( path );

        if ( ! file.open( QIODevice::ReadOnly | QIODevice::Text ) )
            return;

        QTextStream stream( &file );

        SpectrumWindow* sw = new SpectrumWindow( JYParser( head, stream ), path, head, this );
        sw->show();

        emit fileOpened( path );
    }
}

void MainWindow::aboutQt()
{
    qApp->aboutQt();
}

void MainWindow::aboutQwt()
{
    qDebug() << "aboutQwt";
}

void MainWindow::aboutGMP()
{
    qDebug() << "aboutGMP";
}

void MainWindow::about()
{
    qDebug() << "about";
}
