#include "inputanggota.h"
#include "ui_inputanggota.h"

inputAnggota::inputAnggota(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputAnggota)
{
    ui->setupUi(this);
}

inputAnggota::~inputAnggota()
{
    delete ui;
}
