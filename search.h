#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Search; }
QT_END_NAMESPACE

class Search : public QDialog
{
    Q_OBJECT

public:
    Search(QWidget *parent = nullptr, QString column = "name");
    ~Search();

signals:
    void ValueEntered(QString value,QString column);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Search *ui;
    QString column;
};


#endif // SEARCH_H
