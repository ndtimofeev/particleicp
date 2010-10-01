#include <QtGui>
#include "mainwindow.h"

int main( int argc, char** argv )
{
    QApplication app(argc, argv);

        MainWindow mw;
//        mw.restoreGeometry(QSettings("PsiLab","AlICP").value("MainWindowGeometry").toByteArray());
        mw.show();

    return app.exec();
}
