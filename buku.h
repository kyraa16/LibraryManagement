#ifndef BUKU_H
#define BUKU_H

#include <QMainWindow>

namespace Ui {
class buku;
}

class buku : public QMainWindow
{
    Q_OBJECT

public:
    explicit buku(QWidget *parent = nullptr);
    ~buku();

private:
    Ui::buku *ui;
};

#endif // BUKU_H
