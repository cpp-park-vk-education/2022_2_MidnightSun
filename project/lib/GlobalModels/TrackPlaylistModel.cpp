#include "TrackPlaylistModel.hpp"

Sender::Sender(Mediator* mediator)
    : mediator_(mediator) {}

void TrackPlaylistModel::setCurrentTrack(CurrentTrackUIModel* model) {
    currentTrack_ = model;
}

void TrackPlaylistModel::setPlaylist(PlaylistUIModel* model) {
    playlist_ = model;
}

void TrackPlaylistModel::notify(Sender* sender, Function function) {

    if (sender == currentTrack_ && function == Shuffle) {
        playlist_->setShuffle();
    } else if (sender == currentTrack_ && function == PreviousTrack) {
        playlist_->choosePreviousTrack();
        currentTrack_->choosePreviousTrack();
    } else if (sender == currentTrack_ && function == NextTrack) {
        playlist_->chooseNextTrack();
        currentTrack_->chooseNextTrack();
    } else if (sender == currentTrack_ && function == Repeat) {
        playlist_->setRepeat();
    } else if (sender == currentTrack_ && function == DurationEnd) {
        playlist_->chooseNextTrack(); 
        currentTrack_->chooseNextTrack();
    }

    else if (sender == playlist_ && function == ChooseTrack) {
        currentTrack_->chooseTrack();
    }
}
