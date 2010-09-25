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
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "mainwindow.h"
#include "spectrumwindow.h"
#include "rofselector.h"
#include "jyparser.h"
#include "qtwindowlistmenu.h"

MainWindow::MainWindow(QWidget * parent):QMainWindow(parent)
{
    this->history = QSettings("PsiLab","AlICP").value("RecentOpenFiles").toStringList();

    // File
    QMenu *menuFile = this->menuBar()->addMenu(tr("&File"));
    menuFile->addAction(tr("&Open..."), this, SLOT(fileSelect()), QKeySequence::Open);

    ROFSelector *rofmenu = new ROFSelector(&this->history, tr("Open recent..."), this);
    rofmenu->setMaxStrNum(100);
    connect(rofmenu, SIGNAL(selectedFile(QString &)), this, SLOT(fileRead(QString &)));
    menuFile->addMenu(rofmenu);

    menuFile->addAction(tr("E&xit"), qApp, SLOT(closeAllWindows()), QKeySequence::Quit);

    // Window
    this->mdiArea = new QMdiArea();
    this->setCentralWidget(this->mdiArea);

    QtWindowListMenu *winMenu = new QtWindowListMenu(this->menuBar());
    winMenu->attachToMdiArea(this->mdiArea);
    this->menuBar()->addMenu(winMenu);

    // Help
    QMenu *menuHelp = this->menuBar()->addMenu(tr("&Help"));
    menuHelp->addAction(tr("&About"), this, SLOT(about()));
    menuHelp->addAction(tr("About &Qt"), qApp, SLOT(aboutQt()));


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
    SpectrumWindow *sw =
           new SpectrumWindow( path, JYParser(&stream, this).getTable(), this );
    this->mdiArea->addSubWindow(sw);
    sw->showMaximized();
}

