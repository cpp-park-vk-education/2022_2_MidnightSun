#pragma once

#include "Parser.hpp"
#include "Track.hpp"

#include <algorithm>
#include <random>

class Playlist {
 public:
    void addTrack(std::string path);
    void deleteTrack(size_t index);
    void chooseTrack(size_t index);

    void previousTrack();
    void nextTrack();
    
    void shuffle();

    Track* operator[](size_t index) noexcept;
    Track* currentTrack() noexcept;
    size_t size() const noexcept;
 private:
    std::vector<Track*> tracksList_;
    std::string playlistName_ = "";
    size_t currentTrackPosition_ = 0;
    Track* currentTrack_ = nullptr;
    Parser parser;
};
