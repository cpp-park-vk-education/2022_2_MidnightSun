#pragma once

#include "FileSystemController.hpp"
#include <QObject>

class QFileSystemController : public QObject {
 Q_OBJECT
 public:
    explicit QFileSystemController(FileSystemUIModel* model);

//  private slots:
 public slots:
    void openFile(std::string path);
 
 private:
    FileSystemController* controller_;
};
