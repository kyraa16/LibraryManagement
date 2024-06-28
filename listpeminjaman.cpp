#include "listpeminjaman.h"
#include "ui_listpeminjaman.h"
#include "databuku.h"

listPeminjaman::listPeminjaman(DataBuku *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listPeminjaman)
{
    this->dataBuku = data;
    ui->setupUi(this);
}

listPeminjaman::~listPeminjaman()
{
    delete ui;
}
