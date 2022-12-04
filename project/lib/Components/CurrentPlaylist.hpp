#pragma once

#include "Mediator.hpp"

class PlaylistUIModel : public Sender {
 public:
    explicit PlaylistUIModel(Mediator* mediator);

// функции, которые триггерятся контроллером
    virtual Status addTrack();
    virtual Status deleteTrack();
    virtual Status chooseTrack();

// функции, которые триггерятся Current Track UI моделью
    virtual Status setShuffle();
    virtual Status setRepeat();
    virtual Status choosePreviousTrack();
    virtual Status chooseNextTrack();
};