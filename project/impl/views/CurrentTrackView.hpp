#pragma once

#include "QCurrentTrackController.hpp"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

class CurrentTrackView : public QObject {
 Q_OBJECT
 public:
    explicit CurrentTrackView(QWidget* parent = nullptr);
    ~CurrentTrackView() = default;

    void setCurrentTrackMediator(Mediator* mediator);
    CurrentTrackUIModel* getModel();
// private slots:
//    void playButtonChanged();
//    void pauseButtonChanged();

//    void shuffleOffButtonChanged();
//    void shuffleOnButtonChanged();

//    void repeatOffButtonChanged();
//    void repeatOnButtonChanged();

//    void muteOffButtonChanged();
//    void muteOnButtonChanged();

   // void ElapsedTime(qint64 x) {
   //    durationSlider_->setValue(x / 1000);
   // }

   // void volumeTime(int x) {
   //    volumeSlider_->setValue(x);
   // }

public:
   void setStyle(int buttonX, int buttonY,
                 int buttonWidth, int buttonHeight,
                 const char* buttonName, QWidget* object);
 private:
    CurrentTrackUIModel* model_;
    QCurrentTrackController* controller_;
    

    QWidget* currentTrackWidget_;

    QPushButton* shuffle_;
    QPushButton* previousTrack_;
    QPushButton* play_;
    QPushButton* nextTrack_;
    QPushButton* repeat_;
    QPushButton* mute_;

    QSlider* durationSlider_;
    QSlider* volumeSlider_;
};
