#include "QFileSystemController.hpp"

QFileSystemController::QFileSystemController(FileSystemUIModel* model)
    : controller_(new FileSystemController(model)) {}

void QFileSystemController::openFile(std::string path) {
    controller_->openFile(path);
}
