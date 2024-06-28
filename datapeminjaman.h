// #ifndef DATAPEMINJAMAN_H
// #define DATAPEMINJAMAN_H

// #include <QObject>

// struct Peminjaman {
//     int id;
//     QString nama;
//     QString judulBuku;
//     int idBuku;
//     bool status;
//     struct Peminjaman *next;
//     struct Peminjaman *prev;
// };

// class DataPeminjaman : public QObject
// {
//     Q_OBJECT
// public:
//     explicit DataPeminjaman(QObject *parent = nullptr);
//     Peminjaman *head;
//     QString filePath = "C:/Users/kadek/Documents/LibraryManagement/data-peminjaman.txt";
//     int count;
//     void getData();
//     void createPeminjaman(QString nama, QString judulBuku, int idBuku);
//     void updatePeminjaman(int row, int col, QString value);
//     void deletePeminjaman(int id);
//     void searchData(QString query);

// signals:
// };

// #endif // DATAPEMINJAMAN_H
