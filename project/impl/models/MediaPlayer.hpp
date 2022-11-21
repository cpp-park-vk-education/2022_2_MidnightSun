#include "IMediaPlayer.hpp"
#include "MainWindow.hpp"

#include <QDebug>
#include <QFileDialog>
#include <QStringList>
#include <QClipboard>
#include <QTime>
#include <QMediaPlayer>
#include <QUrl>
#include <QMediaPlaylist>


class MediaPlayer : public IMediaPlayerModel {
 public:
      MediaPlayer();
      ~MediaPlayer();

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
      void addQueue() override;
      void deleteQueue() override;
      void chooseTrack() override;
 private:
      QMediaPlayer* mPlayer;
};
