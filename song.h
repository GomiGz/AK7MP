#ifndef SONG_H
#define SONG_H

#include <QString>

class Song
{
public:
    Song(QString name,int albumID);
    QString name;
    int albumID;
};

#endif // SONG_H
