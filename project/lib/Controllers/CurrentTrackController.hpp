#pragma once

#include "CurrentTrackUIModel.hpp"

class CurrentTrackController {
 public:
    explicit CurrentTrackController(CurrentTrackUIModel* model);

    void play();
    void pause();
    void stop();
    void repeat();
    void mute();
    void setDuration(int position);
    void setVolume(int position);

    void shuffle();
    void previousTrack();
    void nextTrack();
 private: 
    CurrentTrackUIModel* model_;  
};
