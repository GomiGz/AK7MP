#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DBPath);
    db.open();
}

void Database::GetAllAlbums(QSqlQueryModel* model)
{
    ExecuteSelect(model,"select rowid,author,name,year,genre FROM albums");
}

void Database::ExecuteSelect(QSqlQueryModel* model,QString select)
{
    QSqlQuery* query = new QSqlQuery(db);
    query->prepare(select);
    query->exec();
    model->setQuery(*query);
    db.close();
}

void Database::ExecuteInsert(QString insert)
{
    QSqlQuery* query = new QSqlQuery(db);
    query->prepare(insert);
    qDebug() << query->lastError();
    query->exec();
    qDebug() << query->lastError();

    db.commit();
    db.close();
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
   ExecuteSelect(model,"select rowid,author,name,year,genre FROM albums where rowdi =" + ID);
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
    qDebug() << QString::fromStdString(query);
    ExecuteInsert(QString::fromStdString(query));
}
