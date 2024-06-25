#include "listpeminjaman.h"
#include "ui_listpeminjaman.h"

listPeminjaman::listPeminjaman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listPeminjaman)
{
    ui->setupUi(this);
}

listPeminjaman::~listPeminjaman()
{
    delete ui;
}
