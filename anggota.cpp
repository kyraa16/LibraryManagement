#include "anggota.h"
#include "ui_anggota.h"
#include "library.h"
#include "buku.h"
#include "peminjaman.h"
#include "databuku.h"

anggota::anggota(DataBuku *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::anggota)
{
    ui->setupUi(this);
    this->dataBuku = data;
}

anggota::~anggota()
{
    delete ui;
}

void anggota::on_anggotaBaru_clicked()
{
    inputAnggota *ia = new inputAnggota(dataBuku);
    ia->show();
    ia->setGeometry(300, 150, 900, 600);
}


void anggota::on_anggotaLibrary_clicked()
{
    Library *anggotaLibrary = new Library();
    anggotaLibrary->show();
    anggotaLibrary->setGeometry(300, 150, 900, 600);
    this->close();
}


void anggota::on_anggotaBuku_clicked()
{
    buku *anggotaBuku = new buku(dataBuku);
    anggotaBuku->show();
    anggotaBuku->setGeometry(300, 150, 900, 600);
    this->close();
}


void anggota::on_anggotaPeminjaman_clicked()
{
    peminjaman *anggotaPeminjaman = new peminjaman(dataBuku);
    anggotaPeminjaman->show();
    anggotaPeminjaman->setGeometry(300, 150, 900, 600);
    this->close();
}

