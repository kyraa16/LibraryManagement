#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H

#include <QDialog>

namespace Ui {
class peminjaman;
}

class peminjaman : public QDialog
{
    Q_OBJECT

public:
    explicit peminjaman(QWidget *parent = nullptr);
    ~peminjaman();

private:
    Ui::peminjaman *ui;
};

#endif // PEMINJAMAN_H
