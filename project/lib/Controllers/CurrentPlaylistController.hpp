#pragma once

#include "CurrentPlaylistUIModel.hpp"

class CurrentPlaylistController {
 public:
    explicit CurrentPlaylistController(CurrentPlaylistUIModel* model);

    void addTrack(std::string path);
    void deleteTrack(size_t index);
    void chooseTrack(size_t index);
 private:
    CurrentPlaylistUIModel* model_;
};
