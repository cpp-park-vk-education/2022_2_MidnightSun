#pragma once

#include <QPushButton>
#include <QWidget>

#include <QMenuBar>

class OptionsWindowWidget {
 public:
    explicit OptionsWindowWidget(QWidget* parent);
    ~OptionsWindowWidget();
 private:
    QWidget* optionsWindow_;

    QPushButton* close_;
    QPushButton* collapseToWindow_;
    QPushButton* rollup_;
};

class OptionsWindowView {
 public:
    explicit OptionsWindowView(QWidget* parent);
    ~OptionsWindowView();
 private:
    OptionsWindowWidget optionsWindowWidget_;
};
