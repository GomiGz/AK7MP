#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "album.h"
#include "detail.h"
#include "database.h"
#include "addDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();

signals:
    void closing();

private slots:
    void on_actionPridat_triggered();
    void updateTable();
    void ShowContextMenu(const QPoint &pos);
    void deleteAlbum();

private:
    Ui::MainWindow *ui;
    void MainWindow::cellDoubleClicked();
    void fillTable(QSqlQueryModel* data);

};
#endif // MAINWINDOW_H
