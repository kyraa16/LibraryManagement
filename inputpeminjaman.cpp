#include "inputpeminjaman.h"
#include "ui_inputpeminjaman.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include "buku.h"

inputPeminjaman::inputPeminjaman(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputPeminjaman)
{
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    ui->setupUi(this);
}

inputPeminjaman::~inputPeminjaman()
{
    delete ui;
}

void inputPeminjaman::on_confirmPeminjaman_rejected()
{
    buku *cancelBuku = new buku(dataBuku, dataPeminjaman, dataAnggota);
    cancelBuku->show();
    cancelBuku->setGeometry(300, 150, 900, 600);
    this->close();
}

