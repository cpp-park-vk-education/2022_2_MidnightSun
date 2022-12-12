#include "QCurrentPlaylistUIModel.hpp"

QCurrentPlaylistUIModel::QCurrentPlaylistUIModel(CurrentPlaylistUIModel* model)
    : model_(model) {}

void QCurrentPlaylistUIModel::setCurrentPlaylistMediator(Mediator* mediator) {
    model_->setCurrentPlaylistMediator(mediator);
}

void QCurrentPlaylistUIModel::addTrack(std::string path) {
    model_->addTrack(path);
    emit addTrack();
}

void QCurrentPlaylistUIModel::deleteTrack(size_t index) {
    model_->deleteTrack(index);
    emit deleteTrack();
}

void QCurrentPlaylistUIModel::chooseTrack(size_t index) {
    model_->chooseTrack(index);
    emit chooseTrack();
}
