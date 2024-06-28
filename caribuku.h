#ifndef CARIBUKU_H
#define CARIBUKU_H

#include <QMainWindow>
//Ga kepake

namespace Ui {
class cariBuku;
}

class cariBuku : public QMainWindow
{
    Q_OBJECT

public:
    explicit cariBuku(QWidget *parent = nullptr);
    ~cariBuku();

private:
    Ui::cariBuku *ui;
};

#endif // CARIBUKU_H
