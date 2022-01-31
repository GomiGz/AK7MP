#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <database.h>
#include <AddSongDialog.h>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Detail; }
QT_END_NAMESPACE

class Detail : public QWidget
{
    Q_OBJECT

public:
    Detail(QWidget *parent = nullptr,int ID = 0);
    ~Detail();

private slots:
    void on_AddPictureButton_clicked();

    void on_AddSongButton_clicked();

    void on_RemoveSongButton_clicked();
    void uploadFile(const QString &path);

private:
    Ui::Detail *ui;
    int albumID;
    void UpdateList();

    void fillList(QSqlQueryModel* data);
    QList<int> songIndexes;
};
#endif // DETAIL_H
