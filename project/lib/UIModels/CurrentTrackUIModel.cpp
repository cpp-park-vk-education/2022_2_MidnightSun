#include "CurrentTrackUIModel.hpp"

void CurrentTrackUIModel::setCurrentTrackMediator(Mediator* mediator) {
    mediator_ = mediator;
}

void CurrentTrackUIModel::play() {
    if (currentTrack_) {
        currentTrack_->play();
    }
}

void CurrentTrackUIModel::pause() {
    if (currentTrack_) {
        currentTrack_->pause();
    }
}

void CurrentTrackUIModel::stop() {
    if (currentTrack_) {
        currentTrack_->stop();
    }
}

void CurrentTrackUIModel::repeat() {
    if (currentTrack_) {
        currentTrack_->repeat();
    }
}

void CurrentTrackUIModel::mute() {
    if (currentTrack_) {
        currentTrack_->mute();
    }
}

void CurrentTrackUIModel::setDuration(int position) {
    if (currentTrack_) {
        currentTrack_->setDuration(position);
    }
}

void CurrentTrackUIModel::setVolume(int position) {
    if (currentTrack_) {
        currentTrack_->setVolume(position);
    }
}

void CurrentTrackUIModel::chooseTrack(Track* track, bool prevNextTrack) {
    if (prevNextTrack && currentTrack_) {
        currentTrack_->stop();
    }
    currentTrack_ = track;
    if (prevNextTrack && currentTrack_) {
        currentTrack_->play();
    }
}


void CurrentTrackUIModel::shuffle() {
    mediator_->notifyTrackPlaylist(this, Shuffle);
}

void CurrentTrackUIModel::previousTrack() {
    mediator_->notifyTrackPlaylist(this, PreviousTrack, true);
}

void CurrentTrackUIModel::nextTrack() {
    mediator_->notifyTrackPlaylist(this, NextTrack, true);
}
