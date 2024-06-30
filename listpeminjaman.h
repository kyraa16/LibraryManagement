#ifndef LISTPEMINJAMAN_H
#define LISTPEMINJAMAN_H

#include <QMainWindow>
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"
#include <QPushButton>

namespace Ui {
class listPeminjaman;
}

class listPeminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit listPeminjaman(DataBuku *data, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent = nullptr);
    ~listPeminjaman();
    void refreshTable();

private slots:
    // void on_tableWidget_cellChanged(int row, int column);
    void handleButtonReturn(int id, QPushButton *btn_kembali);

    void on_backPeminjaman_clicked();

private:
    Ui::listPeminjaman *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
    QString searchQuery = "";
    bool finishRenderTable = false;
};

#endif // LISTPEMINJAMAN_H
