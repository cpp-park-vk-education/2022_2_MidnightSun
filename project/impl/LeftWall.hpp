#pragma once

#include <QWidget>

//////////////////////////////////////// Left Board Widget ////////////////////////////////////////

class LeftBoardWidget {
  public:
    explicit LeftBoardWidget(QWidget* parent);
    ~LeftBoardWidget();
  private:
    QWidget* leftBoard_; 
};

//////////////////////////////////////// Left Board View ////////////////////////////////////////

class LeftBoardView {
 public:
    LeftBoardView(QWidget* parent);
    ~LeftBoardView();
 private:
    LeftBoardWidget leftBoardWidget_;
};
