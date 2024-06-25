#include "buku.h"
#include "ui_buku.h"
#include <QPixmap>
#include "bukubaru.h"

buku::buku(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buku)
{
    // this->setGeometry(0,0,900,900);
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    QStringList columnNames;
    columnNames<<"Nama"<<"NIM"<<"Aksi";
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(columnNames);
    int i = 0;
    for (int i = 0; i < 10; i++) {
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText("Made Aditya");
        ui->tableWidget->setItem(i, 0, item);
        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText("2308561015");
        ui->tableWidget->setItem(i, 1, item2);
        QPushButton* btn_delete;
        btn_delete = new QPushButton();
        btn_delete->setText("Delete");
        ui->tableWidget->setCellWidget(i,2,(QWidget*)btn_delete);
    }
}

buku::~buku()
{
    delete ui;
}

void buku::on_bukuBaru_clicked()
{
    b.show();
    b.setGeometry(300, 150, 900, 600);
    // this->close();
}

void buku::on_peminjaman_clicked()
{
    p.show();
    p.setGeometry(300, 150, 900, 600);
    //this->close();
}

