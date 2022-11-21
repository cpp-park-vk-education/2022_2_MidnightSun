// #include "IMediaPlayer.hpp"

// #include <QMainWindow>
// #include <QDebug>
// #include <QFileDialog>
// #include <QStringList>
// #include <QClipboard>
// #include <QTime>
// #include <QMediaPlayer>
// #include <QUrl>
// #include <QMediaPlaylist>

// QT_BEGIN_NAMESPACE
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE

// class MainWindow {
//  public:
//      explicit MainWindow(QWidget *parent = nullptr);
//      ~MainWindow();

     // void play();
     // void stop();
     // void pause();
     // void mute();
     // void previousTrack();
     // void nextTrack();
     // void shuffle();
     // void repeat();
     // void moveVolumeStrip();
     // void moveDurationStrip();

     // void addTrack();
     // void deleteTrack();
     // void addQueue();
     // void deleteQueue();
//      void chooseTrack();
//  private:
//      Q_OBJECT
     
//      Ui::MainWindow* ui;
// };

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

     void play();
     void stop();
     void pause();
     void mute();
     void previousTrack();
     void nextTrack();
     void shuffle();
     void repeat();
     void moveVolumeStrip();
     void moveDurationStrip();

     void addTrack();
     void deleteTrack();
     void addQueue();
     void deleteQueue();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H