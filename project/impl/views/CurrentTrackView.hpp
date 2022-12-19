#pragma once

#include "CurrentTrackController.hpp"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

class CurrentTrackView : public QObject {
 Q_OBJECT
 public:
    CurrentTrackView(CurrentTrackUIModel* model, QWidget* parent = nullptr, int offset = 0);
    explicit CurrentTrackView(int offset);
    ~CurrentTrackView() = default;

   //  CurrentTrackView(int offset);
    CurrentTrackView(const CurrentTrackView& rhs);

   //  void initializeView();
    void setCurrentTrackMediator(Mediator* mediator);
    CurrentTrackUIModel* getModel();

 private slots:
    void currentTrackChanged();
   //  void currentTrackChanged(int currentTrackPosition);
   //  void deleteCurrentTrack(int currentTrackPosition);

 private slots:
    void play();
    void repeat();
    void mute();
    void setDuration(int position);
    void setVolume(int position);

    void shuffle();
    void previousTrack();
    void nextTrack();

public:
   void setStyle(int buttonX, int buttonY,
                 int buttonWidth, int buttonHeight,
                 const char* buttonName, QWidget* object);
 private:
    CurrentTrackUIModel* model_;
    CurrentTrackController* controller_;
    
    QWidget* currentTrackWidget_;

    QPushButton* shuffle_;
    QPushButton* previousTrack_;
    QPushButton* play_;
    QPushButton* nextTrack_;
    QPushButton* repeat_;
    QPushButton* mute_;

    QSlider* durationSlider_;
    QSlider* volumeSlider_;

    int offset_;
};
