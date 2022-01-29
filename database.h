#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QtSql>
#include <album.h>
#include <sstream>

class Database
{
public:
    Database();
    void GetAllAlbums(QSqlQueryModel* model);
    void AddAlbum(Album album);
    Album GetAlbum(int ID);
    void DeleteAlbum(int ID);

    const QString DBPath = "C:/Users/admin/Documents/CDDB/cddb.db";
    QSqlDatabase db;

private:
    void ExecuteSelect(QSqlQueryModel* model,QString select);
    void ExecuteInsert(QString insert);
};



#endif // DATABASE_H
