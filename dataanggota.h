#ifndef DATAANGGOTA_H
#define DATAANGGOTA_H

#include <QObject>

struct Anggota {
    QString nama;
    QString nim;
    struct Anggota *next;
    struct Anggota *prev;
    Anggota(){}
};

class DataAnggota : public QObject
{
    Q_OBJECT
public:
    explicit DataAnggota(QObject *parent = nullptr);
    Anggota *head;
    QString filePath = "C:/Made Aditya/Sublime Text/Belajar C - C++/qt-app/LibraryManagement/data-anggota.txt";
    int count;
    void getData();
    void createData(QString nama, QString nim);
    void updateData(int row, int col, QString value);
    void deleteData(QString nim);
    void searchData(QString query);

signals:
};

#endif // DATAANGGOTA_H