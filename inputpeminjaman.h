#ifndef INPUTPEMINJAMAN_H
#define INPUTPEMINJAMAN_H

#include <QMainWindow>
#include "databuku.h"
#include "dataanggota.h"
#include "datapeminjaman.h"

namespace Ui {
class inputPeminjaman;
}

class inputPeminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit inputPeminjaman(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent = nullptr);
    ~inputPeminjaman();

private slots:
    void on_confirmPeminjaman_rejected();

private:
    Ui::inputPeminjaman *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
};

#endif // INPUTPEMINJAMAN_H
