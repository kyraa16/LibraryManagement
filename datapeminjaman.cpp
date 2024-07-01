#include "datapeminjaman.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>

DataPeminjaman::DataPeminjaman(QObject *parent)
    : QObject{parent}
{
    getData();
}

void DataPeminjaman::getData()
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    int c = 1;
    bool isThereChange = false;
    struct Peminjaman *currentHead = NULL, *temp = NULL;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.count() == 7) {
            struct Peminjaman *node = new Peminjaman();
            node->id = fields[0].toInt();
            node->namaAnggota = fields[1];
            node->nimAnggota = fields[2];
            node->judulBuku = fields[3];
            node->idBuku = fields[4].toInt();
            node->waktuPengembalian = QDateTime::fromString(fields[5], timeFormat);
            if (fields[6] != "Dikembalikan" && node->waktuPengembalian < QDateTime::currentDateTime()) {
                node->status = "Lewat Batas Waktu";
                isThereChange = true;
            }
            else
                node->status = fields[6];
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
    if (isThereChange)
        refreshData();
}

bool DataPeminjaman::createData(QString namaAnggota, QString nimAnggota, QString judulBuku, int idBuku)
{
    Peminjaman *tempSearch = head;
    while (tempSearch != NULL && !(tempSearch->idBuku == idBuku && tempSearch->nimAnggota == nimAnggota && tempSearch->status != "Dikembalikan"))
        tempSearch = tempSearch->next;
    if (tempSearch == NULL) {
        Peminjaman *peminjamanBaru = new Peminjaman();
        peminjamanBaru->id = QDateTime::currentSecsSinceEpoch();
        peminjamanBaru->namaAnggota = namaAnggota;
        peminjamanBaru->nimAnggota = nimAnggota;
        peminjamanBaru->judulBuku = judulBuku;
        peminjamanBaru->idBuku = idBuku;
        peminjamanBaru->status = "Sedang Dipinjam";
        peminjamanBaru->waktuPengembalian = QDate::currentDate().addDays(60).endOfDay();
        peminjamanBaru->next = head;
        peminjamanBaru->prev = NULL;
        if (head != NULL)
            head->prev = peminjamanBaru;
        head = peminjamanBaru;
        count++;
        QFile file(filePath);
        QString str = "";
        Peminjaman *temp = head;
        int i = 0;
        if(file.open(QIODevice::ReadWrite  | QIODevice::Truncate)) {
            QTextStream out(&file);
            while (temp != NULL) {
                out<<"";
                out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
                temp = temp->next;
                i++;
            }
        } else {
            QMessageBox::information(0, "error", file.errorString());
        }
        file.close();
    }
    return tempSearch == NULL;
}

void DataPeminjaman::refreshData()
{
    QFile file(filePath);
    file.resize(0);
    Peminjaman *temp = head;
    int i = 0;
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
            temp = temp->next;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataPeminjaman::updateData(QString keySearch, QString valueSearch, QString keyToUpdate, QString valueToUpdate)
{
    QFile file(filePath);
    Peminjaman *temp = head;
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            if (keySearch == "nimAnggota" && temp->nimAnggota == valueSearch)
                if (keyToUpdate == "namaAnggota")
                    temp->namaAnggota = valueToUpdate;
                else
                    temp->nimAnggota = valueToUpdate;
            else if(keySearch == "idBuku" && QString::number(temp->idBuku) == valueSearch)
                temp->judulBuku = valueToUpdate;
            out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
            temp = temp->next;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataPeminjaman::deleteByBuku(int idBuku) {
    Peminjaman *temp = head, *hapus;
    int i = 0;
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            if (temp->idBuku == idBuku) {
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
                out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
                temp = temp->next;
            }
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataPeminjaman::deleteByAnggota(QString nim) {
    Peminjaman *temp = head, *hapus;
    int i = 0;
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            if (temp->nimAnggota == nim) {
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
                out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
                temp = temp->next;
            }
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataPeminjaman::returnBook(int id)
{
    QFile file(filePath);
    Peminjaman *temp = head;
    int i = 0;
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        while (temp != NULL) {
            out<<"";
            if (temp->id == id) {
                temp->status = "Dikembalikan";
                temp->waktuPengembalian = QDateTime::currentDateTime();
            }
            out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
            temp = temp->next;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}
