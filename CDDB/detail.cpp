#include "detail.h"
#include "./ui_detail.h"
#include "album.h"

Detail::Detail(QWidget *parent,int id)
    : QWidget(parent)
    , ui(new Ui::Detail)
{
    connect(parent, SIGNAL(aboutToQuit()), this,&Detail::CloseWindow);


    ui->setupUi(this);

    QVector<Album> alba = Album::MockData();

    ui->AuthorLabel->setText(alba[id].Author);
    ui->NameLabel->setText(alba[id].Name);
    ui->YearLabel->setText(alba[id].Year);
    ui->GenreLabel->setText(alba[id].Genre);
}

void Detail::CloseWindow(){
    Detail::~Detail();
}

Detail::~Detail()
{
    delete ui;
}

