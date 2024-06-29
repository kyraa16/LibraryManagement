#include "inputpeminjaman.h"
#include "ui_inputpeminjaman.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

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
