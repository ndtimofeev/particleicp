#include <QtGui>
#include "mainwindow.h"
//#include "dlist.h"

int main( int argc, char** argv )
{
//    DList<QString*> list;
    QApplication app(argc, argv);

        MainWindow mw;
        mw.restoreGeometry(QSettings("PsiLab","AlICP").value("MainWindowGeometry").toByteArray());
        mw.show();

    return app.exec();
}
