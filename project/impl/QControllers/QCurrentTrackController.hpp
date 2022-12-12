#pragma once

// #include "CurrentTrackController.hpp"
#include "QCurrentTrackUIModel.hpp"

#include <QObject>

class QCurrentTrackController : public QObject {
 Q_OBJECT
 public:
    explicit QCurrentTrackController(CurrentTrackUIModel* model);

 private slots:

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
 
 private:
    QCurrentTrackUIModel* model_;
    // CurrentTrackController* controller_;
    
};
