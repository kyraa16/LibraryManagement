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

private slots:
    void on_confirmAnggota_rejected();

    void on_confirmAnggota_accepted();

    void on_inputNama_returnPressed();

    void on_inputNim_returnPressed();

private:
    Ui::inputAnggota *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
    bool validateInput();
    void submitForm();
};

#endif // INPUTANGGOTA_H
