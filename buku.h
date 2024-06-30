#ifndef BUKU_H
#define BUKU_H

#include <QMainWindow>
#include "bukubaru.h"
#include "inputpeminjaman.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

namespace Ui {
class buku;
}

class buku : public QMainWindow
{
    Q_OBJECT

public:
    explicit buku(DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent = nullptr);
    ~buku();

private slots:
    void on_bukuBaru_clicked();

    void on_peminjaman_clicked();

    void on_pushButton_2_clicked();
    void on_peminjaman2_clicked();

    void on_anggota2_clicked();
    void refreshTable();

    void on_searchButton_clicked();

    void on_tableWidget_cellChanged(int row, int column);
    void handleButtonDelete(int id);
    void handleButtonPinjam(Buku *buku);

private:
    Ui::buku *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
    QString searchQuery;
    bool finishRenderTable;
};

#endif // BUKU_H
