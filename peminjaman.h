#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H

#include <QMainWindow>

namespace Ui {
class peminjaman;
}

class peminjaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit peminjaman(QWidget *parent = nullptr);
    ~peminjaman();

private:
    Ui::peminjaman *ui;
};

#endif // PEMINJAMAN_H
