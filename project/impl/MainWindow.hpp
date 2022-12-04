#pragma once

#include <QMainWindow>
#include <QFile>
#include <QApplication>
#include <QtGui/QMouseEvent>

#include "CurrentPlaylist.hpp"
#include "CurrentTrack.hpp"
#include "LeftWall.hpp"
#include "MenuBar.hpp"
#include "TitleBarButtons.hpp"

class MainWindowWidget : public QWidget {
 Q_OBJECT
 public:
    explicit MainWindowWidget(QWidget* parent = nullptr);
    ~MainWindowWidget() = default;
  protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
  private:
    QPoint oldPos;
};

class MainView {
  public:
    MainView();
    ~MainView() = default;
    void show();
    void close();
  // private:
    MainWindowWidget mainWindowWidget_;
    TitleBarButtonsWidget titleBarButtonsWidget_;

    CurrentTrackView currentTrackView_;
    CurrentPlaylistView currentPlaylistView_;
    LeftBoardView leftBoardView_;
    MenuBarView menuBarView_;
};
