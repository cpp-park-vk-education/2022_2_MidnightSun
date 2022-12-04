#include "Playlist.hpp"

void Playlist::addTrack(const Track& newTrack) {
    tracksList_.push_back(newTrack);
}

void Playlist::deleteTrack(Track& deletedTrack) {
    if (&deletedTrack == &currentTrack_ && tracksList_.size() != 1) {
        if (currentTrackPosition_ + 1 == tracksList_.size()) { // если текущий трек последний в плейлисте
            setCurrentTrack(tracksList_[currentTrackPosition_ - 1]);
        } else {
            setCurrentTrack(tracksList_[currentTrackPosition_ + 1]);
        }
    }
    auto deletedTrackInPlaylist = find(tracksList_.begin(),
                                       tracksList_.end(),
                                       deletedTrack);
    if (deletedTrackInPlaylist != tracksList_.end()) {
        tracksList_.erase(deletedTrackInPlaylist);
    }
}

void Playlist::setCurrentTrack(const Track& newCurrentTrack) {
    auto newCurrentTrackInPlaylist = find(tracksList_.begin(),
                                          tracksList_.end(),
                                          newCurrentTrack);
    if (newCurrentTrackInPlaylist != tracksList_.end()) {
        currentTrack_ = newCurrentTrack;
        currentTrackPosition_ = std::distance(tracksList_.begin(),
                                              newCurrentTrackInPlaylist);
    }
}

void Playlist::setNextTrack() {
    if (currentTrackPosition_ + 1 == tracksList_.size()) {
        currentTrack_ = tracksList_[0];
        currentTrackPosition_ = 0;
    } else {
        currentTrack_ = tracksList_[++currentTrackPosition_];
    }
}

void Playlist::setPreviousTrack() {
    if (currentTrackPosition_ != 0) {
        currentTrack_ = tracksList_[--currentTrackPosition_];
    } 
}

void Playlist::shuffle() {
    std::shuffle(tracksList_.begin(),
                 tracksList_.end(),
                 std::random_device());
}

size_t Playlist::getSize() const noexcept {
    return tracksList_.size();
}

Track Playlist::getCurrentTrack() const noexcept {
    return currentTrack_;
}
