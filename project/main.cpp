#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainView window;
    window.show();;
    return app.exec();
}
