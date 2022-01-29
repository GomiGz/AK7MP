#include "./ui_addDialog.h"
#include "addDialog.h"

AddDialog::AddDialog(QWidget *parent)
    : ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&AddDialog::on_AddDialog_accepted);
}

AddDialog::~AddDialog()
{
    delete ui;
}


void AddDialog::on_AddDialog_accepted()
{
    Album newAlbum;
    newAlbum.Author = ui->inputAuthor->text();
    newAlbum.Name = ui->inputAlbum->text();
    newAlbum.Year = ui->inputYear->text();
    newAlbum.Genre = ui->inputGenre->text();
    qDebug()<< newAlbum.Author << newAlbum.Name << newAlbum.Year << newAlbum.Genre;
    Database db;
    db.AddAlbum(newAlbum);
    emit AlbumAdded();
    done(0);
}

