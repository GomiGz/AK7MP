#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QDebug>
#include <album.h>
#include <database.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AddDialog; }
QT_END_NAMESPACE

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

signals:
    void AlbumAdded();

private slots:
    void on_AddDialog_accepted();

private:
    Ui::AddDialog *ui;
};
#endif //ADDDIALOG_H
