#pragma once

#include "FileSystemController.hpp"

#include <QAction>
#include <QFileDialog>
#include <QMainWindow>
#include <QMenuBar>
#include <QWidget>


class FileSystemView : public QMainWindow {
 Q_OBJECT
 public:
    explicit FileSystemView(QWidget* parent);
    ~FileSystemView();

    void setFileSystemMediator(Mediator* mediator);
    FileSystemUIModel* getModel();

 signals:
    void openFile(QString);

 private slots:
    void openFile();

 private:
    QMenuBar* menuBarWidget_;
    QMenu* menuAddFile_;
    QAction* actionAddFile_;

    FileSystemUIModel* model_;
    FileSystemController* controller_;
};
