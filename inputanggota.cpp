#include "inputanggota.h"
#include "ui_inputanggota.h"
#include "databuku.h"
#include "anggota.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include <QMessageBox>

inputAnggota::inputAnggota(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputAnggota)
{
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    ui->setupUi(this);
}

inputAnggota::~inputAnggota()
{
    delete ui;
}

void inputAnggota::on_confirmAnggota_rejected()
{
    anggota *confirmAnggota = new anggota(dataBuku, dataPeminjaman, dataAnggota);
    confirmAnggota->show();
    confirmAnggota->setGeometry(300, 150, 900, 600);
    this->close();
}

void inputAnggota::on_confirmAnggota_accepted()
{
    QString nama = ui->inputNama->text();
    QString nim = ui->inputNim->text();

    dataAnggota->createData(nama,nim);
    QMessageBox::information(0,"Tambah Anggota", "Data anggota berhasil ditambah!");
    anggota *a = new anggota(dataBuku, dataPeminjaman, dataAnggota);
    a->show();
    this->close();
}

