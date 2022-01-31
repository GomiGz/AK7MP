#include "AddSongDialog.h"
#include "./ui_AddSongDialog.h"

AddSongDialog::AddSongDialog(QWidget *parent, int id) :ui (new Ui::AddSongDialog)
{
    ui->setupUi(this);
    albumID = id;
}

AddSongDialog::~AddSongDialog()
{
    delete ui;
}

void AddSongDialog::on_buttonBox_accepted()
{
    //qDebug() << albumID << " " << ui->lineEdit->text();
    Database db;
    Song song(ui->lineEdit->text(),albumID);
    db.AddSong(song);
    db.Close();
    emit SongAdded();
    done(0);
}


void AddSongDialog::on_buttonBox_rejected()
{
    done(0);
}

