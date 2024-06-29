#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H

#include <QMainWindow>
#include "listpeminjaman.h"
#include "buku.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

namespace Ui {
class peminjaman;
}

class peminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit peminjaman(DataBuku *data, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent = nullptr);
    ~peminjaman();

private slots:

    void on_listPinjam_clicked();

    void on_pinjamBuku_clicked();

    void on_back2_clicked();

    void on_peminjamanBuku_clicked();

    void on_peminjamanAnggota_clicked();

private:
    Ui::peminjaman *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
};

#endif // PEMINJAMAN_H
