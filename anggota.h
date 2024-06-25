#ifndef ANGGOTA_H
#define ANGGOTA_H

#include <QMainWindow>
#include "inputanggota.h"

namespace Ui {
class anggota;
}

class anggota : public QMainWindow
{
    Q_OBJECT

public:
    explicit anggota(QWidget *parent = nullptr);
    ~anggota();

private slots:
    void on_anggotaBaru_clicked();

private:
    Ui::anggota *ui;
    inputAnggota ia;
};

#endif // ANGGOTA_H
