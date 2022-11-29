#pragma once

#include <QPushButton>
#include <QWidget>

class TitleBarButtonsWidget {
 public:
    explicit TitleBarButtonsWidget(QWidget* parent);
    ~TitleBarButtonsWidget();

    TitleBarButtonsWidget(const TitleBarButtonsWidget& rhs) = delete;
    TitleBarButtonsWidget(TitleBarButtonsWidget&& rhs) = delete;

    TitleBarButtonsWidget& operator=(const TitleBarButtonsWidget& rhs) = delete;
    TitleBarButtonsWidget& operator=(TitleBarButtonsWidget&& rhs) = delete;

 private:
    QWidget* titleBarButtons_;

    QPushButton* close_;
    QPushButton* zoom_;
    QPushButton* minimize_;
};

class TitleBarButtonsView {
 public:
    explicit TitleBarButtonsView(QWidget* parent);
    ~TitleBarButtonsView() = default;
 private:
    TitleBarButtonsWidget titleBarButtonsWidget_;
};
