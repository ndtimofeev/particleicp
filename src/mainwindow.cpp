#include <QApplication>
#include <QMdiSubWindow>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QSettings>
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QTime>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "mainwindow.h"
#include "spectrumwindow.h"
#include "rofselector.h"
#include "jyparser.h"
#include "qtwindowlistmenu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget * parent):QMainWindow(parent)
{
    this->history = QSettings("PsiLab","AlICP").value("RecentOpenFiles").toStringList();

    Ui::MainWindow ui;
    ui.setupUi( this );

    ui.menu_Recent_Files->setMaxStrNum(5);
    ui.menu_Recent_Files->disable();
    connect( ui.menu_Recent_Files, SIGNAL( selectedFile( QString & ) ),
             this, SLOT( fileRead( QString & ) ) );

    // Window
    this->mdiArea = new QMdiArea();
    this->setCentralWidget( this->mdiArea );

    ui.menuWindow->attachToMdiArea( this->mdiArea );
}

MainWindow::~MainWindow()
{
    QSettings settings("PsiLab", "AlICP");
    settings.setValue("MainWindowGeometry", saveGeometry());
    settings.setValue("RecentOpenFiles", this->history);
}

void MainWindow::fileSelect()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Data"), "~/", tr("Data Files (*.jy)"));

    if (!path.isEmpty()) 
        this->fileRead(path);
}

void MainWindow::fileRead(QString & path)
{
    this->history << path;
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    qDebug() << QTime::currentTime();
    JYParser parser( &stream, this );
    qDebug() << QTime::currentTime();
    SpectrumWindow *sw =
           new SpectrumWindow( path, parser.getTable(), this );
    this->mdiArea->addSubWindow(sw);
    sw->showMaximized();
}

