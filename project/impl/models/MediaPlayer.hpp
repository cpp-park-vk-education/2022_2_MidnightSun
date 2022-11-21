#include "IMediaPlayer.hpp"

class MediaPlayerModel : public IMediaPlayerModel {
 public:
    void play() override;
    void stop() override;
    void pause() override;
    void mute() override;
    void previousTrack() override;
    void nextTrack() override;
    void shuffle() override;
    void repeat() override;
    void moveVolumeStrip() override;
    void moveDurationStrip() override;

    void addTrack() override;
    void deleteTrack() override;
    void turnOnTheTrack() override;
    void addQueue() override;
    void deleteQueue() override;
    void chooseTrack() override;
 private:
    QMediaPlayer* mPlayer(nullptr);
    Ui::MainWindow* ui(nullptr);
};

class PlaylistModel : public IPlaylistModel {
 public:
    void addTrack() override;
    void deleteTrack() override;
    void turnOnTheTrack() override;
    void addQueue() override;
    void deleteQueue() override;
    void chooseTrack() override;
 private:
    MediaPlayerModel* mediaPlayer(nullptr);
};

class CurrentTrackModel : public ICurrentTrackModel {
 public:
    void play() override;
    void stop() override;
    void pause() override;
    void mute() override;
    void previousTrack() override;
    void nextTrack() override;
    void shuffle() override;
    void repeat() override;
    void moveVolumeStrip() override;
    void moveDurationStrip() override;
 private:
    MediaPlayerModel* mediaPlayer(nullptr);
};
