#ifndef BUKU_H
#define BUKU_H

#include <QDialog>

namespace Ui {
class Buku;
}

class Buku : public QDialog
{
    Q_OBJECT

public:
    explicit Buku(QWidget *parent = nullptr);
    ~Buku();

private:
    Ui::Buku *ui;
};

#endif // BUKU_H
