#include "inputpeminjaman.h"
#include "ui_inputpeminjaman.h"

inputPeminjaman::inputPeminjaman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputPeminjaman)
{
    ui->setupUi(this);
}

inputPeminjaman::~inputPeminjaman()
{
    delete ui;
}
