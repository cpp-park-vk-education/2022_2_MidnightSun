#include "Models.hpp"

Track::Track(const std::string& trackName)
    : trackName_(trackName) {}

Track::Track(const std::chrono::seconds& duration)
    : duration_(duration) {}

bool Track::operator==(const Track& other) const {
    return trackName_ == other.trackName_;
}

bool Track::operator!=(const Track& other) const {
    return trackName_ != other.trackName_;
}

void Track::play() noexcept {
    if (!isPlaying_) {
        isPlaying_ = true;
    }
}

void Track::pause() noexcept {
    if (isPlaying_) {
        isPlaying_ = false;
    }
}

void Track::stop() noexcept {
    isPlaying_ = false;
    currentTime_ = std::chrono::seconds::zero();
}

void Track::repeat() noexcept {
    if (isRepeating_) {
        isRepeating_ = false;
    } else {
        isRepeating_ = true;
    }
}

void Track::mute() noexcept {
    volume_ = 0;
}

void Track::setDurationPosition(const std::chrono::seconds& time) noexcept {
    if (time > duration_) {
        currentTime_ = duration_;
    } else {
        currentTime_ = time;
    }
}

void Track::setVolume(float newVolume) noexcept {
    if (newVolume > 100) {
        volume_ = 100;
    } else {
        volume_ = newVolume;
    }
}

bool Track::isPlaying() const noexcept {
    return isPlaying_;
}

bool Track::isRepeating() const noexcept {
    return isRepeating_;
}

std::chrono::seconds Track::getCurrentTime() const noexcept {
    return currentTime_;
}

std::chrono::seconds Track::getDuration() const noexcept {
    return duration_;
}

float Track::getVolume() const noexcept {
    return volume_;
}




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
