#include "listpeminjaman.h"
#include "ui_listpeminjaman.h"
#include "peminjaman.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include <QButtonGroup>
#include <QDialogButtonBox>
#include <QVBoxLayout>

listPeminjaman::listPeminjaman(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listPeminjaman)
{
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    QStringList columnNames;
    columnNames<<"Nama"<<"Judul Buku"<<"ID Buku"<<"Status"<<"Waktu Pengembalian"<<"Aksi";
    qInfo()<<this->dataPeminjaman->head->nama;
    ui->tableWidget->setRowCount(10);
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
    ui->tableWidget->setRowCount(this->dataPeminjaman->count-1);
    while (peminjaman != NULL) {
        if (searchQuery == "") {
            qInfo()<<peminjaman->status;
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(peminjaman->nama);
            ui->tableWidget->setItem(i, 0, item);
            QTableWidgetItem* item2 = new QTableWidgetItem();
            item2->setText(peminjaman->judulBuku);
            ui->tableWidget->setItem(i, 1, item2);
            QTableWidgetItem* item3 = new QTableWidgetItem();
            item3->setText(QString::number(peminjaman->idBuku));
            ui->tableWidget->setItem(i, 2, item3);
            QTableWidgetItem* item4 = new QTableWidgetItem();
            item4->setText(peminjaman->status);
            ui->tableWidget->setItem(i, 3, item4);
            QTableWidgetItem* item5 = new QTableWidgetItem();
            item5->setText(peminjaman->waktuPengembalian.date().toString(Qt::ISODate));
            ui->tableWidget->setItem(i, 4, item5);
            if (peminjaman->status != "Dikembalikan") {
                QPushButton *btn_delete = new QPushButton();
                btn_delete->setText("Kembalikan");
                connect(btn_delete, &QPushButton::released, this,
                        [this, peminjaman]()
                        {
                            handleButtonReturn(peminjaman->id);
                        });
                ui->tableWidget->setCellWidget(i,5,(QWidget*)btn_delete);
            }
            i++;
        }
        peminjaman = peminjaman->next;
    }
    ui->tableWidget->setRowCount(i);
    finishRenderTable = true;
    qInfo()<<i;
}

void listPeminjaman::handleButtonReturn(int id) {
    Peminjaman *temp = dataPeminjaman->head;
    dataPeminjaman->returnBook(id);
    refreshTable();
    // dataMhs->cetakData();
}


void listPeminjaman::on_tableWidget_cellChanged(int row, int column)
{

}


void listPeminjaman::on_backPeminjaman_clicked()
{
    peminjaman *backPeminjaman = new peminjaman(dataBuku, dataPeminjaman, dataAnggota);
    backPeminjaman->show();
    backPeminjaman->setGeometry(300, 150, 900, 600);
    this->close();
}

