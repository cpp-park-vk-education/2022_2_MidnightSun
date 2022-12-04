#pragma once

#include "Track.hpp"

#include <algorithm>
#include <random>

class Playlist {
 public:
    void addTrack(const Track& newTrack);
    void deleteTrack(Track& deletedTrack);

    void setCurrentTrack(const Track& newCurrentTrack);
    void setNextTrack();
    void setPreviousTrack();

    void shuffle();

    Track& operator[](size_t i) noexcept {
        return tracksList_[i];
    }

    Track operator[](size_t i) const noexcept {
        return tracksList_[i];
    }

    size_t getSize() const noexcept;
    Track getCurrentTrack() const noexcept;
 private:
    std::string playlistName_ = "";
    Track currentTrack_;
    size_t currentTrackPosition_ = 0;
    std::vector<Track> tracksList_;
};
