#pragma once

#include "Mediator.hpp"
#include "Playlist.hpp"

class CurrentPlaylistUIModel : public Sender {
 public:
    void setCurrentPlaylistMediator(Mediator* mediator);

    void addTrack(std::string path);
    void deleteTrack(size_t index);
    void chooseTrack(size_t index);

    void shuffle();
    void previousTrack();
    void nextTrack();

 private:
    Playlist playlist_;
};
