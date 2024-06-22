#ifndef BUKUBARU_H
#define BUKUBARU_H

#include <QMainWindow>

namespace Ui {
class bukuBaru;
}

class bukuBaru : public QMainWindow
{
    Q_OBJECT

public:
    explicit bukuBaru(QWidget *parent = nullptr);
    ~bukuBaru();

private:
    Ui::bukuBaru *ui;
};

#endif // BUKUBARU_H
