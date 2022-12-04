#include "Models.hpp"

TrackModel::TrackModel(const std::string& trackName)
    : trackName_(trackName) {}

TrackModel::TrackModel(const std::chrono::seconds& duration)
    : duration_(duration) {}

bool TrackModel::operator==(const TrackModel& other) const {
    return trackName_ == other.trackName_;
}

bool TrackModel::operator!=(const TrackModel& other) const {
    return trackName_ != other.trackName_;
}

void TrackModel::play() noexcept {
    if (!isPlaying_) {
        isPlaying_ = true;
    }
}

void TrackModel::pause() noexcept {
    if (isPlaying_) {
        isPlaying_ = false;
    }
}

void TrackModel::stop() noexcept {
    isPlaying_ = false;
    currentTime_ = std::chrono::seconds::zero();
}

void TrackModel::repeat() noexcept {
    if (isRepeating_) {
        isRepeating_ = false;
    } else {
        isRepeating_ = true;
    }
}

void TrackModel::mute() noexcept {
    volume_ = 0;
}

void TrackModel::setDurationPosition(const std::chrono::seconds& time) noexcept {
    if (time > duration_) {
        currentTime_ = duration_;
    } else {
        currentTime_ = time;
    }
}

void TrackModel::setVolume(float newVolume) noexcept {
    if (newVolume > 100) {
        volume_ = 100;
    } else {
        volume_ = newVolume;
    }
}

bool TrackModel::isPlaying() const noexcept {
    return isPlaying_;
}

bool TrackModel::isRepeating() const noexcept {
    return isRepeating_;
}

std::chrono::seconds TrackModel::getCurrentTime() const noexcept {
    return currentTime_;
}

std::chrono::seconds TrackModel::getDuration() const noexcept {
    return duration_;
}

float TrackModel::getVolume() const noexcept {
    return volume_;
}




void PlaylistModel::addTrack(const TrackModel& newTrack) {
    tracksList_.push_back(newTrack);
}

void PlaylistModel::deleteTrack(TrackModel& deletedTrack) {
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

void PlaylistModel::setCurrentTrack(const TrackModel& newCurrentTrack) {
    auto newCurrentTrackInPlaylist = find(tracksList_.begin(),
                                          tracksList_.end(),
                                          newCurrentTrack);
    if (newCurrentTrackInPlaylist != tracksList_.end()) {
        currentTrack_ = newCurrentTrack;
        currentTrackPosition_ = std::distance(tracksList_.begin(),
                                              newCurrentTrackInPlaylist);
    }
}

void PlaylistModel::setNextTrack() {
    if (currentTrackPosition_ + 1 == tracksList_.size()) {
        currentTrack_ = tracksList_[0];
        currentTrackPosition_ = 0;
    } else {
        currentTrack_ = tracksList_[++currentTrackPosition_];
    }
}

void PlaylistModel::setPreviousTrack() {
    if (currentTrackPosition_ != 0) {
        currentTrack_ = tracksList_[--currentTrackPosition_];
    } 
}

void PlaylistModel::shuffle() {
    std::shuffle(tracksList_.begin(),
                 tracksList_.end(),
                 std::random_device());
}

size_t PlaylistModel::getSize() const noexcept {
    return tracksList_.size();
}

TrackModel PlaylistModel::getCurrentTrack() const noexcept {
    return currentTrack_;
}
