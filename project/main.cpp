#include "MainWindow.hpp"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    MainView w;
    w.show();
    return a.exec();
}

// int main() {
//     return 0;
// }