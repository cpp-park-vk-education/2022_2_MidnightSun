#include "QCurrentPlaylistController.hpp"

QCurrentPlaylistController::QCurrentPlaylistController(CurrentPlaylistUIModel* model) 
    : controller_(new CurrentPlaylistController(model)) {}

void QCurrentPlaylistController::addTrack(std::string path) {
    controller_->addTrack(path);
}

void QCurrentPlaylistController::deleteTrack(size_t index) {
    controller_->deleteTrack(index);
}

void QCurrentPlaylistController::chooseTrack(size_t index) {
    controller_->chooseTrack(index);
}
