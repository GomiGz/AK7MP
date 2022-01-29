#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <database.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Detail; }
QT_END_NAMESPACE

class Detail : public QWidget
{
    Q_OBJECT

public:
    Detail(QWidget *parent = nullptr,int ID = 0);
    ~Detail();

private:
    Ui::Detail *ui;
};
#endif // DETAIL_H
