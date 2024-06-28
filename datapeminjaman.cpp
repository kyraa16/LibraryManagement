// #include "datapeminjaman.h"
// #include <QFile>
// #include <QIODevice>
// #include <QTextStream>
// #include <QMessageBox>
// #include <QDateTime>

// DataPeminjaman::DataPeminjaman(QObject *parent)
//     : QObject{parent}
// {}

// void DataPeminjaman::getData()
// {
//     QFile file(filePath);
//     if(!file.open(QIODevice::ReadOnly)) {
//         QMessageBox::information(0, "error", file.errorString());
//     }
//     QTextStream in(&file);
//     int c = 1;
//     struct Peminjaman *currentHead = NULL, *temp = NULL;
//     while(!in.atEnd()) {
//         QString line = in.readLine();
//         QStringList fields = line.split(",");
//         if (currentHead == NULL) {
//             currentHead = new Peminjaman();
//             currentHead->id = fields[0].toInt();
//             currentHead->nama = fields[1];
//             currentHead->judulBuku = fields[2];
//             currentHead->idBuku = fields[3].toInt();
//             currentHead->next = NULL;
//             currentHead->prev = NULL;
//             temp = currentHead;
//         } else {
//             struct Peminjaman *node = new Buku();
//             qInfo()<<fields[0];
//             node->id = fields[0].toInt();
//             node->judul = fields[1];
//             node->penerbit = fields[2];
//             node->author = fields[3];
//             node->next = NULL;
//             node->prev = temp;
//             temp->next = node;
//             temp = node;
//         }
//         c++;
//     }
//     file.close();
//     head = currentHead;
//     count = c;
// }

// void DataPeminjaman::createBuku(QString judul, QString penerbit, QString author)
// {
//     Buku *bukuBaru = new Buku();
//     bukuBaru->id = QDateTime::currentSecsSinceEpoch();
//     bukuBaru->judul = judul;
//     bukuBaru->penerbit = penerbit;
//     bukuBaru->author = author;
//     bukuBaru->next = head;
//     bukuBaru->prev = NULL;
//     head->prev = bukuBaru;
//     head = bukuBaru;
//     count++;
//     QFile file(filePath);
//     QString str = "";
//     Buku *temp = head;
//     int i = 0;
//     if(file.open(QIODevice::ReadWrite)) {
//         // qInfo()<<str;
//         // file.write(str.toUtf8());
//         QTextStream out(&file);
//         while (temp != NULL) {
//             out<<QString::number(temp->id)<<","<<temp->judul<<","<<temp->penerbit<<","<<temp->author<<"\n";
//             temp = temp->next;
//             i++;
//         }
//     } else {
//         QMessageBox::information(0, "error", file.errorString());
//     }
//     file.close();
// }

// void DataPeminjaman::updateBuku(int row, int col, QString value)
// {
//     QFile file(filePath);
//     QString str = "";
//     Buku *temp = head;
//     int i = 0;
//     if(file.open(QIODevice::ReadWrite)) {
//         // qInfo()<<str;
//         // file.write(str.toUtf8());
//         QTextStream out(&file);
//         while (temp != NULL) {
//             if (i == row) {
//                 if (col == 1)
//                     temp->judul = value;
//                 else if (col == 2)
//                     temp->penerbit = value;
//                 else if (col == 3)
//                     temp->author = value;
//             }
//             // str += QString::number(temp->id) + "," + temp->judul + "," + temp->penerbit + "," + temp->author + "\n";
//             out<<QString::number(temp->id)<<","<<temp->judul<<","<<temp->penerbit<<","<<temp->author<<"\n";
//             temp = temp->next;
//             i++;
//         }
//     } else {
//         QMessageBox::information(0, "error", file.errorString());
//     }
//     file.close();
// }

// void DataPeminjaman::deleteBuku(int id) {
//     Buku *temp = head, *hapus;
//     int i = 0, deletedIndex = 0;
//     bool deleted = false;
//     // if (temp->nim == nim) {
//     //     qInfo()<<"Delete row : "<<nim.compare(temp->nim);
//     // }
//     // qInfo()<<"Delete row : "<<nim.compare(temp->nim);
//     QFile file(filePath);
//     QString str = "";
//     if(file.open(QIODevice::WriteOnly)) {
//         qInfo()<<str;
//         // file.write("");
//         // file.write(str.toUtf8());
//         QTextStream out(&file);
//         // out<<str;
//         while (temp != NULL) {
//             if (temp->id == id) {
//                 // qInfo()<<nim;
//                 if (temp == head) {
//                     hapus = temp;
//                     temp = head = head->next;
//                     delete hapus;
//                 } else if (temp->next == NULL) {
//                     hapus = temp;
//                     temp->prev->next = temp->next;
//                     temp = temp->next;
//                     delete hapus;
//                 }
//                 else {
//                     hapus = temp;
//                     temp->prev->next = temp->next;
//                     temp->next->prev = temp->prev;
//                     temp = temp->next;
//                     delete hapus;
//                 }
//                 count--;
//                 deleted = true;
//             } else {
//                 out<<QString::number(temp->id)<<","<<temp->judul<<","<<temp->penerbit<<","<<temp->author<<"\n";
//                 temp = temp->next;
//             }
//             deletedIndex += deleted ? 0 : 1;
//             i++;
//         }
//     } else {
//         QMessageBox::information(0, "error", file.errorString());
//     }
//     file.close();
//     // return deletedIndex;
//     // cetakData();
// }
