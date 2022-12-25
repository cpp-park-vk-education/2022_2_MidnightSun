#pragma once

#include "CurrentTrackController.hpp"

#include <algorithm>
#include <unordered_map>

#include <QLabel>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

class CurrentTrackView : public QObject {
 Q_OBJECT
 public:
    CurrentTrackView(CurrentTrackUIModel* model, QWidget* parent = nullptr);
    ~CurrentTrackView() = default;

    void setCurrentTrackMediator(Mediator* mediator);
    CurrentTrackUIModel* getModel();

 private slots:
    void currentTrackChanged(QString path, int index, bool flag);
    void deleteCurrentTrack(QString path, int index);

    void numberCurrentTrackClicked();

    void elapsedTime(qint64 position);
    void remaningTime(qint64 position);

   //  void muteCurrentTrackClicked();
   //  void volumeCurrentTrackClicked(int);

   //  void firstCurrentTrackClcked();
   //  void secondCurrentTrackClcked();
   //  void thirdCurrentTrackClcked();
   //  void fourthCurrentTrackClcked();
   //  void fifthCurrentTrackClcked();
   //  void sixthCurrentTrackClcked();
   //  void currentTrackChanged(int currentTrackPosition);
   //  void deleteCurrentTrack(int currentTrackPosition);

 private slots:
   //  void play();
    void repeat();
    void mute();
    void setDuration(int position);
    void setVolume(int position);

    void shuffle();
    void previousTrack();
    void nextTrack();

    void playAll();
    void repeatAll();
    void muteAll();
    void setVolumeAll(int);

 signals:
    void removeCurrentTrack();

 public:
   void setStyle(int buttonX, int buttonY,
                 int buttonWidth, int buttonHeight,
                 const char* buttonName, QWidget* object);
 private:
  
    void currentTrackStatus(int index);

    int currentTracksCount_;
   //  std::vector<int> currentTracks_;
   //  std::unordered_map<int, QLabel*> map_;

    CurrentTrackUIModel* model_;
    CurrentTrackController* controller_;
    
    QWidget* parent_;
    QWidget* currentTrackWidget_;
   //  QPushButton* shuffle_;
   //  QPushButton* previousTrack_;
   //  QPushButton* play_;
   //  QPushButton* nextTrack_;
   //  QPushButton* repeat_;
   //  QPushButton* mute_;

    QPushButton* play_;
    QPushButton* repeat_;
    QPushButton* mute_;
    QSlider* volumeSliderAll_;

    QLabel* currentTrackTitle_;

   //  QSlider* durationSlider_;
    std::vector<QPushButton*> currentTracksNumbers_;
    std::vector<QPushButton*> muteButtons_;
    std::vector<QPushButton*> repeatButtons_;
    std::vector<QSlider*> durationSlider_;
    std::vector<QSlider*> volumeSlider_;
    std::vector<QLabel*> trackNames_;

    std::vector<Track*> playTracks_;

    std::vector<int> durations_;
   //  std::vector<int> a;
   //  QSlider* volumeSlider_;
   //  int a = 0;

};
