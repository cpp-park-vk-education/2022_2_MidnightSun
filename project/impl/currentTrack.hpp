#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QSlider>

//////////////////////////////////////// Current Track Buttons ////////////////////////////////////////

class IButton : public QMainWindow {
 Q_OBJECT
//  signals:
//     void clicked();
 public:
    friend class CurrentTrackView;

    explicit IButton(QWidget* parent = nullptr);
    ~IButton();
 protected:
    QPushButton* button_;
};

struct ShuffleButton : public IButton {
    explicit ShuffleButton(QWidget* parent);
};

struct PreviousTrackButton : public IButton {
    explicit PreviousTrackButton(QWidget* parent);
};

struct PlayButton : public IButton {
    explicit PlayButton(QWidget* parent);;
};

struct NextTrackButton : public IButton {
    explicit NextTrackButton(QWidget* parent);
};

struct RepeatButton : public IButton {
    explicit RepeatButton(QWidget* parent);
};

struct MuteButton : public IButton {
    explicit MuteButton(QWidget* parent);
};

class VolumeSlider {
  public:
    explicit VolumeSlider(QWidget* parent);
    ~VolumeSlider();
 private:
    QSlider* volumeSlider_;
};

//////////////////////////////////////// Current Track Widget ////////////////////////////////////////

class CurrentTrackWidget {
 public:
    friend class CurrentTrackView;

    explicit CurrentTrackWidget(QWidget* parent);
    ~CurrentTrackWidget();
 private:
    QWidget* currentTrackWindow_;
   
    ShuffleButton shufle_;
    PreviousTrackButton previousTrack_;
    PlayButton play_;
    NextTrackButton nextTrack_;
    RepeatButton repeat_;
    MuteButton mute_;
    VolumeSlider volumeSlider_;
};

//////////////////////////////////////// Current Track Controller ////////////////////////////////////////

class CurrentTrackController : public QMainWindow {
 Q_OBJECT
 public:
    friend class CurrentTrackView;
 private slots:
    // void shuffle();
    // void previousTrack();
    void play() {}
    // void nextTrack();
    // void repeat();
    // void mute();
};

//////////////////////////////////////// Current Track UIModel ////////////////////////////////////////

class CurrentTrackUIModel {
 public:
    void shuffle();
    void previousTrack();
    void play();
    void nextTrack();
    void repeat();
    void mute();
};

//////////////////////////////////////// Current Track View ////////////////////////////////////////

#include <iostream>
#include <QMessageBox>

class CurrentTrackView : public QMainWindow {
 Q_OBJECT
//  private slots:
//     void play();
 public:
    explicit CurrentTrackView(QWidget* parent);
    ~CurrentTrackView();
 private:
    CurrentTrackWidget baseFunctionalButtons_;
    CurrentTrackController controller_;
    CurrentTrackUIModel model_;
};
