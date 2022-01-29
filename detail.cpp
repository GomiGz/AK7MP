#include "detail.h"
#include "./ui_detail.h"
#include "album.h"
#include "widget.h"

Detail::Detail(QWidget *parent,int id)
    : ui(new Ui::Detail)
{

    ui->setupUi(this);

    Database db;
    Album album = db.GetAlbum(id);

    ui->AuthorLabel->setText(album.Author);
    ui->NameLabel->setText(album.Name);
    ui->YearLabel->setText(album.Year);
    ui->GenreLabel->setText(album.Genre);
}

Detail::~Detail()
{
    delete ui;
}

