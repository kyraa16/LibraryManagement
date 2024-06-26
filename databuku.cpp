#include "databuku.h"
#include "datapeminjaman.h"
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>

DataBuku::DataBuku(QObject *parent)
    : QObject{parent}
{
    this->getData();
}

void DataBuku::getData()
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    int c = 1;
    struct Buku *currentHead = NULL, *temp = NULL;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.count() == 4) {
            struct Buku *node = new Buku();
            node->id = fields[0].toInt();
            node->judul = fields[1];
            node->penerbit = fields[2];
            node->author = fields[3];
            node->next = NULL;
            if (currentHead == NULL) {
                temp = currentHead = node;
                currentHead->prev = NULL;
            } else {
                node->prev = temp;
                temp->next = node;
                temp = node;
            }
            c++;
        }
    }
    file.close();
    head = currentHead;
    count = c;
}

void DataBuku::createData(QString judul, QString penerbit, QString author)
{
    Buku *bukuBaru = new Buku();
    bukuBaru->id = QDateTime::currentSecsSinceEpoch();
    bukuBaru->judul = judul;
    bukuBaru->penerbit = penerbit;
    bukuBaru->author = author;
    bukuBaru->next = head;
    bukuBaru->prev = NULL;
    if (head != NULL)
        head->prev = bukuBaru;
    head = bukuBaru;
    count++;
    QFile file(filePath);
    QString str = "";
    Buku *temp = head;
    int i = 0;
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            out<<QString::number(temp->id)<<","<<temp->judul<<","<<temp->penerbit<<","<<temp->author<<"\n";
            temp = temp->next;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataBuku::updateData(int row, int col, QString value, DataPeminjaman *dataPeminjaman)
{
    QFile file(filePath);
    Buku *temp = head;
    int i = 0;
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            if (i == row) {
                if (col == 1) {
                    temp->judul = value;
                    dataPeminjaman->updateData("idBuku", QString::number(temp->id), "judul", value);
                }
                else if (col == 2)
                    temp->penerbit = value;
                else if (col == 3)
                    temp->author = value;
            }
            out<<QString::number(temp->id)<<","<<temp->judul<<","<<temp->penerbit<<","<<temp->author<<"\n";
            temp = temp->next;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataBuku::deleteData(int id, DataPeminjaman *dataPeminjaman) {
    Buku *temp = head, *hapus;
    int i = 0;
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            if (temp->id == id) {
                dataPeminjaman->deleteByBuku(temp->id);
                if (temp == head) {
                    hapus = temp;
                    temp = head = head->next;
                    delete hapus;
                } else if (temp->next == NULL) {
                    hapus = temp;
                    temp->prev->next = temp->next;
                    temp = temp->next;
                    delete hapus;
                }
                else {
                    hapus = temp;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp = temp->next;
                    delete hapus;
                }
                count--;
            } else {
                out<<QString::number(temp->id)<<","<<temp->judul<<","<<temp->penerbit<<","<<temp->author<<"\n";
                temp = temp->next;
            }
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}
