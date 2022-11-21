// // #include <QFileDialog>
// // #include <QStringList>
// // #include <QClipboard>
// // #include <QTime>
// // #include <QMediaPlayer>
// // #include <QUrl>

// //  #include <QMediaPlaylist>
// #include <QMainWindow>
// #include "ui_mainwindow.h"



// namespace Ui {
// class MainWindow;
// }

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT
// public:
//     explicit MainWindow(QWidget *parent = 0) 
//                         : QMainWindow(parent),
//                           ui(new Ui::MainWindow) {}
//     ~MainWindow() {
//         if (ui) {
//             delete ui;
//         }
//     }
// private:
//     Ui::MainWindow *ui;
// };

// // #endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
