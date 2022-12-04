#pragma once

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

class Track {
 public:
    Track(const std::string& trackName);
    Track(const std::chrono::seconds& duration);
    Track() = default;
    ~Track() = default;
    
    Track(const Track& rhs) = default;
    Track(Track&& rhs) = default;

    Track& operator=(const Track& rhs) = default;
    Track& operator=(Track&& rhs) = default;

    bool operator==(const Track& other) const;
    bool operator!=(const Track& other) const;

    void play() noexcept;
    void pause() noexcept;
    void stop() noexcept;
    void repeat() noexcept;
    void mute() noexcept;

    void setDurationPosition(const std::chrono::seconds& time) noexcept;
    void setVolume(float newVolume) noexcept;

    bool isPlaying() const noexcept;
    bool isRepeating() const noexcept;

    std::chrono::seconds getCurrentTime() const noexcept;
    std::chrono::seconds getDuration() const noexcept;
    float getVolume() const noexcept;
 private:
    bool isPlaying_ = false;
    bool isRepeating_ = false;

    std::chrono::seconds currentTime_ = std::chrono::seconds::zero();
    std::chrono::seconds duration_ = std::chrono::seconds::zero();
    
    float volume_ = 50.0;

    std::string path_ = "";
    std::string trackName_ = "";
    std::string singer_ = "";
    std::vector<std::string> tags_;
};

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
