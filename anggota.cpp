#include "anggota.h"
#include "ui_anggota.h"
#include "library.h"
#include "buku.h"
#include "peminjaman.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include "inputanggota.h"
#include <QMessageBox>

anggota::anggota(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::anggota)
{
    ui->setupUi(this);
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;

    ui->tableWidget->setColumnCount(3);
    QStringList columnNames;
    columnNames<<"Nama Anggota"<<"NIM"<<"Aksi";
    ui->tableWidget->setHorizontalHeaderLabels(columnNames);
    refreshTable();
}

anggota::~anggota()
{
    delete ui;
}

void anggota::refreshTable()
{
    struct Anggota *anggota = this->dataAnggota->head;
    int i = 0;
    ui->tableWidget->setRowCount(this->dataBuku->count+1);
    QTableWidget *currentTable = ui->tableWidget;
    while (anggota != NULL) {
        if (anggota->nim.contains(searchQuery) || anggota->nama.contains(searchQuery, Qt::CaseInsensitive)) {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(anggota->nama);
            ui->tableWidget->setItem(i, 0, item);
            QTableWidgetItem* item2 = new QTableWidgetItem();
            item2->setText(anggota->nim);
            ui->tableWidget->setItem(i, 1, item2);

            QPushButton *btn_delete;
            btn_delete = new QPushButton();
            btn_delete->setText("Delete");
            connect(btn_delete, &QPushButton::released, this,
                    [this, anggota]()
                    {
                        // handleButtonDelete(i);
                        handleButtonDelete(anggota->nim);
                    });
            ui->tableWidget->setCellWidget(i,2,(QWidget*)btn_delete);

            i++;
        }
        anggota = anggota->next;
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(i);
    finishRenderTable = true;
}

void anggota::handleButtonDelete(QString nim) {
    // Anggota *temp = dataAnggota->head;
    dataAnggota->deleteData(nim, dataPeminjaman);
    refreshTable();
}


void anggota::on_anggotaLibrary_clicked()
{
    Library *anggotaLibrary = new Library();
    anggotaLibrary->show();
    anggotaLibrary->setGeometry(300, 150, 900, 600);
    this->close();
}


void anggota::on_anggotaBuku_clicked()
{
    buku *anggotaBuku = new buku(dataBuku, dataPeminjaman, dataAnggota);
    anggotaBuku->show();
    anggotaBuku->setGeometry(300, 150, 900, 600);
    this->close();
}

void anggota::on_anggotaPeminjaman_clicked()
{
    peminjaman *anggotaPeminjaman = new peminjaman(dataBuku, dataPeminjaman, dataAnggota);
    anggotaPeminjaman->show();
    anggotaPeminjaman->setGeometry(300, 150, 900, 600);
    this->close();
}

void anggota::on_anggotaBaru_clicked()
{
    inputAnggota *anggotaBaru = new inputAnggota(dataBuku, dataPeminjaman, dataAnggota);
    anggotaBaru->show();
    anggotaBaru->setGeometry(300, 150, 900, 600);
    this->close();
}

void anggota::on_cariAnggota_clicked()
{
    this->searchQuery = ui->searchAnggota->text();
    refreshTable();
}


void anggota::on_tableWidget_cellChanged(int row, int column)
{
    if (finishRenderTable) {
        int i = 0;
        QString val = ui->tableWidget->item(row, column)->text();
        bool canUpdate = true;
        if (column == 1) {
            Anggota *a, *temp = dataAnggota->head;
            while (temp != NULL) {
                if (i == row)
                    a = temp;
                if (val == temp->nim && temp != a)
                    canUpdate = false;
                if (i >= row && !canUpdate)
                    break;
                temp = temp->next;
                i++;
            }
            if (!canUpdate) {
                QMessageBox::critical(this,"Tambah Anggota","NIM sudah ada");
                ui->tableWidget->setItem(row,column,new QTableWidgetItem(a->nim));
            }
        }
        if (canUpdate)
            dataAnggota->updateData(row, column, val, dataPeminjaman);
    }
}


void anggota::on_searchAnggota_returnPressed()
{
    searchQuery = ui->searchAnggota->text();
    refreshTable();
}

