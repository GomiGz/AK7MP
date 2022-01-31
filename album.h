#ifndef ALBUM_H
#define ALBUM_H

#include <QString>
#include <QVector>
#include "song.h"


class Album
{
public:
    Album();
    int id;
    QString Name;
    QString Author;
    QString Year;
    QString Genre;
    QVector<QString> Songs;

    static QVector<Album> MockData();
};

#endif // ALBUM_H
