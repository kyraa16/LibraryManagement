#include "inputanggota.h"
#include "ui_inputanggota.h"
#include "databuku.h"
#include "anggota.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include <QMessageBox>

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

void inputAnggota::on_confirmAnggota_rejected()
{
    anggota *confirmAnggota = new anggota(dataBuku, dataPeminjaman, dataAnggota);
    confirmAnggota->show();
    confirmAnggota->setGeometry(300, 150, 900, 600);
    this->close();
}

void inputAnggota::on_confirmAnggota_accepted()
{
    submitForm();
}

void inputAnggota::submitForm()
{
    QString nama = ui->inputNama->text();
    QString nim = ui->inputNim->text();
    if (validateInput()) {
        dataAnggota->createData(nama,nim);
        QMessageBox::information(0,"Tambah Anggota", "Data anggota berhasil ditambah!");
        anggota *a = new anggota(dataBuku, dataPeminjaman, dataAnggota);
        a->show();
        this->close();
    }
}

bool inputAnggota::validateInput()
{
    QString errorMsg = "";
    QString nama = ui->inputNama->text();
    QString nim = ui->inputNim->text();
    if (nama == "")
        errorMsg = "Masukkan nama terlebih dahulu";
    else if (nim == "")
        errorMsg = "Masukkan NIM terlebih dahulu";
    Anggota *temp = dataAnggota->head;
    while (temp != NULL && temp->nim != nim)
        temp = temp->next;
    if (temp != NULL && temp->nim == nim)
        errorMsg = "NIM sudah ada";
    if (errorMsg != "")
        QMessageBox::critical(this,"Tambah Peminjaman",errorMsg);
    return errorMsg == "";
}


void inputAnggota::on_inputNama_returnPressed()
{
    submitForm();
}


void inputAnggota::on_inputNim_returnPressed()
{
    submitForm();
}
