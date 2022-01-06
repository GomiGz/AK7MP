#include "widget.h"
#include "./ui_widget.h"
#include "album.h"
#include "detail.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &Widget::cellDoubleClicked);

    QVector<Album> album;
    album = Album::MockData();

    int i = 0;
    ui->tableWidget->setRowCount(album.count());
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    for(Album alb :album) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(alb.Name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(alb.Author));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(alb.Year));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(alb.Genre));
        i++;
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::cellDoubleClicked(){
    Detail *wdg = new Detail(this,ui->tableWidget->selectedItems().first()->row());
    wdg->show();
}

