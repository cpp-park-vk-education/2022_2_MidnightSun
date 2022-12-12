#include "CurrentPlaylistController.hpp"

CurrentPlaylistController::CurrentPlaylistController(CurrentPlaylistUIModel* model)
    : model_(model) {}

void CurrentPlaylistController::addTrack(std::string path) {
    model_->addTrack(path);
}

void CurrentPlaylistController::deleteTrack(size_t index) {
    model_->deleteTrack(index);
}

void CurrentPlaylistController::chooseTrack(size_t index) {
    model_->chooseTrack(index);
}
