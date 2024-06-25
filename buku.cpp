#include "buku.h"
#include "ui_buku.h"
#include <QPixmap>
buku::buku(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buku)
{
    ui->setupUi(this);
}

buku::~buku()
{
    delete ui;
}
