#include "library.h"
#include "peminjaman.h"
#include "./ui_library.h"
#include "buku.h"
#include "anggota.h"
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
    b.setGeometry(300, 150, 900, 600);
    b.show();
    //this->close();
}

void Library::on_peminjamanButton_clicked()
{
    qInfo()<<"Peminjaman";
    p.show();
    p.setGeometry(300, 150, 900, 600);
    //this->close();
}


void Library::on_anggota_clicked()
{
    qInfo()<<"Anggota";
    a.setGeometry(300, 150, 900, 600);
    a.show();
}

