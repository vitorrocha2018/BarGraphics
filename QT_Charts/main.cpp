#include "widget.h"
#include <QApplication>

QWidget *setup()
{
    auto w = new Widget();

    w->setWindowTitle("Teste QBars");

    w->resize(900, 600);

    return w;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setup()->show();

    return a.exec();
}
