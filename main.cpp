#include "mainwindow.h"
#include <QApplication>
#include "comoperator.h"
#include <memory>
typedef shared_ptr<ComOperator> Comm_ptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
    Comm_ptr comm (new ComOperator());

    w->setCom(comm);
    w->show();
    w->setUpComm();
    return a.exec();
}
