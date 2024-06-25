#ifndef INPUTPEMINJAMAN_H
#define INPUTPEMINJAMAN_H

#include <QMainWindow>

namespace Ui {
class inputPeminjaman;
}

class inputPeminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit inputPeminjaman(QWidget *parent = nullptr);
    ~inputPeminjaman();

private:
    Ui::inputPeminjaman *ui;
};

#endif // INPUTPEMINJAMAN_H
