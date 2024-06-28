#include "bukubaru.h"
#include "ui_bukubaru.h"
#include "buku.h"
#include <QMessageBox>
#include "databuku.h"

// buku b;

bukuBaru::bukuBaru(DataBuku *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bukuBaru)
{
    ui->setupUi(this);
    this->dataBuku = data;
}

bukuBaru::~bukuBaru()
{
    delete ui;
}

void bukuBaru::on_tambahBuku_rejected()
{
    buku *cancelBuku = new buku(dataBuku);
    cancelBuku->show();
    cancelBuku->setGeometry(300, 150, 900, 600);
    this->close();
}

void bukuBaru::on_tambahBuku_accepted()
{
    QString judul = ui->judulInput->text();
    QString author = ui->authorInput->text();
    QString penerbit = ui->penerbitInput->text();
    dataBuku->createBuku(judul, penerbit, author);
    QMessageBox::information(0,"Tambah Buku", "Data buku berhasil ditambah!");
    buku *b = new buku(dataBuku);
    b->show();
    this->close();
}

