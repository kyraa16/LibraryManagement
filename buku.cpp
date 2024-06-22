#include "buku.h"
#include "ui_buku.h"
#include <QPixmap>
buku::buku(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buku)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/kadek/Documents/LibraryManagement/pic2.jpg");
    ui->pic2->setPixmap(pix);
}

buku::~buku()
{
    delete ui;
}
