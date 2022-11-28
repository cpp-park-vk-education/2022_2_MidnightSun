#pragma once

#include <QMainWindow>
#include <QFile>
#include <QApplication>
#include <QtGui/QMouseEvent>

#include "currentTrack.hpp"
#include "optionsWindow.hpp"
#include "leftBoard.hpp"

class MainWindowWidget : public QWidget {
 Q_OBJECT
 public:
    MainWindowWidget(QWidget* parent = nullptr);
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

    CurrentTrackView currentTrackView_;

    OptionsWindowWidget optionWindow_;

    LeftBoardView leftBoardView_;
};
