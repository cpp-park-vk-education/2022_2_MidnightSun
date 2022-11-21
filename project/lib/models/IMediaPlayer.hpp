class IMediaPlayerModel {
 public:
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void pause() = 0;
    virtual void mute() = 0;
    virtual void previousTrack() = 0;
    virtual void nextTrack() = 0;
    virtual void shuffle() = 0;
    virtual void repeat() = 0;
    virtual void moveVolumeStrip() = 0;
    virtual void moveDurationStrip() = 0;

    virtual void addTrack() = 0;
    virtual void deleteTrack() = 0;
    virtual void turnOnTheTrack() = 0;
    virtual void addQueue() = 0;
    virtual void deleteQueue() = 0;
    virtual void chooseTrack() = 0;
};

class IPlaylistModel {
 public:
    virtual void addTrack() = 0;
    virtual void deleteTrack() = 0;
    virtual void turnOnTheTrack() = 0;
    virtual void addQueue() = 0;
    virtual void deleteQueue() = 0;
    virtual void chooseTrack() = 0;
};

class ICurrentTrackModel {
 public:
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void pause() = 0;
    virtual void mute() = 0;
    virtual void previousTrack() = 0;
    virtual void nextTrack() = 0;
    virtual void shuffle() = 0;
    virtual void repeat() = 0;
    virtual void moveVolumeStrip() = 0;
    virtual void moveDurationStrip() = 0;
};
