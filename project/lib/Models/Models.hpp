#pragma once

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

class TrackModel {
 public:
    TrackModel(const std::string& trackName);
    TrackModel(const std::chrono::seconds& duration);
    TrackModel() = default;
    ~TrackModel() = default;
    
    TrackModel(const TrackModel& rhs) = default;
    TrackModel(TrackModel&& rhs) = default;

    TrackModel& operator=(const TrackModel& rhs) = default;
    TrackModel& operator=(TrackModel&& rhs) = default;

    bool operator==(const TrackModel& other) const;
    bool operator!=(const TrackModel& other) const;

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

class PlaylistModel {
 public:
    void addTrack(const TrackModel& newTrack);
    void deleteTrack(TrackModel& deletedTrack);

    void setCurrentTrack(const TrackModel& newCurrentTrack);
    void setNextTrack();
    void setPreviousTrack();

    void shuffle();

    TrackModel& operator[](size_t i) noexcept {
        return tracksList_[i];
    }

    TrackModel operator[](size_t i) const noexcept {
        return tracksList_[i];
    }

    size_t getSize() const noexcept;
    TrackModel getCurrentTrack() const noexcept;
 private:
    std::string playlistName_ = "";
    TrackModel currentTrack_;
    size_t currentTrackPosition_ = 0;
    std::vector<TrackModel> tracksList_;
};
