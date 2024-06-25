#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H

#include <QMainWindow>
#include "listpeminjaman.h"
#include "buku.h"

namespace Ui {
class peminjaman;
}

class peminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit peminjaman(QWidget *parent = nullptr);
    ~peminjaman();

private slots:
    void on_pushButton_4_clicked();

    void on_listPinjam_clicked();

    void on_pinjamBuku_clicked();

private:
    Ui::peminjaman *ui;
    listPeminjaman lp;
    buku pb;
};

#endif // PEMINJAMAN_H
