#include "anggota.h"
#include "ui_anggota.h"

anggota::anggota(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::anggota)
{
    ui->setupUi(this);
}

anggota::~anggota()
{
    delete ui;
}

void anggota::on_anggotaBaru_clicked()
{
    ia.show();
    ia.setGeometry(300, 150, 900, 600);
}

