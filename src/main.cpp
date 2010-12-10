#include <QtGui>
#include "mainwindow.h"
#include "settings.h"

int main( int argc, char** argv )
{
    QApplication app(argc, argv);

        Settings::init( "PsiLab", "ParticleICP" );

        QTranslator qtTranslator;

        qtTranslator.load("particleicp_" + QLocale::system().name());
//                        QLibraryInfo::location(QLibraryInfo::TranslationsPath));

        qDebug() << QLibraryInfo::location(QLibraryInfo::TranslationsPath);
        qDebug() << QLocale::system().name();

        app.installTranslator(&qtTranslator);

        MainWindow mw;

        mw.show();

    return app.exec();
}
