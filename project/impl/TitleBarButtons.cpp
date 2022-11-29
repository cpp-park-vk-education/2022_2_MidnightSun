#include "TitleBarButtons.hpp"

#define OPTIONS_WINDOW_WIDTH 800
#define OPTIONS_WINDOW_HEIGHT 25

#define BUTTON_WIDTH 30
#define BUTTON_HEIGHT 25

#define CLOSE_X 765
#define COLLAPSE_TO_WINDOW_X 730
#define ROLLUP_X 690

#define CLOSE_Y 0
#define COLLAPSE_TO_WINDOW_Y 0
#define ROLLUP_Y 0

TitleBarButtonsWidget::TitleBarButtonsWidget(QWidget* parent)
    : titleBarButtons_(new QWidget(parent)) {

    titleBarButtons_->setObjectName("optionsWindow");
    titleBarButtons_->setGeometry(QRect(0, 0, OPTIONS_WINDOW_WIDTH, OPTIONS_WINDOW_HEIGHT));

    close_ = new QPushButton(titleBarButtons_);
    close_->setGeometry(QRect(CLOSE_X, CLOSE_Y,
                              BUTTON_WIDTH, BUTTON_HEIGHT));

    collapseToWindow_ = new QPushButton(titleBarButtons_);
    collapseToWindow_->setGeometry(QRect(COLLAPSE_TO_WINDOW_X, COLLAPSE_TO_WINDOW_Y,
                                         BUTTON_WIDTH, BUTTON_HEIGHT));

    rollup_ = new QPushButton(titleBarButtons_);
    rollup_->setGeometry(QRect(ROLLUP_X, ROLLUP_Y,
                               BUTTON_WIDTH, BUTTON_HEIGHT));

    QPixmap f("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/rollup.png");
    QIcon e(f);
    rollup_->setIcon(e);
    rollup_->setIconSize(QSize(25, 25));

    QPixmap c("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/collapseToWindow.png");
    QIcon d(c);
    collapseToWindow_->setIcon(d);
    collapseToWindow_->setIconSize(QSize(25, 25));

    QPixmap a("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/close.png");
    QIcon b(a);
    close_->setIcon(b);
    close_->setIconSize(QSize(25, 25));
}

TitleBarButtonsWidget::~TitleBarButtonsWidget() {}

TitleBarButtonsView::TitleBarButtonsView(QWidget* parent)
    : titleBarButtonsWidget_(parent) {}

TitleBarButtonsView::~TitleBarButtonsView() {}
