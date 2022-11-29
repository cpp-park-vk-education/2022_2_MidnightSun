#include "TitleBarButtons.hpp"

const int OPTIONS_WINDOW_WIDTH = 800;
const int OPTIONS_WINDOW_HEIGHT = 25;

const int BUTTON_WIDTH = 30;
const int BUTTON_HEIGHT = 25;

const int CLOSE_X = 765;
const int COLLAPSE_TO_WINDOW_X = 730;
const int ROLLUP_X = 690;

const int CLOSE_Y = 0;
const int COLLAPSE_TO_WINDOW_Y = 0;
const int ROLLUP_Y = 0;

TitleBarButtonsWidget::TitleBarButtonsWidget(QWidget* parent)
    : titleBarButtons_(new QWidget(parent)) {

    titleBarButtons_->setObjectName("optionsWindow");
    titleBarButtons_->setGeometry(QRect(0, 0, OPTIONS_WINDOW_WIDTH, OPTIONS_WINDOW_HEIGHT));

    close_ = new QPushButton(titleBarButtons_);
    close_->setGeometry(QRect(CLOSE_X, CLOSE_Y,
                              BUTTON_WIDTH, BUTTON_HEIGHT));

    zoom_ = new QPushButton(titleBarButtons_);
    zoom_->setGeometry(QRect(COLLAPSE_TO_WINDOW_X, COLLAPSE_TO_WINDOW_Y,
                             BUTTON_WIDTH, BUTTON_HEIGHT));

    minimize_ = new QPushButton(titleBarButtons_);
    minimize_->setGeometry(QRect(ROLLUP_X, ROLLUP_Y,
                                 BUTTON_WIDTH, BUTTON_HEIGHT));

    QPixmap f("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/rollup.png");
    QIcon e(f);
    minimize_->setIcon(e);
    minimize_->setIconSize(QSize(25, 25));

    QPixmap c("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/collapseToWindow.png");
    QIcon d(c);
    zoom_->setIcon(d);
    zoom_->setIconSize(QSize(25, 25));

    QPixmap a("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/close.png");
    QIcon b(a);
    close_->setIcon(b);
    close_->setIconSize(QSize(25, 25));
}

TitleBarButtonsWidget::~TitleBarButtonsWidget() {
    delete titleBarButtons_;
    delete close_;
    delete zoom_;
    delete minimize_;
}

TitleBarButtonsView::TitleBarButtonsView(QWidget* parent)
    : titleBarButtonsWidget_(parent) {}
