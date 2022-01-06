#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Detail; }
QT_END_NAMESPACE

class Detail : public QWidget
{
    Q_OBJECT

public:
    Detail(QWidget *parent = nullptr,int ID = 0);
    ~Detail();

slots:
    void MainClosing();

private:
    Ui::Detail *ui;
    void CloseWindow();
};
#endif // DETAIL_H
