#include "bukubaru.h"
#include "ui_bukubaru.h"
#include "buku.h"
#include <QMessageBox>
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

// buku b;

bukuBaru::bukuBaru(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman,DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bukuBaru)
{
    ui->setupUi(this);
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
}

bukuBaru::~bukuBaru()
{
    delete ui;
}

void bukuBaru::on_tambahBuku_rejected()
{
    buku *cancelBuku = new buku(dataBuku, dataPeminjaman, dataAnggota);
    cancelBuku->show();
    cancelBuku->setGeometry(300, 150, 900, 600);
    this->close();
}

void bukuBaru::on_tambahBuku_accepted()
{
    QString judul = ui->judulInput->text();
    QString author = ui->authorInput->text();
    QString penerbit = ui->penerbitInput->text();
    dataBuku->createData(judul, penerbit, author);
    QMessageBox::information(0,"Tambah Buku", "Data buku berhasil ditambah!");
    buku *b = new buku(dataBuku, dataPeminjaman, dataAnggota);
    b->show();
    this->close();
}

