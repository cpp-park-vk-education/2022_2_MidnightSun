#pragma once

#include "currentTrackController.hpp"
#include "currentTrackUIModel.hpp"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

//////////////////////////////////////// Current Track Buttons ////////////////////////////////////////

class Button : public QObject {
 Q_OBJECT

 public:
    explicit Button(QWidget* parent = nullptr);
    ~Button();

    void editStatus();
    void setStyle(int buttonX, int buttonY,
                  int buttonWidth, int buttonHeight,
                  const char* buttonName);
    QPushButton* getPtr() const;

 protected:
    QPushButton* button_;
};

class Slider : public QObject  {
 Q_OBJECT
 public:
    explicit Slider(QWidget* parent = nullptr);
    ~Slider();

    void setStyle(int buttonX, int buttonY,
                  int buttonWidth, int buttonHeight,
                  const char* buttonName);
 private:
    QSlider* slider_;
};

class VolumeSlider : public Slider {
 public:
    explicit VolumeSlider(QWidget* parent);
};

class DurationSlider : public Slider {
 public:
    explicit DurationSlider(QWidget* parent);
};

class CurrentTrackWidget {
 public:
    explicit CurrentTrackWidget(QWidget* parent = nullptr);
    ~CurrentTrackWidget();
 private:
    QWidget* currentTrackWidget_;
};

//////////////////////////////////////// Current Track UIModel ////////////////////////////////////////

class CurrentTrackUIModel : public QMainWindow, public ICurrentTrackUIModel {
 Q_OBJECT

 public:
    template<typename CurrentTrackView>
    explicit CurrentTrackUIModel(CurrentTrackView* view);
    ~CurrentTrackUIModel();

    void shuffle() override;
    void previousTrack() override;
    void play() override;
    void nextTrack() override;
    void repeat() override;
    void mute() override;
    void moveDurationSlider() override;
    void moveVolumeSlider() override;

 signals:
    void shuffleFunctionSuccess();
    void previousTrackFunctionSuccess();
    void playFunctionSuccess();
    void nextTrackFunctionSuccess();
    void repeatFunctionSuccess();
    void muteFunctionSuccess();
    void moveDurationSliderSuccess();
    void moveVolumeSliderSuccess();

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
    template <typename CurrentTrackView>
    explicit CurrentTrackController(CurrentTrackView* view);
    ~CurrentTrackController() = default;

 private slots:
    void shuffle() override;
    void previousTrack() override;
    void play() override;
    void nextTrack() override;
    void repeat() override;
    void mute() override;
    void moveDurationSlider() override;
    void moveVolumeSlider() override;

 private:
    CurrentTrackUIModel model_;
};

//////////////////////////////////////// Current Track View ////////////////////////////////////////

class CurrentTrackView : public QObject {
 Q_OBJECT
 public:
    explicit CurrentTrackView(QWidget* parent);
    ~CurrentTrackView() = default;

 private slots:
    void shuffleClicked();
    void previousTrackClicked();
    void playClicked();
    void nextTrackClicked();
    void repeatClicked();
    void muteClicked();
    void durationSliderMoved();
    void volumeSliderMoved();

 private:
    CurrentTrackController controller_;

    CurrentTrackWidget currentTrackWidget_;

    Button shuffle_;
    Button previousTrack_;
    Button play_;
    Button nextTrack_;
    Button repeat_;
    Button mute_;

    DurationSlider durationSlider_;
    VolumeSlider volumeSlider_;
};
