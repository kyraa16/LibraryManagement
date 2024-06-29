#ifndef DATABUKU_H
#define DATABUKU_H

#include <QObject>

struct Buku {
    int id;
    QString judul;
    QString penerbit;
    QString author;
    struct Buku *next;
    struct Buku *prev;
    Buku(){}
};

class DataBuku : public QObject
{
    Q_OBJECT
public:
    explicit DataBuku(QObject *parent = nullptr);
    Buku *head;
    QString filePath = "C:/Users/kadek/Documents/LibraryManagement/data-buku.txt";
    int count;
    void getData();
    void createData(QString judul, QString penerbit, QString author);
    void updateData(int row, int col, QString value);
    void deleteData(int id);
    void searchData(QString query);

signals:
};

#endif // DATABUKU_H
