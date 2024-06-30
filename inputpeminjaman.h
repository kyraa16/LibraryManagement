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
    explicit inputPeminjaman(Buku *selectedBook, DataBuku *dataBuku, DataPeminjaman *dataPeminjaman, DataAnggota *dataAnggota, QWidget *parent = nullptr);
    ~inputPeminjaman();
    void showTabelAnggota();

private slots:
    void on_confirmPeminjaman_rejected();
    void handleButtonPilih(Anggota *anggota, int row);

    void on_confirmPeminjaman_accepted();

    void on_searchButton_clicked();

    void on_searchInput_returnPressed();

private:
    Ui::inputPeminjaman *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
    QString searchQuery;
    Buku *selectedBook;
    Anggota *selectedAnggota = NULL;
};

#endif // INPUTPEMINJAMAN_H
