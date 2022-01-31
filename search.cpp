#include "ui_search.h"
#include "search.h"

Search::Search(QWidget *parent,QString column) : ui(new Ui::Search)
{
    ui->setupUi(this);
    this->column = column;
}

void Search::on_buttonBox_accepted()
{
    emit ValueEntered(ui->lineEdit->text(),column);
    done(0);
}

Search::~Search()
{
    delete ui;
}
