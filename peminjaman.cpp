#include "peminjaman.h"
#include "ui_peminjaman.h"

peminjaman::peminjaman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::peminjaman)
{
    ui->setupUi(this);
}

peminjaman::~peminjaman()
{
    delete ui;
}
