#ifndef ADDSONGDIALOG_H
#define ADDSONGDIALOG_H

#include <QDialog>
#include <database.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AddSongDialog; }
QT_END_NAMESPACE

class AddSongDialog : public QDialog
{
    Q_OBJECT

public:
    AddSongDialog(QWidget *parent = nullptr,int ID = 0);
    ~AddSongDialog();

signals:
    void SongAdded();

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddSongDialog *ui;
    int albumID;
};

#endif // ADDSONGDIALOG_H
