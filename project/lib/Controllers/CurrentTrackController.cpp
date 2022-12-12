#include "CurrentTrackController.hpp"

CurrentTrackController::CurrentTrackController(CurrentTrackUIModel* model)
    : model_(model) {}

void CurrentTrackController::play() {
    model_->play();
}

void CurrentTrackController::pause() {
    model_->pause();
}

void CurrentTrackController::stop() {
    model_->stop();
}

void CurrentTrackController::repeat() {
    model_->repeat();
}

void CurrentTrackController::mute() {
    model_->mute();
}

void CurrentTrackController::setDuration(int position) {
    model_->setDuration(position);
}

void CurrentTrackController::setVolume(int position) {
    model_->setVolume(position);
}


void CurrentTrackController::shuffle() {
    model_->shuffle();
}

void CurrentTrackController::previousTrack() {
    model_->previousTrack();
}

void CurrentTrackController::nextTrack() {
    model_->nextTrack();
}
