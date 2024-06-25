#ifndef BUKU_H
#define BUKU_H

#include <QMainWindow>
#include "bukubaru.h"
#include "inputpeminjaman.h"

namespace Ui {
class buku;
}

class buku : public QMainWindow
{
    Q_OBJECT

public:
    explicit buku(QWidget *parent = nullptr);
    ~buku();

private slots:
    void on_bukuBaru_clicked();

    void on_peminjaman_clicked();

private:
    Ui::buku *ui;
    bukuBaru b;
    inputPeminjaman p;
};

#endif // BUKU_H
