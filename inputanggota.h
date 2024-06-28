#ifndef INPUTANGGOTA_H
#define INPUTANGGOTA_H

#include <QMainWindow>
#include "databuku.h"

namespace Ui {
class inputAnggota;
}

class inputAnggota : public QMainWindow
{
    Q_OBJECT

public:
    explicit inputAnggota(DataBuku *data, QWidget *parent = nullptr);
    ~inputAnggota();

private:
    Ui::inputAnggota *ui;
    DataBuku *dataBuku;
};

#endif // INPUTANGGOTA_H
