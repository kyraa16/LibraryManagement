#include "buku.h"
#include "ui_buku.h"
#include <QPixmap>
#include "bukubaru.h"
#include "library.h"
#include "peminjaman.h"
#include "anggota.h"
#include "databuku.h"
#include "bukubaru.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include "inputpeminjaman.h"
#include <QHBoxLayout>
#include <QButtonGroup>

buku::buku(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buku)
{
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    QStringList columnNames;
    columnNames<<"ID"<<"Judul"<<"Penerbit"<<"Author"<<"Aksi";
    ui->tableWidget->setHorizontalHeaderLabels(columnNames);
    refreshTable();
}

buku::~buku()
{
    delete ui;
}

void buku::refreshTable()
{
    struct Buku *buku = this->dataBuku->head;
    int i = 0;
    ui->tableWidget->setRowCount(this->dataBuku->count);
    QTableWidget *currentTable = ui->tableWidget;
    while (buku != NULL) {
        if (buku->id == searchQuery.toInt() || buku->judul.contains(searchQuery, Qt::CaseInsensitive) || searchQuery == "") {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(QString::number(buku->id));
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 0, item);
            QTableWidgetItem* item2 = new QTableWidgetItem();
            item2->setText(buku->judul);
            ui->tableWidget->setItem(i, 1, item2);
            QTableWidgetItem* item3 = new QTableWidgetItem();
            item3->setText(buku->penerbit);
            ui->tableWidget->setItem(i, 2, item3);
            QTableWidgetItem* item4 = new QTableWidgetItem();
            item4->setText(buku->author);
            ui->tableWidget->setItem(i, 3, item4);
            QButtonGroup *buttonGroup = new QButtonGroup(this);
            QPushButton *btn_pinjam = new QPushButton("Pinjam");
            QPushButton *btn_delete = new QPushButton("Delete");
            connect(btn_delete, &QPushButton::released, this,
                    [this, buku]()
                    {
                        // handleButtonDelete(i);
                        handleButtonDelete(buku->id);
                    });
            connect(btn_pinjam, &QPushButton::released, this,
                    [this, buku]()
                    {
                        // handleButtonDelete(i);
                        handleButtonPinjam(buku);
                    });
            QWidget *buttonWidget = new QWidget();
            QHBoxLayout *layout = new QHBoxLayout(buttonWidget);
            layout->addWidget(btn_pinjam);
            layout->addWidget(btn_delete);
            layout->setAlignment(Qt::AlignLeft);
            layout->setSpacing(0);
            layout->setContentsMargins(0, 0, 0, 0);
            buttonWidget->setLayout(layout);
            ui->tableWidget->setCellWidget(i, 4, buttonWidget);
            ui->tableWidget->setColumnWidth(4,150);
            i++;
        }
        buku = buku->next;
    }
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    finishRenderTable = true;
}

void buku::on_bukuBaru_clicked()
{
    bukuBaru *b = new bukuBaru(dataBuku, dataPeminjaman, dataAnggota);
    b->show();
    b->setGeometry(300, 150, 900, 600);
    this->close();
}

void buku::on_peminjaman_clicked()
{

}


void buku::on_pushButton_2_clicked()
{
    Library *back = new Library();
    back->show();
    back->setGeometry(300, 150, 900, 600);
    this->close();
}


void buku::on_peminjaman2_clicked()
{
    peminjaman *bukuPeminjaman = new peminjaman(dataBuku, dataPeminjaman, dataAnggota);
    bukuPeminjaman->show();
    bukuPeminjaman->setGeometry(300, 150, 900, 600);
    this->close();
}


void buku::on_anggota2_clicked()
{
    anggota *bukuAnggota = new anggota(dataBuku, dataPeminjaman, dataAnggota);
    bukuAnggota->show();
    bukuAnggota->setGeometry(300, 150, 900, 600);
    this->close();
}


void buku::on_searchButton_clicked()
{
    this->searchQuery = ui->searchInput->text();
    refreshTable();
}


void buku::on_tableWidget_cellChanged(int row, int column)
{
    if (finishRenderTable) {
        int i = 0;
        QString val = ui->tableWidget->item(row, column)->text();
        dataBuku->updateData(row, column, val, dataPeminjaman);
    }
}

void buku::handleButtonDelete(int id) {
    Buku *temp = dataBuku->head;
    dataBuku->deleteData(id, dataPeminjaman);
    refreshTable();
}

void buku::handleButtonPinjam(Buku *buku) {
    inputPeminjaman *ip = new inputPeminjaman(buku, dataBuku,dataPeminjaman,dataAnggota);
    ip->show();
    ip->setGeometry(300, 150, 900, 600);
    this->close();
}


void buku::on_searchInput_returnPressed()
{
    searchQuery = ui->searchInput->text();
    refreshTable();
}

