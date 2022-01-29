#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &MainWindow::cellDoubleClicked);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnHidden(4,true);

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(const QPoint &)),this,SLOT(ShowContextMenu(const QPoint &)));

    Database db = Database();
    QSqlQueryModel* data = new QSqlQueryModel();
    db.GetAllAlbums(data);
    fillTable(data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cellDoubleClicked(){
    Detail *wdg = new Detail(this,ui->tableWidget->selectedItems().first()->row());
    wdg->show();
}


void MainWindow::on_actionPridat_triggered()
{
    AddDialog* dialog = new AddDialog(this);
    connect(dialog,&AddDialog::AlbumAdded,this,&MainWindow::updateTable);
    dialog->show();
}

void MainWindow::fillTable(QSqlQueryModel *data){
    ui->tableWidget->setRowCount(data->rowCount());
    for(int i=0; i < data->rowCount(); i++  ){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(data->record(i).value(2).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(data->record(i).value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(data->record(i).value(3).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(data->record(i).value(4).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(data->record(i).value(0).toString()));
    }
}

void MainWindow::updateTable(){
    Database db = Database();
    QSqlQueryModel* data = new QSqlQueryModel();
    db.GetAllAlbums(data);
    fillTable(data);
}

void MainWindow::ShowContextMenu(const QPoint &pos)
{
   QMenu contextMenu(tr("Context menu"), this);
   QAction action1("Smazat album", this);
   connect(&action1, SIGNAL(triggered()), this, SLOT(deleteAlbum()));
   contextMenu.addAction(&action1);
   contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::deleteAlbum()
{
    //qDebug() << ui->tableWidget->item(ui->tableWidget->selectedItems().first()->row(),4)->text().toInt();
    Database db;
    db.DeleteAlbum(ui->tableWidget->item(ui->tableWidget->selectedItems().first()->row(),4)->text().toInt());
    updateTable();
}



