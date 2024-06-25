#ifndef INPUTANGGOTA_H
#define INPUTANGGOTA_H

#include <QMainWindow>

namespace Ui {
class inputAnggota;
}

class inputAnggota : public QMainWindow
{
    Q_OBJECT

public:
    explicit inputAnggota(QWidget *parent = nullptr);
    ~inputAnggota();

private:
    Ui::inputAnggota *ui;
};

#endif // INPUTANGGOTA_H
