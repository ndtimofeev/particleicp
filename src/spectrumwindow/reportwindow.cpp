#include "reportwindow.h"
#include <QDebug>

ReportWindow::ReportWindow( const QMap<QString,qreal>& report, QWidget* parent ) :
    QMdiSubWindow( parent )
{
    this->setWindowTitle( tr("Report window") );
    this->text = new QTextEdit( this->map2tring( report ), this );
    this->setWidget( this->text );
    this->text->setReadOnly( true );
}

ReportWindow::~ReportWindow()
{
}

QString ReportWindow::map2tring( const QMap<QString,qreal>& map ) const
{
    QString str;
    foreach ( QString key, map.uniqueKeys() )
        str += key += QString(" = ") += QString::number(map[key]) += QString("<br>");

    return str;
}

