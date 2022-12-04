#include "Track.hpp"

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