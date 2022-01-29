#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVector<Album> album;
    album = Album::MockData();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/admin/Documents/CDDB/cddb.db");
    db.open();


    QSqlQuery* query = new QSqlQuery(db);
    query->prepare("select rowid,author,name,year,genre FROM albums");
    query->exec();
    QSqlQueryModel* data = new QSqlQueryModel();
    data->setQuery(*query);

    ui->tableView->setModel(data);

    qDebug() << data->rowCount();
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::cellDoubleClicked(){
//    Detail *wdg = new Detail(this,ui->tableView->selectedItems().first()->row());
//    wdg->show();
//}

