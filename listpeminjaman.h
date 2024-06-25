#ifndef LISTPEMINJAMAN_H
#define LISTPEMINJAMAN_H

#include <QMainWindow>

namespace Ui {
class listPeminjaman;
}

class listPeminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit listPeminjaman(QWidget *parent = nullptr);
    ~listPeminjaman();

private:
    Ui::listPeminjaman *ui;
};

#endif // LISTPEMINJAMAN_H
