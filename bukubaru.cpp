#include "bukubaru.h"
#include "ui_bukubaru.h"

// buku b;

bukuBaru::bukuBaru(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bukuBaru)
{
    ui->setupUi(this);
}

bukuBaru::~bukuBaru()
{
    delete ui;
}

