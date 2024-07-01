#include "dataanggota.h"
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>

DataAnggota::DataAnggota(QObject *parent)
    : QObject{parent}
{
    getData();
}

void DataAnggota::getData()
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    int c = 1;
    struct Anggota *currentHead = NULL, *temp = NULL;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.count() == 2) {
            struct Anggota *node = new Anggota();
            node->nama = fields[0];
            node->nim = fields[1];
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

void DataAnggota::createData(QString nama, QString nim)
{
    Anggota *anggotaBaru = new Anggota();
    anggotaBaru->nama = nama;
    anggotaBaru->nim = nim;
    anggotaBaru->next = head;
    anggotaBaru->prev = NULL;
    if (head != NULL)
        head->prev = anggotaBaru;
    head = anggotaBaru;
    count++;
    QFile file(filePath);
    QString str = "";
    Anggota *temp = head;
    int i = 0;
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            out<<temp->nama<<","<<temp->nim<<"\n";
            temp = temp->next;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataAnggota::updateData(int row, int col, QString value, DataPeminjaman *dataPeminjaman)
{
    QFile file(filePath);
    QString str = "";
    Anggota *temp = head;
    int i = 0;
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            if (i == row) {
                if (col == 0) {
                    dataPeminjaman->updateData("nimAnggota", temp->nim,"namaAnggota",value);
                    temp->nama = value;
                }
                else if (col == 1) {
                    dataPeminjaman->updateData("nimAnggota", temp->nim,"nimAnggota",value);
                    temp->nim = value;
                }
            }
            out<<temp->nama<<","<<temp->nim<<"\n";
            temp = temp->next;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataAnggota::deleteData(QString nim, DataPeminjaman *dataPeminjaman) {
    Anggota *temp = head, *hapus;
    int i = 0;
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            if (temp->nim == nim) {
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
                dataPeminjaman->deleteByAnggota(nim);
                count--;
            } else {
                out<<temp->nama<<","<<temp->nim<<"\n";
                temp = temp->next;
            }
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}
