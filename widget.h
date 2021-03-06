#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include "album.h"
#include "detail.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void closing();

private:
    Ui::Widget *ui;
    void Widget::cellDoubleClicked();
};
#endif // WIDGET_H
