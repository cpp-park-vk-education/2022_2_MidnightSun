#pragma once

// #include <QWidget>
// #include <QTableWidget>

#include <QMenuBar>
#include <QWidget>
#include <QAction>
#include <QMainWindow>

class MenuBarView : public QMainWindow {
 
 Q_OBJECT

 public:
    explicit MenuBarView(QWidget* parent);
    ~MenuBarView();
 private slots:
    void openFile();
 private:
    QMenuBar* menuBarWidget_;
    QMenu* menuAddFile_;
    QAction* actionAddFile_;
};
