#pragma once

#include <QWidget>

class LeftBoardWidget {
  public:
    explicit LeftBoardWidget(QWidget* parent);
    ~LeftBoardWidget();
  private:
    QWidget* leftBoard_; 
};

class LeftBoardView {
 public:
    LeftBoardView(QWidget* parent);
    ~LeftBoardView();
 private:
    LeftBoardWidget leftBoardWidget_;
};
