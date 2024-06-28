#ifndef BUKU_H
#define BUKU_H

#include <QMainWindow>
#include "bukubaru.h"
#include "inputpeminjaman.h"
#include "databuku.h"

namespace Ui {
class buku;
}

class buku : public QMainWindow
{
    Q_OBJECT

public:
    explicit buku(DataBuku *dataBuku, QWidget *parent = nullptr);
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

private:
    Ui::buku *ui;
    DataBuku *dataBuku;
    QString searchQuery;
    bool finishRenderTable;
};

#endif // BUKU_H
