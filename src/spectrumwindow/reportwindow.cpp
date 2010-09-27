#include "reportwindow.h"
#include <QDebug>

ReportWindow::ReportWindow( const QMap<QString,QVariant>& report, QWidget* parent ) :
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

QString ReportWindow::map2tring( const QMap<QString,QVariant>& map ) const
{
    QString str;
#warning "FixMe: Now report is QMap<QString,QVariant>"
    /*
    foreach ( QString key, map.uniqueKeys() )
        str += key += QString(" = ") += QString::number(map[key]) += QString("<br>");
    */
    return str;
}

