#include "CurrentPlaylist.hpp"

PlaylistUIModel::PlaylistUIModel(Mediator* mediator)
    : Sender(mediator) {}

// функции, которые триггерятся контроллером

Status PlaylistUIModel::addTrack() {
    return Success;
}

Status PlaylistUIModel::deleteTrack() {
    return Success;
}

Status PlaylistUIModel::chooseTrack() {
    mediator_->notify(this, ChooseTrack);
    return Success;
}

// функции, которые триггерятся Current Track моделью

Status PlaylistUIModel::setShuffle() {
    return Success;
}

Status PlaylistUIModel::setRepeat() {
    return Success;
}

Status PlaylistUIModel::choosePreviousTrack() {
    return Success;
}

Status PlaylistUIModel::chooseNextTrack() {
    return Success;
}