#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QMdiSubWindow>
#include <QTextEdit>

class ReportWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    ReportWindow( const QMap<QString,qreal>& report, QWidget* parent = 0 );
    virtual ~ReportWindow();

protected:
    QString map2tring( const QMap<QString,qreal>& map ) const;

private:
    QTextEdit* text;
};

#endif /* REPORTWINDOW_H */

