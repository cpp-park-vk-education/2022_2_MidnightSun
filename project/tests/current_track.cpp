// #include "CurrentTrack.hpp"
#include "MainWindow.hpp"

#include <QApplication>
#include <iostream>
#include <gtest/gtest.h>

// TEST(Test, Test) {

//     CurrentTrackView currentTrackView(nullptr);
// }

int main(int argc, char** argv) {
    // CurrentTrackView a(nullptr);
    QApplication a(argc, argv);
    // CurrentTrackView w(nullptr);
    MainView w;
    // a.closeAllWindows();
    w.show();
    // a.exit();
    return a.exec();
    // std::cout << 1;
    // int a =0;
    // a++;
    // MainView a;
    // a.show()
    // return a.exec();
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
}