#ifndef INPUTANGGOTA_H
#define INPUTANGGOTA_H

#include <QMainWindow>
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

namespace Ui {
class inputAnggota;
}

class inputAnggota : public QMainWindow
{
    Q_OBJECT

public:
    explicit inputAnggota(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent = nullptr);
    ~inputAnggota();

private:
    Ui::inputAnggota *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
};

#endif // INPUTANGGOTA_H
