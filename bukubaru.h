#ifndef BUKUBARU_H
#define BUKUBARU_H

#include <QMainWindow>
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

namespace Ui {
class bukuBaru;
}

class bukuBaru : public QMainWindow
{
    Q_OBJECT

public:
    explicit bukuBaru(DataBuku *data, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent = nullptr);
    ~bukuBaru();

private slots:

    void on_tambahBuku_rejected();

    void on_tambahBuku_accepted();

private:
    Ui::bukuBaru *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
};

#endif // BUKUBARU_H
