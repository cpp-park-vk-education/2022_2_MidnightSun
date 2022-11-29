#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainView b;
    b.show();
    return a.exec();
}
