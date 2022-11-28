#include "leftBoard.hpp"

#define LEFT_BOARD_WIDTH 200
#define LEFT_BOARD_HEIGHT 600

LeftBoardWidget::LeftBoardWidget(QWidget* parent) 
                                 : leftBoard_(new QWidget(parent)) {
    leftBoard_->setObjectName("leftBoard");
    leftBoard_->setGeometry(QRect(0, 0,
                                  LEFT_BOARD_WIDTH,
                                  LEFT_BOARD_HEIGHT));
}

LeftBoardWidget::~LeftBoardWidget() {}

LeftBoardView::LeftBoardView(QWidget* parent) 
                  : leftBoardWidget_(parent) {}

LeftBoardView::~LeftBoardView() {}
