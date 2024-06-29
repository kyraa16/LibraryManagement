#include "peminjaman.h"
#include "ui_peminjaman.h"
#include "buku.h"
#include "library.h"
#include "buku.h"
#include "anggota.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

peminjaman::peminjaman(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::peminjaman)
{
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    ui->setupUi(this);
}

peminjaman::~peminjaman()
{
    delete ui;
}

void peminjaman::on_listPinjam_clicked()
{
    // qInfo()<<"List Peminjaman";
    qInfo()<<dataPeminjaman->head->nama;
    listPeminjaman *lp = new listPeminjaman(dataBuku, dataPeminjaman, dataAnggota);
    lp->setGeometry(300, 150, 900, 600);
    lp->show();
}

void peminjaman::on_pinjamBuku_clicked()
{
    buku *pb = new buku(dataBuku, dataPeminjaman, dataAnggota);
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
    buku *peminjamanBuku = new buku(dataBuku, dataPeminjaman, dataAnggota);
    peminjamanBuku->setGeometry(300, 150, 900, 600);
    peminjamanBuku->show();
    this->close();
}


void peminjaman::on_peminjamanAnggota_clicked()
{
    anggota *peminjamanAnggota = new anggota(dataBuku, dataPeminjaman, dataAnggota);
    peminjamanAnggota->show();
    peminjamanAnggota->setGeometry(300, 150, 900, 600);
    this->close();
}

