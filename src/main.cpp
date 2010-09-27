#include <QtGui>
#include "mainwindow.h"
//#include "dlist.h"
#include "proginfo.h"

int main( int argc, char** argv )
{
//    ProgInfo* pi = new;
//    DList<QString*> list;
    QApplication app(argc, argv);

        MainWindow mw;
        mw.restoreGeometry(QSettings("PsiLab","AlICP").value("MainWindowGeometry").toByteArray());
        mw.show();

    return app.exec();
}
