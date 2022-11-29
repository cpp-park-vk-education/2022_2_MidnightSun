#pragma once

#include <QMainWindow>
#include <QFile>
#include <QApplication>
#include <QtGui/QMouseEvent>

#include "CurrentTrack.hpp"
#include "TitleBarButtons.hpp"
#include "LeftWall.hpp"

class MainWindowWidget : public QWidget {
 Q_OBJECT
 public:
    explicit MainWindowWidget(QWidget* parent = nullptr);
    ~MainWindowWidget();
  protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
  private:
    QPoint oldPos;
};

class MainView {
  public:
    MainView();
    ~MainView();
    void show();
  private:
    MainWindowWidget mainWindowWidget_;
    TitleBarButtonsWidget titleBarButtonsWidget_;

    CurrentTrackView currentTrackView_;
    LeftBoardView leftBoardView_;
};
