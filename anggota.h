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
    void on_anggotaBuku_clicked();
    void on_anggotaLibrary_clicked();
    void on_anggotaPeminjaman_clicked();
    void refreshTable();
    void handleButtonDelete(QString nim);
    void on_anggotaBaru_clicked();

    void on_cariAnggota_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_searchAnggota_returnPressed();

private:
    Ui::anggota *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
    QString searchQuery;

    bool finishRenderTable;
};

#endif // ANGGOTA_H
