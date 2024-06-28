#include "inputpeminjaman.h"
#include "ui_inputpeminjaman.h"
#include "databuku.h"

inputPeminjaman::inputPeminjaman(DataBuku *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputPeminjaman)
{
    this->dataBuku = data;
    ui->setupUi(this);
}

inputPeminjaman::~inputPeminjaman()
{
    delete ui;
}
