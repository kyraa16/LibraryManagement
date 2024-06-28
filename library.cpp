#include "library.h"
#include "peminjaman.h"
#include "./ui_library.h"
#include "buku.h"
#include "anggota.h"
#include "databuku.h"
#include<QDebug>
#include <QDate>

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    DataBuku *data = new DataBuku();
    this->dataBuku = data;
    ui->setupUi(this);
    ui->label->setGeometry(250, 100, 300, 300);
    // QDate now = QDate::currentDate().addDays(5);
    QDateTime now = QDate::currentDate().endOfDay();
    QString str = now.toString("yyyy-MM-dd  HH:mm:ss");
    QDateTime newDay = QDateTime::fromString("2024-06-29 00:00:00", "yyyy-MM-dd  HH:mm:ss");
    qInfo()<<(newDay);
}

Library::~Library()
{
    delete ui;
}

void Library::on_bukuButton_clicked()
{
    qInfo()<<"Buku";
    buku *pageBuku = new buku(dataBuku);
    pageBuku->setGeometry(300, 150, 900, 600);
    pageBuku->show();
    this->close();
}

void Library::on_peminjamanButton_clicked()
{
    qInfo()<<"Peminjaman";
    peminjaman *pagePeminjaman = new peminjaman(dataBuku);
    pagePeminjaman->setGeometry(300, 150, 900, 600);
    pagePeminjaman->show();
    this->close();
}


void Library::on_anggota_clicked()
{
    qInfo()<<"Anggota";
    anggota *a = new anggota(dataBuku);
    a->setGeometry(300, 150, 900, 600);
    a->show();
}

