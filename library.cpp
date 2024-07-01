#include "library.h"
#include "peminjaman.h"
#include "./ui_library.h"
#include "buku.h"
#include "anggota.h"
#include "databuku.h"
#include "dataanggota.h"
#include "datapeminjaman.h"
#include<QDebug>
#include <QDate>

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    DataBuku *dataBuku = new DataBuku();
    DataPeminjaman *dataPeminjaman = new DataPeminjaman();
    DataAnggota *dataAnggota = new DataAnggota();
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    ui->setupUi(this);
}

Library::~Library()
{
    delete ui;
}

void Library::on_bukuButton_clicked()
{
    buku *pageBuku = new buku(dataBuku, dataPeminjaman, dataAnggota);
    pageBuku->setGeometry(300, 150, 900, 600);
    pageBuku->show();
    this->close();
}

void Library::on_peminjamanButton_clicked()
{
    peminjaman *pagePeminjaman = new peminjaman(dataBuku, dataPeminjaman, dataAnggota);
    pagePeminjaman->setGeometry(300, 150, 900, 600);
    pagePeminjaman->show();
    this->close();
}


void Library::on_anggota_clicked()
{
    anggota *a = new anggota(dataBuku, dataPeminjaman, dataAnggota);
    a->setGeometry(300, 150, 900, 600);
    a->show();
    this->close();
}

