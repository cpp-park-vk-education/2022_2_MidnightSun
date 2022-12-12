#include "QCurrentPlaylistController.hpp"

QCurrentPlaylistController::QCurrentPlaylistController(CurrentPlaylistUIModel* model) 
    : model_(new QCurrentPlaylistUIModel(model)) {}

void QCurrentPlaylistController::addTrack(std::string path) {
    // controller_->addTrack(path);
    model_->addTrack(path);
}

void QCurrentPlaylistController::deleteTrack(size_t index) {
    // controller_->deleteTrack(index);
    model_->deleteTrack(index);
}

void QCurrentPlaylistController::chooseTrack(size_t index) {
    // controller_->chooseTrack(index);
    model_->chooseTrack(index);
}
