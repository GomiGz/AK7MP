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
    void Close();
    void GetAllAlbums(QSqlQueryModel* model);
    void AddAlbum(Album album);
    Album GetAlbum(int ID);
    void DeleteAlbum(int ID);
    void AddSong(Song song);
    void GetSongsFromAlbum(QSqlQueryModel* model, int albumID);
    void DeleteSong(int ID);
    void GetAlbums(QSqlQueryModel* model,QString row, QString value);


    const QString DBPath = QDir::currentPath() + "/cddb.db";
    QSqlDatabase db;

private:
    void ExecuteSelect(QSqlQueryModel* model,QString select);
    void ExecuteInsert(QString insert);
};



#endif // DATABASE_H
