#ifndef INPUTPEMINJAMAN_H
#define INPUTPEMINJAMAN_H

#include <QMainWindow>
#include "databuku.h"

namespace Ui {
class inputPeminjaman;
}

class inputPeminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit inputPeminjaman(DataBuku *data, QWidget *parent = nullptr);
    ~inputPeminjaman();

private:
    Ui::inputPeminjaman *ui;
    DataBuku *dataBuku;
};

#endif // INPUTPEMINJAMAN_H
