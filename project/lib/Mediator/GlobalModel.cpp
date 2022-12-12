#include "GlobalModel.hpp"

Sender::Sender(Mediator* mediator)
    : mediator_(mediator) {}

void TrackPlaylistModel::setCurrentTrack(CurrentTrackUIModel* model) {
    currentTrack_ = model;
}

void TrackPlaylistModel::setPlaylist(CurrentPlaylistUIModel* model) {
    playlist_ = model;
}

void TrackPlaylistModel::setFileSystem(FileSystemUIModel* model) {
    fileSystem_ = model;
}

void TrackPlaylistModel::notifyTrackPlaylist(Sender* sender, Function function, Track* track) {

    if (sender == currentTrack_ && function == Shuffle) {
        playlist_->shuffle();
    } else if (sender == currentTrack_ && function == PreviousTrack) {
        playlist_->previousTrack();
        currentTrack_->chooseTrack(track);
    } else if (sender == currentTrack_ && function == NextTrack) {
        playlist_->nextTrack();
        currentTrack_->chooseTrack(track);
    } else if (sender == currentTrack_ && function == DurationEnd) {
        playlist_->nextTrack();
        // currentTrack_->chooseTrack(track);
    }

    else if (sender == playlist_ && function == NewCurrentTrack) {
        currentTrack_->chooseTrack(track);
    } else if (sender == playlist_ && function == DeletedTrackIsCurrent) {
        currentTrack_->chooseTrack(track);
    }
}

void TrackPlaylistModel::notifyFileSystemPlaylist(Sender* sender, Function function, std::string path) {
    if (sender == fileSystem_ && function == OpenFile) {
        playlist_->addTrack(path);
    }
}
