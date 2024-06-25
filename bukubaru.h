#ifndef BUKUBARU_H
#define BUKUBARU_H

#include <QMainWindow>
// #include "buku.h"

namespace Ui {
class bukuBaru;
}

class bukuBaru : public QMainWindow
{
    Q_OBJECT

public:
    explicit bukuBaru(QWidget *parent = nullptr);
    ~bukuBaru();

private slots:

private:
    Ui::bukuBaru *ui;
    // buku back;
};

#endif // BUKUBARU_H
