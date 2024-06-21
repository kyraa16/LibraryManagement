#include "library.h"
#include "./ui_library.h"

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    ui->label->setGeometry(250, 100, 300, 300);
}

Library::~Library()
{
    delete ui;
}
