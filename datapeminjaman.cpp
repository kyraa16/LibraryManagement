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
            // if (currentHead == NULL) {
            //     currentHead = new Peminjaman();
            //     currentHead->id = fields[0].toInt();
            //     currentHead->namaAnggota = fields[1];
            //     currentHead->judulBuku = fields[2];
            //     currentHead->idBuku = fields[3].toInt();
            //     currentHead->waktuPengembalian = QDateTime::fromString(fields[4], timeFormat);
            //     if (fields[5] != "Dikembalikan" && currentHead->waktuPengembalian < QDateTime::currentDateTime())
            //         currentHead->status = "Lewat Batas Waktu";
            //     else
            //         currentHead->status = fields[5];
            //     currentHead->next = NULL;
            //     currentHead->prev = NULL;
            //     temp = currentHead;
            // } else {
            //     struct Peminjaman *node = new Peminjaman();
            //     qInfo()<<fields[0];
            //     node->id = fields[0].toInt();
            //     node->namaAnggota = fields[1];
            //     node->judulBuku = fields[2];
            //     node->idBuku = fields[3].toInt();
            //     node->waktuPengembalian = QDateTime::fromString(fields[4], timeFormat);
            //     if (fields[5] != "Dikembalikan" && node->waktuPengembalian < QDateTime::currentDateTime())
            //         node->status = "Lewat Batas Waktu";
            //     else
            //         node->status = fields[5];
            //     node->next = NULL;
            //     node->prev = temp;
            //     temp->next = node;
            //     temp = node;
            // }
            c++;
        }
    }
    file.close();
    head = currentHead;
    count = c;
    if (isThereChange)
        refreshData();
}

void DataPeminjaman::createData(QString namaAnggota, QString nimAnggota, QString judulBuku, int idBuku)
{
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

void DataPeminjaman::refreshData()
{
    QFile file(filePath);
    file.resize(0);
    QString str = "";
    Peminjaman *temp = head;
    int i = 0;
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
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

void DataPeminjaman::deleteByBuku(int idBuku) {
    Peminjaman *temp = head, *hapus;
    int i = 0, deletedIndex = 0;
    bool deleted = false;
    QFile file(filePath);
    QString str = "";
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qInfo()<<str;
        QTextStream out(&file);
        while (temp != NULL) {
            if (temp->idBuku == idBuku) {
                // qInfo()<<nim;
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
                deleted = true;
            } else {
                out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
                temp = temp->next;
            }
            deletedIndex += deleted ? 0 : 1;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
    // return deletedIndex;
}

void DataPeminjaman::deleteByAnggota(QString nim) {
    Peminjaman *temp = head, *hapus;
    int i = 0, deletedIndex = 0;
    bool deleted = false;
    QFile file(filePath);
    QString str = "";
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qInfo()<<str;
        QTextStream out(&file);
        while (temp != NULL) {
            if (temp->nimAnggota == nim) {
                // qInfo()<<nim;
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
                deleted = true;
            } else {
                out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
                temp = temp->next;
            }
            deletedIndex += deleted ? 0 : 1;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
    // return deletedIndex;
}

void DataPeminjaman::returnBook(int id)
{
    QFile file(filePath);
    QString str = "";
    Peminjaman *temp = head;
    int i = 0;
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.write("");
        QTextStream out(&file);
        while (temp != NULL) {
            out<<"";
            if (temp->id == id) {
                temp->status = "Dikembalikan";
                temp->waktuPengembalian = QDateTime::currentDateTime();
            }
            out<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->nimAnggota<<","<<temp->judulBuku<<","<<temp->idBuku<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
            // qInfo()<<QString::number(temp->id)<<","<<temp->namaAnggota<<","<<temp->judulBuku<<","<<QString::number(temp->idBuku)<<","<<temp->waktuPengembalian.toString(timeFormat)<<","<<temp->status<<"\n";
            temp = temp->next;
            i++;
        }
        qInfo()<<i;
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}
