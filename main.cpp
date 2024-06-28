#include "library.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Library w;
    w.show();
    w.setGeometry(300, 150, 900, 600);
    return a.exec();
}
