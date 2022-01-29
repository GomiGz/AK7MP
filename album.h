#ifndef ALBUM_H
#define ALBUM_H

#include <QString>
#include <QVector>
#include "song.h"
#include <QSqlQueryModel>

class Album
{
public:
    Album();
    Album(QSqlQueryModel model);
    int id;
    QString Name;
    QString Author;
    QString Year;
    QString Genre;
    QVector<QString> Songs;

    static QVector<Album> MockData();
};

#endif // ALBUM_H
