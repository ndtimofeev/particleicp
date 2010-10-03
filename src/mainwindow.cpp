#include <QString>
#include <QDebug>
#include <QSettings>
#include <QFileDialog>
#include "mainwindow.h"
#include "parsersettingsdialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget* parent ) : QMainWindow( parent )
{
    QSettings settings("PsiLab","ParticleICP");
    this->restoreGeometry( settings.value("MainWindowGeometry").toByteArray() );

    Ui::MainWindow ui;
    ui.setupUi( this );
    this->rofptr = ui.menu_Recent_Files;
    this->rofptr->restoreState( settings.value("RecentFiles").toStringList() );
    this->rofptr->setMax(5);
}

MainWindow::~MainWindow()
{
    QSettings settings("PsiLab","ParticleICP");
    settings.setValue( "MainWindowGeometry", this->saveGeometry() );
    settings.setValue( "RecentFiles", this->rofptr->saveState() );

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
    QStringList head = ParserSettingsDialog::getSettings( path, this/*QSettings("PsiLab", "ParticleICP") */);

    if ( ! head.isEmpty() )
        emit fileOpened( path );
}

void MainWindow::aboutQt()
{
    qApp->aboutQt();
}

