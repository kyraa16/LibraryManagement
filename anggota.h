#ifndef ANGGOTA_H
#define ANGGOTA_H

#include <QMainWindow>
#include "inputanggota.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

namespace Ui {
class anggota;
}

class anggota : public QMainWindow
{
    Q_OBJECT

public:
    explicit anggota(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent = nullptr);
    ~anggota();

private slots:
    void on_anggotaBaru_clicked();

    void on_anggotaLibrary_clicked();

    void on_anggotaBuku_clicked();

    void on_anggotaPeminjaman_clicked();

private:
    Ui::anggota *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
};

#endif // ANGGOTA_H
