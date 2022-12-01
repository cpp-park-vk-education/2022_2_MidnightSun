#pragma once

class ICurrentTrackUIModel {
 public:
    virtual void shuffle() = 0;
    virtual void previousTrack() = 0;
    virtual void play() = 0;
    virtual void nextTrack() = 0;
    virtual void repeat() = 0;
    virtual void mute() = 0;
    virtual void moveDurationSlider() = 0;
    virtual void moveVolumeSlider() = 0;
};
