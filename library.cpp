#include "library.h"
#include "peminjaman.h"
#include "./ui_library.h"
#include "buku.h"
#include "anggota.h"
#include "databuku.h"
#include "dataanggota.h"
#include "datapeminjaman.h"
#include<QDebug>
#include <QDate>

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    DataBuku *dataBuku = new DataBuku();
    DataPeminjaman *dataPeminjaman = new DataPeminjaman();
    DataAnggota *dataAnggota = new DataAnggota();
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    ui->setupUi(this);
    ui->label->setGeometry(250, 100, 300, 300);
    // QDate now = QDate::currentDate().addDays(5);
    // QDateTime endDay = QDate::currentDate().endOfDay();
    // QString str = endDay.toString("yyyy-MM-dd HH:mm:ss");
    // QString str2 = QDateTime::currentDateTime().addDays(1).toString("yyyy-MM-dd HH:mm:ss");
    // QDateTime newDay = QDateTime::fromString("2024-06-28 14:02:33", "yyyy-MM-dd HH:mm:ss");
    // qInfo()<<(newDay<endDay);
}

Library::~Library()
{
    delete ui;
}

void Library::on_bukuButton_clicked()
{
    qInfo()<<"Buku";
    buku *pageBuku = new buku(dataBuku, dataPeminjaman, dataAnggota);
    pageBuku->setGeometry(300, 150, 900, 600);
    pageBuku->show();
    this->close();
}

void Library::on_peminjamanButton_clicked()
{
    qInfo()<<"Peminjaman";
    peminjaman *pagePeminjaman = new peminjaman(dataBuku, dataPeminjaman, dataAnggota);
    pagePeminjaman->setGeometry(300, 150, 900, 600);
    pagePeminjaman->show();
    this->close();
}


void Library::on_anggota_clicked()
{
    qInfo()<<"Anggota";
    anggota *a = new anggota(dataBuku, dataPeminjaman, dataAnggota);
    a->setGeometry(300, 150, 900, 600);
    a->show();
}

