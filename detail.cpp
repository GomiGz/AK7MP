#include "detail.h"
#include "./ui_detail.h"
#include "album.h"
#include "widget.h"

Detail::Detail(QWidget *parent,int id)
    : ui(new Ui::Detail)
{
    ui->setupUi(this);

    std::ostringstream s;
    s << QDir::currentPath().toStdString() << "/images/"<< id <<".png";
    std::string stdPath(s.str());
    QString path = QString::fromStdString(stdPath);

    QFileInfo check_file(path);

    if (check_file.exists() && check_file.isFile()) {
        QPixmap pm(path);
        ui->ImageLabel->setPixmap(pm);
        ui->ImageLabel->setScaledContents(true);
        ui->AddPictureButton ->hide();
    }else{
        ui->ImageLabel->hide();
    }

    albumID = id;
    songIndexes = QList<int>();
    Database db;
    Album album = db.GetAlbum(id);

    ui->AuthorLabel->setText(album.Author);
    ui->NameLabel->setText(album.Name);
    ui->YearLabel->setText(album.Year);
    ui->GenreLabel->setText(album.Genre);

    ui->ListSongs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    UpdateList();
    db.Close();
}

Detail::~Detail()
{
    delete ui;
}


void Detail::on_AddPictureButton_clicked()
{
    QString filters("PNG files (*.png)");
    QFileDialog* dia = new QFileDialog(0,"Vybrat",QDir::currentPath(),filters);
    connect(dia,SIGNAL(fileSelected(const QString &)),this,SLOT(uploadFile(const QString &)));
    dia->show();
}


void Detail::on_AddSongButton_clicked()
{
    AddSongDialog* dia = new AddSongDialog(this,albumID);
    connect(dia,&AddSongDialog::SongAdded,this,&Detail::UpdateList);
    dia->show();
}


void Detail::on_RemoveSongButton_clicked()
{
    Database db;
    db.DeleteSong(songIndexes[ui->ListSongs->currentIndex().row()]);
    db.Close();
    UpdateList();
}

void Detail::UpdateList()
{
    Database db;
    QSqlQueryModel* data = new QSqlQueryModel();
    db.GetSongsFromAlbum(data,albumID);
    fillList(data);
    db.Close();
}


void Detail::fillList(QSqlQueryModel* data)
{
    ui->ListSongs->clear();
    songIndexes.clear();
    qDebug() << ui->ListSongs->count();
    for(int i=0; i < data->rowCount(); i++  ){
        songIndexes.append(data->record(i).value(0).toInt());
        ui->ListSongs->addItem(data->record(i).value(1).toString());
    }
}

void Detail::uploadFile(const QString &path)
{
    std::ostringstream s;
    s << QDir::currentPath().toStdString() << "/images/"<< albumID <<".png";
    std::string stdPath(s.str());
    QString newPath = QString::fromStdString(stdPath);
    QFile::copy(path,newPath);

    QFileInfo check_file(newPath);
    if (check_file.exists() && check_file.isFile()) {
        QPixmap pm(path);
        ui->ImageLabel->setPixmap(pm);
        ui->ImageLabel->setScaledContents(true);
        ui->AddPictureButton ->hide();
        ui->ImageLabel->show();
    }
}
