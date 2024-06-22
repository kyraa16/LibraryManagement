#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include "buku.h"
#include "peminjaman.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Library;
}
QT_END_NAMESPACE

class Library : public QMainWindow
{
    Q_OBJECT

public:
    Library(QWidget *parent = nullptr);
    ~Library();

private slots:
    void on_bukuButton_clicked();

    void on_peminjamanButton_clicked();

private:
    Ui::Library *ui;
    buku b;
    peminjaman p;
};
#endif // LIBRARY_H
