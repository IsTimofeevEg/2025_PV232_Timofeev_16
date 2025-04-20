#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    smart_ptr<MainWindow> w(new MainWindow);
    w->show();
    return a.exec();
}
