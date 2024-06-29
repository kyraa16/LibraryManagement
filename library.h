#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include "buku.h"
#include "peminjaman.h"
#include "anggota.h"
#include "databuku.h"
#include "datapeminjaman.h"
#include "dataanggota.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Library;
}
QT_END_NAMESPACE

class Library : public QMainWindow
{
    Q_OBJECT

public:
    Library(QWidget *parent = nullptr);
    ~Library();

private slots:
    void on_bukuButton_clicked();

    void on_peminjamanButton_clicked();

    void on_anggota_clicked();

private:
    Ui::Library *ui;
    DataBuku *dataBuku;
    DataPeminjaman *dataPeminjaman;
    DataAnggota *dataAnggota;
};
#endif // LIBRARY_H
