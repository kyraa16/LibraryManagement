#include "listpeminjaman.h"
#include "ui_listpeminjaman.h"
#include "peminjaman.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include <QButtonGroup>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>

listPeminjaman::listPeminjaman(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listPeminjaman)
{
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(7);
    QStringList columnNames;
    columnNames<<"Nama"<<"NIM"<<"Judul Buku"<<"ID Buku"<<"Status"<<"Waktu Pengembalian"<<"Aksi";
    // qInfo()<<this->dataPeminjaman->head->nama;
    // ui->tableWidget->setRowCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(columnNames);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    refreshTable();
}

listPeminjaman::~listPeminjaman()
{
    delete ui;
}

void listPeminjaman::refreshTable()
{
    struct Peminjaman *peminjaman = this->dataPeminjaman->head;
    int i = 0;
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(this->dataPeminjaman->count);
    while (peminjaman != NULL) {
        if (QString::number(peminjaman->id) == searchQuery || peminjaman->nimAnggota.contains(searchQuery) || peminjaman->namaAnggota.contains(searchQuery, Qt::CaseInsensitive) || searchQuery == "") {
            // qInfo()<<peminjaman->namaAnggota<<"-"<<peminjaman->nimAnggota;
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(peminjaman->namaAnggota);
            ui->tableWidget->setItem(i, 0, item);
            QTableWidgetItem* item2 = new QTableWidgetItem();
            item2->setText(peminjaman->nimAnggota);
            ui->tableWidget->setItem(i, 1, item2);
            QTableWidgetItem* item3 = new QTableWidgetItem();
            item3->setText(peminjaman->judulBuku);
            ui->tableWidget->setItem(i, 2, item3);
            QTableWidgetItem* item4 = new QTableWidgetItem();
            item4->setText(QString::number(peminjaman->idBuku));
            ui->tableWidget->setItem(i, 3, item4);
            QTableWidgetItem* item5 = new QTableWidgetItem();
            item5->setText(peminjaman->status);
            ui->tableWidget->setItem(i, 4, item5);
            QTableWidgetItem* item6 = new QTableWidgetItem();
            QLocale locale(QLocale("id_ID"));
            item6->setText(locale.toString(peminjaman->waktuPengembalian, "d MMMM yyyy"));
            ui->tableWidget->setItem(i, 5, item6);
            if (peminjaman->status != "Dikembalikan") {
                QPushButton *btn_delete = new QPushButton();
                btn_delete->setText("Kembalikan");
                connect(btn_delete, &QPushButton::released, this,
                        [this, peminjaman, btn_delete]()
                        {
                            handleButtonReturn(peminjaman->id, btn_delete);
                            btn_delete->hide();
                        });
                btn_delete->hide();
                ui->tableWidget->setCellWidget(i,6,(QWidget*)btn_delete);
            }
            i++;
        }
        peminjaman = peminjaman->next;
    }
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setColumnWidth(5, 140);
    ui->tableWidget->setColumnWidth(4, 120);
    // for (int j = 0; j < i; ++j)
    //     if (j != 5 && j != 4)
    //         ui->tableWidget->horizontalHeader()->setSectionResizeMode(j,QHeaderView::Stretch);
    finishRenderTable = true;
    qInfo()<<i;
}

void listPeminjaman::handleButtonReturn(int id, QPushButton *btn_kembali) {
    // Peminjaman *temp = dataPeminjaman->head;
    dataPeminjaman->returnBook(id);
    refreshTable();
    // btn_kembali->hide();
    // dataMhs->cetakData();
}

void listPeminjaman::on_backPeminjaman_clicked()
{
    peminjaman *backPeminjaman = new peminjaman(dataBuku, dataPeminjaman, dataAnggota);
    backPeminjaman->show();
    backPeminjaman->setGeometry(300, 150, 900, 600);
    this->close();
}


void listPeminjaman::on_searchButton_clicked()
{
    searchQuery = ui->searchInput->text();
    refreshTable();
}


void listPeminjaman::on_searchInput_returnPressed()
{
    searchQuery = ui->searchInput->text();
    refreshTable();
}

