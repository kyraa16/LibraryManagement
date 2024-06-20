#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>

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

private:
    Ui::Library *ui;
};
#endif // LIBRARY_H
