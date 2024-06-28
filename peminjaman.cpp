#include "peminjaman.h"
#include "ui_peminjaman.h"
#include "buku.h"
#include "library.h"
#include "buku.h"
#include "anggota.h"
#include "databuku.h"

peminjaman::peminjaman(DataBuku *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::peminjaman)
{
    this->dataBuku = data;
    ui->setupUi(this);
}

peminjaman::~peminjaman()
{
    delete ui;
}

void peminjaman::on_listPinjam_clicked()
{
    qInfo()<<"List Peminjaman";
    listPeminjaman *lp = new listPeminjaman(dataBuku);
    lp->setGeometry(300, 150, 900, 600);
    lp->show();
}

void peminjaman::on_pinjamBuku_clicked()
{
    buku *pb = new buku(dataBuku);
    pb->show();
    pb->setGeometry(300, 150, 900, 600);
}

void peminjaman::on_back2_clicked()
{
    qInfo()<<"Library";
    Library *back2 = new Library();
    back2->setGeometry(300, 150, 900, 600);
    back2->show();
    this->close();
}

void peminjaman::on_peminjamanBuku_clicked()
{
    buku *peminjamanBuku = new buku(dataBuku);
    peminjamanBuku->setGeometry(300, 150, 900, 600);
    peminjamanBuku->show();
    this->close();
}


void peminjaman::on_peminjamanAnggota_clicked()
{
    anggota *peminjamanAnggota = new anggota(dataBuku);
    peminjamanAnggota->show();
    peminjamanAnggota->setGeometry(300, 150, 900, 600);
    this->close();
}

