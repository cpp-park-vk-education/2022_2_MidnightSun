#include "QCurrentTrackController.hpp"

QCurrentTrackController::QCurrentTrackController(CurrentTrackUIModel* model) 
    : controller_(new CurrentTrackController(model)) {}


void QCurrentTrackController::play() {
    controller_->play();
}

void QCurrentTrackController::pause() {
    controller_->pause();
}

void QCurrentTrackController::stop() {
    controller_->stop();
}

void QCurrentTrackController::repeat() {
    controller_->repeat();
}

void QCurrentTrackController::mute() {
    controller_->mute();
}

void QCurrentTrackController::setDuration(int position) {
    controller_->setDuration(position);
}

void QCurrentTrackController::setVolume(int position) {
    controller_->setVolume(position);
}


void QCurrentTrackController::shuffle() {
    controller_->shuffle();
}

void QCurrentTrackController::previousTrack() {
    controller_->previousTrack();
}

void QCurrentTrackController::nextTrack() {
    controller_->nextTrack();
}
