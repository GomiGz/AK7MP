#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DBPath);
    db.open();
}

void Database::Close()
{
    db.close();
}

void Database::GetAllAlbums(QSqlQueryModel* model)
{
    ExecuteSelect(model,"select rowid,author,name,year,genre FROM albums");
}

void Database::ExecuteSelect(QSqlQueryModel* model,QString select)
{
    qDebug() << select;
    QSqlQuery* query = new QSqlQuery(db);
    query->prepare(select);
    qDebug() << query->lastError();
    query->exec();
    qDebug() << query->lastError();
    model->setQuery(*query);
}

void Database::ExecuteInsert(QString insert)
{
    qDebug() << insert;
    QSqlQuery* query = new QSqlQuery(db);
    query->prepare(insert);
    qDebug() << query->lastError();
    query->exec();
    qDebug() << query->lastError();

    db.commit();
}

void Database::AddAlbum(Album album)
{
   QString s;
   s.append("insert into albums (author,name,year,genre) values ('");
   s.append(album.Author);
   s.append("','");
   s.append(album.Name);
   s.append("','");
   s.append(album.Year);
   s.append("','");
   s.append(album.Genre);
   s.append("')");
   ExecuteInsert(s);
}

Album Database::GetAlbum(int ID)
{
   Album album;
   QSqlQueryModel* model= new QSqlQueryModel();

   std::ostringstream s;
   s << "select rowid,author,name,year,genre FROM albums where rowid =" << ID;
   std::string query(s.str());
   ExecuteSelect(model,QString::fromStdString(query));

   album.Author= model->record(0).value(1).toString();
   album.Name= model->record(0).value(2).toString();
   album.Year= model->record(0).value(3).toString();
   album.Genre= model->record(0).value(4).toString();
   album.id = model->record(0).value(0).toInt();
   return album;
}

void Database::DeleteAlbum(int ID)
{
    std::ostringstream s;
    s << "delete from albums where rowid =" << ID;
    std::string query(s.str());
    //qDebug() << QString::fromStdString(query);
    ExecuteInsert(QString::fromStdString(query));
}

void Database::AddSong(Song song)
{
    QString s;
    s.append("insert into songs (name,albumID) values ('");
    s.append(song.name);
    s.append("','");
    s.append(QString::fromStdString(std::to_string(song.albumID)));
    s.append("')");
    ExecuteInsert(s);
}

void Database::GetSongsFromAlbum(QSqlQueryModel* model, int albumID)
{
    std::ostringstream s;
    s << "select rowid,name FROM songs where albumID=" << albumID;
    std::string query(s.str());
    ExecuteSelect(model,QString::fromStdString(query));
}

void Database::DeleteSong(int ID)
{
    std::ostringstream s;
    s << "delete from songs where rowid =" << ID;
    std::string query(s.str());
    ExecuteInsert(QString::fromStdString(query));
}

void Database::GetAlbums(QSqlQueryModel* model,QString row, QString value)
{
    std::ostringstream s;
    s << "select rowid,author,name,year,genre from albums where "<< row.toStdString() <<" like '%" << value.toStdString() << "%'";
    std::string query(s.str());
    qDebug() << QString::fromStdString(query);
    ExecuteSelect(model,QString::fromStdString(query));
}
