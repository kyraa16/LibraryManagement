#include "bukubaru.h"
#include "ui_bukubaru.h"
#include "buku.h"
#include <QMessageBox>
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

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
    submitForm();
}

void bukuBaru::submitForm()
{
    QString judul = ui->judulInput->text();
    QString author = ui->authorInput->text();
    QString penerbit = ui->penerbitInput->text();
    if (validateInput()) {
        dataBuku->createData(judul, penerbit, author);
        QMessageBox::information(0,"Tambah Buku", "Data buku berhasil ditambah!");
        buku *b = new buku(dataBuku, dataPeminjaman, dataAnggota);
        b->show();
        this->close();
    }
}

bool bukuBaru::validateInput()
{
    QString errorMsg = "";
    QString judul = ui->judulInput->text();
    QString author = ui->authorInput->text();
    QString penerbit = ui->penerbitInput->text();
    if (judul == "")
        errorMsg = "Masukkan judul terlebih dahulu";
    else if (author == "")
        errorMsg = "Masukkan author terlebih dahulu";
    else if (penerbit == "")
        errorMsg = "Masukkan penerbit terlebih dahulu";
    if (errorMsg != "")
        QMessageBox::critical(this,"Tambah Peminjaman",errorMsg);
    return errorMsg == "";
}

void bukuBaru::on_judulInput_returnPressed()
{
    submitForm();
}


void bukuBaru::on_authorInput_returnPressed()
{
    submitForm();
}


void bukuBaru::on_penerbitInput_returnPressed()
{
    submitForm();
}

