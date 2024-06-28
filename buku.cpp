#include "buku.h"
#include "ui_buku.h"
#include <QPixmap>
#include "bukubaru.h"
#include "library.h"
#include "peminjaman.h"
#include "anggota.h"
#include "databuku.h"
#include "bukubaru.h"

buku::buku(DataBuku *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buku)
{
    this->dataBuku = data;
    // this->setGeometry(0,0,900,900);
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    QStringList columnNames;
    columnNames<<"ID"<<"Judul"<<"Penerbit"<<"Author"<<"Aksi";
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(columnNames);
    refreshTable();
}

buku::~buku()
{
    delete ui;
}

void buku::refreshTable()
{
    // searchResult = dataMhs->head;
    struct Buku *buku = this->dataBuku->head;
    int i = 0;
    ui->tableWidget->setRowCount(this->dataBuku->count-1);
    QTableWidget *currentTable = ui->tableWidget;
    while (buku != NULL) {
        if (buku->id == searchQuery.toInt() || searchQuery == "") {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(QString::number(buku->id));
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
            QPushButton *btn_delete;
            btn_delete = new QPushButton();
            btn_delete->setText("Delete");
            connect(btn_delete, &QPushButton::released, this,
                    [this, buku]()
                    {
                        // handleButtonDelete(i);
                        handleButtonDelete(buku->id);
                    });
            ui->tableWidget->setCellWidget(i,4,(QWidget*)btn_delete);
            i++;
        }
        buku = buku->next;
    }
    ui->tableWidget->setRowCount(i);
    finishRenderTable = true;
    qInfo()<<i;
}

void buku::on_bukuBaru_clicked()
{
    bukuBaru *b = new bukuBaru(dataBuku);
    b->show();
    b->setGeometry(300, 150, 900, 600);
    this->close();
}

void buku::on_peminjaman_clicked()
{
    inputPeminjaman *p = new inputPeminjaman(dataBuku);
    p->show();
    p->setGeometry(300, 150, 900, 600);
    this->close();
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
    peminjaman *bukuPeminjaman = new peminjaman(dataBuku);
    bukuPeminjaman->show();
    bukuPeminjaman->setGeometry(300, 150, 900, 600);
    this->close();
}


void buku::on_anggota2_clicked()
{
    anggota *bukuAnggota = new anggota(dataBuku);
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
        dataBuku->updateBuku(row, column, val);
    }
}

void buku::handleButtonDelete(int id) {
    int row = -1;
    Buku *temp = dataBuku->head;
    dataBuku->deleteBuku(id);
    refreshTable();
    // dataMhs->cetakData();
}

