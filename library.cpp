#include "library.h"
#include "peminjaman.h"
#include "./ui_library.h"
#include "buku.h"
#include<QDebug>

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    ui->label->setGeometry(250, 100, 300, 300);
}

Library::~Library()
{
    delete ui;
}

void Library::on_bukuButton_clicked()
{
    qInfo()<<"Buku";
    b.show();
    this->close();
}

void Library::on_peminjamanButton_clicked()
{
    qInfo()<<"Peminjaman";
    p.show();
    this->close();
}

