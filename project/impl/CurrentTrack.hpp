#pragma once

#include "currentTrackController.hpp"
#include "currentTrackUIModel.hpp"
#include "InterfaceButtons.hpp"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

//////////////////////////////////////// Current Track Buttons ////////////////////////////////////////

// class IButton : public QMainWindow {

//  Q_OBJECT
//  public:   
//     friend class CurrentTrackView;
//     explicit IButton(QWidget* parent = nullptr);
//     ~IButton();

//     void setStyle(int button_x, int button_y,
//                   int button_width, int button_height,
//                   const char* path);
//  private:
//     QPushButton* button_;
// };


struct ShuffleButton : public IButton {
 public:
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

class CurrentTrackWidget {
 public:
    explicit CurrentTrackWidget(QWidget* parent = nullptr);
    ~CurrentTrackWidget();
 private:
    QWidget* currentTrackWidget_;
};

//////////////////////////////////////// Current Track Window ////////////////////////////////////////

class CurrentTrackWindow {
 public:
    friend class CurrentTrackView;

    explicit CurrentTrackWindow(QWidget* parent);
    ~CurrentTrackWindow();
 private:
    CurrentTrackWidget currentTrackWidget_;
    ShuffleButton shuffle_;
    PreviousTrackButton previousTrack_;
    PlayButton play_;
    NextTrackButton nextTrack_;
    RepeatButton repeat_;
    MuteButton mute_;
    VolumeSlider volumeSlider_;
};

//////////////////////////////////////// Current Track UIModel ////////////////////////////////////////

class CurrentTrackUIModel : public QMainWindow, public ICurrentTrackUIModel {
 Q_OBJECT
 public:
    template<typename CurrentTrackView>
    CurrentTrackUIModel(CurrentTrackView* view);
    ~CurrentTrackUIModel();

    void shuffle() override;
    void previousTrack() override;
    void play() override;
    void nextTrack() override;
    void repeat() override;
    void mute() override;
 signals:
    void shuffleFunctionSuccess();
    void previousTrackFunctionSuccess();
    void playFunctionSuccess();
    void nextTrackFunctionSuccess();
    void repeatFunctionSuccess();
    void muteFunctionSuccess();
 private:
    enum RepeatFlags {
        None = 0, 
        One = 1, 
        All = 2
    };
    
    bool shuffleFlag_;
    bool playFlag_;
    QMediaPlayer* mPlayer_;
};

//////////////////////////////////////// Current Track Controller ////////////////////////////////////////

class CurrentTrackController : public QMainWindow, public ICurrentTrackController {
 Q_OBJECT
 public:
    friend class CurrentTrackView;

    template <typename View>
    CurrentTrackController(View* view);
    ~CurrentTrackController() = default;
 private slots:
    void shuffle() override;
    void previousTrack() override;
    void play() override;
    void nextTrack() override;
    void repeat() override;
    void mute() override;
 private:
    CurrentTrackUIModel model_;
};

//////////////////////////////////////// Current Track View ////////////////////////////////////////

class CurrentTrackView : public QMainWindow {
 Q_OBJECT
 public:
    explicit CurrentTrackView(QWidget* parent);
    ~CurrentTrackView();
 private slots:
    void shuffleClicked();
    void previousTrackClicked();
    void playClicked();
    void nextTrackClicked();
    void repeatClicked();
    void muteClicked();

 private:
    CurrentTrackWindow baseFunctionalButtons_;
    CurrentTrackController controller_;
    CurrentTrackUIModel model_ ;
};
