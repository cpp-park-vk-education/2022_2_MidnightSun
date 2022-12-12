#pragma once

#include "Mediator.hpp"
#include "Track.hpp"

class CurrentTrackUIModel : public Sender {
 public:
    void setCurrentTrackMediator(Mediator* mediator);

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

    void chooseTrack(Track* track);

public:
   Track* currentTrack_ = nullptr;
};
