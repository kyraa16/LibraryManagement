#include "inputanggota.h"
#include "ui_inputanggota.h"
#include "databuku.h"

inputAnggota::inputAnggota(DataBuku *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputAnggota)
{
    this->dataBuku = data;
    ui->setupUi(this);
}

inputAnggota::~inputAnggota()
{
    delete ui;
}
