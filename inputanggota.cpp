#include "inputanggota.h"
#include "ui_inputanggota.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

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
