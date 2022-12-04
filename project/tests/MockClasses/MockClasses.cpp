#include "MockClasses.hpp"

MockCurrentTrack::MockCurrentTrack(Mediator* mediator) 
    : CurrentTrackUIModel(mediator) {}

Status MockCurrentTrack::shuffle() {
    CurrentTrackUIModel::shuffle();
    doShuffle();
    return Success;
}

Status MockCurrentTrack::previousTrack() {
    CurrentTrackUIModel::previousTrack();
    doPreviousTrack();
    return Success;
}

Status MockCurrentTrack::play() {
    CurrentTrackUIModel::play();
    doPlay();
    return Success;
}

Status MockCurrentTrack::nextTrack() {
    CurrentTrackUIModel::nextTrack();
    doNextTrack();
    return Success;
}

Status MockCurrentTrack::repeat() {
    CurrentTrackUIModel::repeat();
    doRepeat();
    return Success;
}

Status MockCurrentTrack::mute() {
    CurrentTrackUIModel::mute();
    doMute();
    return Success;
}

Status MockCurrentTrack::moveDuration() {
    CurrentTrackUIModel::moveDuration();
    doMoveDuration();
    return Success;
}

Status MockCurrentTrack::moveVolume() {
    CurrentTrackUIModel::moveVolume();
    doMoveVolume();
    return Success;
}



Status MockCurrentTrack::chooseTrack() {
    CurrentTrackUIModel::chooseTrack();
    doChooseTrack();
    return Success;
}

Status MockCurrentTrack::choosePreviousTrack() {
    CurrentTrackUIModel::choosePreviousTrack();
    doChoosePreviousTrack();
    return Success;
}

Status MockCurrentTrack::chooseNextTrack() {
    CurrentTrackUIModel::chooseNextTrack();
    doChooseNextTrack();
    return Success;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

MockPlaylist::MockPlaylist(Mediator* mediator)
    : PlaylistUIModel(mediator) {}

Status MockPlaylist::addTrack() {
    PlaylistUIModel::addTrack();
    doAddTrack();
    return Success;
}

Status MockPlaylist::deleteTrack() {
    PlaylistUIModel::deleteTrack();
    doDeleteTrack();
    return Success;
}

Status MockPlaylist::chooseTrack() {
    PlaylistUIModel::chooseTrack();
    doChooseTrack();
    return Success;
}

Status MockPlaylist::setShuffle() {
    PlaylistUIModel::setShuffle();
    doSetShuffle();
    return Success;
}

Status MockPlaylist::setRepeat() {
    PlaylistUIModel::setRepeat();
    doSetRepeat();
    return Success;
}

Status MockPlaylist::choosePreviousTrack() {
    PlaylistUIModel::choosePreviousTrack();
    doChoosePreviousTrack();
    return Success;
}

Status MockPlaylist::chooseNextTrack() {
    PlaylistUIModel::chooseNextTrack();
    doChooseNextTrack();
    return Success;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MockModel::notify(Sender* sender, Function function) {
    TrackPlaylistModel::notify(sender, function);
    doNotify(sender, function);
}

void MockModel::setCurrentTrack(MockCurrentTrack* model) {
    TrackPlaylistModel::setCurrentTrack(model);
}

void MockModel::setPlaylist(MockPlaylist* model) {
    TrackPlaylistModel::setPlaylist(model);
}
