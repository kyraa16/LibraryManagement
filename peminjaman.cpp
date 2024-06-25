#include "peminjaman.h"
#include "ui_peminjaman.h"
#include "buku.h"

peminjaman::peminjaman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::peminjaman)
{
    ui->setupUi(this);
}

peminjaman::~peminjaman()
{
    delete ui;
}

void peminjaman::on_listPinjam_clicked()
{
    qInfo()<<"List Peminjaman";
    lp.setGeometry(300, 150, 900, 600);
    lp.show();
}


void peminjaman::on_pinjamBuku_clicked()
{
    pb.show();
    pb.setGeometry(300, 150, 900, 600);
}

