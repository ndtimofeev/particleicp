#include <QtGui>
#include "mainwindow.h"
#include "settings.h"

int main( int argc, char** argv )
{
    QApplication app(argc, argv);

        Settings::init( "PsiLab", "ParticleICP" );
        MainWindow mw;
        mw.show();

    return app.exec();
}
