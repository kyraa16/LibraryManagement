#ifndef LISTPEMINJAMAN_H
#define LISTPEMINJAMAN_H

#include <QMainWindow>
#include "databuku.h"

namespace Ui {
class listPeminjaman;
}

class listPeminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit listPeminjaman(DataBuku *data, QWidget *parent = nullptr);
    ~listPeminjaman();

private:
    Ui::listPeminjaman *ui;
    DataBuku *dataBuku;
};

#endif // LISTPEMINJAMAN_H
