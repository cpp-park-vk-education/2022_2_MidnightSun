#pragma once

#include "CurrentTrackUIModel.hpp"
#include <QObject>

class QCurrentTrackUIModel : public QObject {
 Q_OBJECT
 public:
    explicit QCurrentTrackUIModel(CurrentTrackUIModel* model);
 
    void setCurrentTrackMediator(Mediator* mediator);

    void play();
    void pause();
    // void stop();
    void repeat();
    void mute();
    void setDuration(int position);
    void setVolume(int position);

    void shuffle();
    void previousTrack();
    void nextTrack();

    void chooseTrack(Track* track);

 signals:
    void playClicked();
    void pauseClicked();

    void shuffleOffClicked();
    void shuffleOnClicked();

    void repeatOffClicked();
    void repeatOnClicked();

    void volumeSliderMoved(int);
    void muteOffClicked();
    void muteOnClicked();

//  private:
 public:
    CurrentTrackUIModel* model_;
};
