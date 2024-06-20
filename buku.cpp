#include "buku.h"
#include "ui_buku.h"

Buku::Buku(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Buku)
{
    ui->setupUi(this);
}

Buku::~Buku()
{
    delete ui;
}
