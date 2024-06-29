#ifndef DATAPEMINJAMAN_H
#define DATAPEMINJAMAN_H

#include <QObject>
#include <QDateTime>

struct Peminjaman {
    int id;
    QString nama;
    QString judulBuku;
    int idBuku;
    QDateTime waktuPengembalian;
    QString status;
    struct Peminjaman *next;
    struct Peminjaman *prev;
};

class DataPeminjaman : public QObject
{
    Q_OBJECT
public:
    explicit DataPeminjaman(QObject *parent = nullptr);
    Peminjaman *head;
    QString filePath = "C:/Users/kadek/Documents/LibraryManagement/data-peminjaman.txt";
    QString timeFormat = "yyyy-MM-dd HH:mm:ss";
    int count;
    void getData();
    void createData(QString nama, QString judulBuku, int idBuku);
    // void updateData(int row, int col, QString value);
    // void deleteData(int id);
    void refreshData();
    void returnBook(int id);
    void searchData(QString query);

signals:
};

#endif // DATAPEMINJAMAN_H
