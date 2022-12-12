#include "QCurrentTrackUIModel.hpp"

QCurrentTrackUIModel::QCurrentTrackUIModel(CurrentTrackUIModel* model)
    : model_(model) {}


void QCurrentTrackUIModel::setCurrentTrackMediator(Mediator* mediator) {
    model_->setCurrentTrackMediator(mediator);
}

void QCurrentTrackUIModel::play() {
    model_->play();
    emit playClicked();
}

void QCurrentTrackUIModel::pause() {
    model_->pause();
    emit pauseClicked();
}

// void QCurrentTrackUIModel::stop();

void QCurrentTrackUIModel::repeat() {
    model_->repeat();
    if (model_->currentTrack_->isRepeating()) {
        emit repeatOnClicked();
    } else {
        emit repeatOffClicked();
    }
}

void QCurrentTrackUIModel::mute() {
    model_->mute();
    if (model_->currentTrack_->isMuting()) {
        emit muteOnClicked();
    } else {
        emit muteOffClicked();
    }
}


void QCurrentTrackUIModel::setDuration(int position) {
// ...
}

void QCurrentTrackUIModel::setVolume(int position) {
// ...
}

void QCurrentTrackUIModel::shuffle() {
    model_->shuffle();
}

void QCurrentTrackUIModel::previousTrack() {
    model_->previousTrack();
}

void QCurrentTrackUIModel::nextTrack() {
    model_->nextTrack();
}

void QCurrentTrackUIModel::chooseTrack(Track* track) {
    model_->chooseTrack(track);
}
