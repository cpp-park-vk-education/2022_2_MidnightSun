#pragma once

#include <QPushButton>
#include <QWidget>

class TitleBarButtonsWidget {
 public:
    explicit TitleBarButtonsWidget(QWidget* parent);
    ~TitleBarButtonsWidget();
 private:
    QWidget* titleBarButtons_;

    QPushButton* close_;
    QPushButton* collapseToWindow_;
    QPushButton* rollup_;
};

class TitleBarButtonsView {
 public:
    explicit TitleBarButtonsView(QWidget* parent);
    ~TitleBarButtonsView();
 private:
    TitleBarButtonsWidget titleBarButtonsWidget_;
};
