#include <QVector>
#include "album.h"

Album::Album()
{
}

Album::Album(QSqlQueryModel model){

}

QVector<Album> Album::MockData()
{
   QVector<Album> list;
   Album first;
   first.Author= "test";
   first.Genre="roclk";
   first.Name= "hapopz";
   first.Year= "2021";

   Album second;
   second.Author= "kolo";
   second.Genre="se";
   second.Name= "tocilo";
   second.Year= "1920";

   list.append(first);
   list.append(second);

   return list;
}
