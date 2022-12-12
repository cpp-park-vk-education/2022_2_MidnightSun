#include "QCurrentTrackController.hpp"

QCurrentTrackController::QCurrentTrackController(CurrentTrackUIModel* model) 
    : model_(new QCurrentTrackUIModel(model)) {}

void QCurrentTrackController::play() {
    model_->play();
}

void QCurrentTrackController::pause() {
    model_->pause();
}

// void QCurrentTrackController::stop() {
//     model_->stop();
// }

void QCurrentTrackController::repeat() {
    model_->repeat();
}

void QCurrentTrackController::mute() {
    model_->mute();
}

void QCurrentTrackController::setDuration(int position) {
    model_->setDuration(position);
}

void QCurrentTrackController::setVolume(int position) {
    model_->setVolume(position);
}


void QCurrentTrackController::shuffle() {
    model_->shuffle();
}

void QCurrentTrackController::previousTrack() {
    model_->previousTrack();
}

void QCurrentTrackController::nextTrack() {
    model_->nextTrack();
}
