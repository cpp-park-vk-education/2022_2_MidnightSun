#pragma once

#include "Mediator.hpp"

class CurrentTrackUIModel : public Sender {
 public:
    explicit CurrentTrackUIModel(Mediator* Mediator);

// функции, которые триггерятся контроллером
    virtual Status shuffle();
    virtual Status previousTrack();
    virtual Status play();
    virtual Status nextTrack();
    virtual Status repeat();
    virtual Status mute();
    virtual Status moveDuration();
    virtual Status moveVolume();

// функции, которые триггерятся Playlist UI моделью
    virtual Status chooseTrack();

// функции, которые триггерятся Current Track UI моделью
    virtual Status choosePreviousTrack();
    virtual Status chooseNextTrack();
};