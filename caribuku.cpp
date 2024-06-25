#include "caribuku.h"
#include "ui_caribuku.h"

cariBuku::cariBuku(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cariBuku)
{
    ui->setupUi(this);
}

cariBuku::~cariBuku()
{
    delete ui;
}
