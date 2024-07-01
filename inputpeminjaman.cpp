#include "inputpeminjaman.h"
#include "ui_inputpeminjaman.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include "buku.h"
#include "listpeminjaman.h"
#include <QMessageBox>

inputPeminjaman::inputPeminjaman(Buku *selectedBook, DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputPeminjaman)
{
    this->dataBuku = dataBuku;
    this->dataPeminjaman = dataPeminjaman;
    this->dataAnggota = dataAnggota;
    this->selectedBook = selectedBook;
    ui->setupUi(this);
    ui->judulBuku->setText(selectedBook->judul);
    ui->idBuku->setText(QString::number(selectedBook->id));
    QLocale locale(QLocale("id_ID"));
    QDateTime waktu = QDate::currentDate().addDays(60).endOfDay();
    ui->waktuPengembalian->setText(locale.toString(waktu, "d MMMM yyyy"));
    ui->tableWidget->setColumnCount(3);
    QStringList columnNames;
    columnNames<<"Nama Anggota"<<"NIM"<<"Aksi";
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(columnNames);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    showTabelAnggota();
}

inputPeminjaman::~inputPeminjaman()
{
    delete ui;
}

void inputPeminjaman::showTabelAnggota()
{
    struct Anggota *anggota = this->dataAnggota->head;
    int i = 0;
    ui->tableWidget->setRowCount(this->dataBuku->count);
    QTableWidget *currentTable = ui->tableWidget;
    while (anggota != NULL) {
        if (anggota->nim.contains(searchQuery) || anggota->nama.contains(searchQuery, Qt::CaseInsensitive)) {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(anggota->nama);
            ui->tableWidget->setItem(i, 0, item);
            QTableWidgetItem* item2 = new QTableWidgetItem();
            item2->setText(anggota->nim);
            ui->tableWidget->setItem(i, 1, item2);

            QPushButton *btn_pilih;
            btn_pilih = new QPushButton();
            btn_pilih->setText("Pilih");
            connect(btn_pilih, &QPushButton::released, this,
                    [this, anggota, i]()
                    {
                        handleButtonPilih(anggota, i);
                    });
            ui->tableWidget->setCellWidget(i,2,(QWidget*)btn_pilih);
            i++;
        }
        anggota = anggota->next;
    }
    ui->tableWidget->setColumnWidth(2, 80);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget->setRowCount(i);
}

void inputPeminjaman::handleButtonPilih(Anggota *anggota, int row)
{
    ui->namaAnggota->setText(anggota->nama);
    ui->tableWidget->selectRow(row);
    this->selectedAnggota = anggota;
}

void inputPeminjaman::on_confirmPeminjaman_rejected()
{
    buku *cancelBuku = new buku(dataBuku, dataPeminjaman, dataAnggota);
    cancelBuku->show();
    cancelBuku->setGeometry(300, 150, 900, 600);
    this->close();
}


void inputPeminjaman::on_confirmPeminjaman_accepted()
{
    if (selectedAnggota != NULL) {
        bool success = dataPeminjaman->createData(selectedAnggota->nama, selectedAnggota->nim, selectedBook->judul, selectedBook->id);
        if (success) {
            QMessageBox::information(0,"Tambah Peminjaman", "Data peminjaman berhasil ditambah!");
            listPeminjaman *lp = new listPeminjaman(dataBuku, dataPeminjaman, dataAnggota);
            lp->show();
            this->close();
        }
        else
            QMessageBox::critical(NULL,"Tambah Peminjaman", "Anggota ini sedang meminjam buku yang sama");
    } else {
        QMessageBox::critical(this,"Tambah Peminjaman", "Pilih anggota terlebih dahulu!");
    }
}


void inputPeminjaman::on_searchButton_clicked()
{
    searchQuery = ui->searchInput->text();
    showTabelAnggota();
}


void inputPeminjaman::on_searchInput_returnPressed()
{
    searchQuery = ui->searchInput->text();
    showTabelAnggota();
}

