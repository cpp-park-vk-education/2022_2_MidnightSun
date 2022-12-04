#include "CurrentTrack.hpp"

//////////////////////////////////////// Coordinats x ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_X = 150;
const int SHUFFLE_BUTTON_X = 325;
const int PREVIOUS_TRACK_BUTTON_X = 370;
const int PLAY_BUTTON_X = 415;
const int NEXT_TRACK_BUTTON_X = 480;
const int REPEAT_BUTTON_X = 525;
const int MUTE_BUTTON_X = 605;
const int VOLUME_SLIDER_X = 655;

//////////////////////////////////////// Coordinats y ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_Y = 500;
const int BUTTON_Y = 535;
const int PLAY_BUTTON_Y = 525;

//////////////////////////////////////// Widths ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_WIDTH = 700;
const int BUTTON_WIDTH = 35;
const int PLAY_BUTTON_WIDTH = 50;
const int VOLUME_SLIDER_WIDTH = 125;

//////////////////////////////////////// Heights ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_HEIGHT = 150;
const int BUTTON_HEIGHT = 35;
const int PLAY_BUTTON_HEIGHT = 50;

//////////////////////////////////////// Names ////////////////////////////////////////

const char* SHUFFLE_NAME = "shuffle";
const char* PREVIOUS_TRACK_NAME = "previousTrack";
const char* PLAY_NAME = "play";
const char* NEXT_TRACK_NAME = "nextTrack";
const char* REPEAT_NAME = "repeat";
const char* MUTE_NAME = "mute";

//////////////////////////////////////// Current Track Buttons ////////////////////////////////////////

Button::Button(QWidget* parent)
    : button_(new QPushButton(parent)) {}

Button::~Button() {
    delete button_;
}

void Button::setStyle(int buttonX, int buttonY,
                       int buttonWidth, int buttonHeight,
                       const char* buttonName) {
    button_->setObjectName(buttonName);
    button_->setGeometry(QRect(buttonX, buttonY,
                               buttonWidth, buttonHeight));
}

QPushButton* Button::getPtr() const {
    return button_;
}

Slider::Slider(QWidget* parent)
    : slider_(new QSlider(Qt::Horizontal, parent)) {}

Slider::~Slider() {
    delete slider_;
}

void Slider::setStyle(int buttonX, int buttonY,
                       int buttonWidth, int buttonHeight,
                       const char* buttonName) {
    slider_->setObjectName(buttonName);
    slider_->setGeometry(QRect(buttonX, buttonY,
                               buttonWidth, buttonHeight));
}

VolumeSlider::VolumeSlider(QWidget* parent)
    : Slider(parent) {
    setStyle(VOLUME_SLIDER_X, BUTTON_Y,
             VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT,
             "заглущка");
}

DurationSlider::DurationSlider(QWidget* parent)
    : Slider(parent) {
        // TODO
    setStyle(VOLUME_SLIDER_X, BUTTON_Y,
             VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT,
             "заглущка");
}

CurrentTrackWidget::CurrentTrackWidget(QWidget* parent)
    : currentTrackWidget_(new QWidget(parent)) {
    currentTrackWidget_->setObjectName("currentTrackWidget");
    currentTrackWidget_->setGeometry(QRect(CURRENT_TRACK_WIDGET_X,
                                           CURRENT_TRACK_WIDGET_Y,
                                           CURRENT_TRACK_WIDGET_WIDTH,
                                           CURRENT_TRACK_WIDGET_HEIGHT));
}

CurrentTrackWidget::~CurrentTrackWidget() {
    delete currentTrackWidget_;
}

//////////////////////////////////////// Current Track UIModel ////////////////////////////////////////

template<typename CurrentTrackView>
CurrentTrackUIModel::CurrentTrackUIModel(CurrentTrackView* view) {
    connect(this, SIGNAL(shuffleFunctionSuccess()),
            view, SLOT(shuffleClicked()));
    connect(this, SIGNAL(previousTrackFunctionSuccess()),
            view, SLOT(previousTrackClicked()));
    connect(this, SIGNAL(playFunctionSuccess()),
            view, SLOT(playClicked()));
    connect(this, SIGNAL(nextTrackFunctionSuccess()),
            view, SLOT(nextTrackClicked()));
    connect(this, SIGNAL(repeatFunctionSuccess()),
            view, SLOT(repeatClicked()));
    connect(this, SIGNAL(muteFunctionSuccess()),
            view, SLOT(muteClicked()));
    connect(this, SIGNAL(moveDurationSliderSuccess()),
            view, SLOT(durationSliderMoved()));
    connect(this, SIGNAL(moveVolumeSliderSuccess()),
            view, SLOT(volumeSliderMoved()));
}

void CurrentTrackUIModel::shuffle() {
    // ...
    emit shuffleFunctionSuccess();
}

void CurrentTrackUIModel::previousTrack() {
    // ...
    emit previousTrackFunctionSuccess();
}

void CurrentTrackUIModel::play() {
    // ...
    emit playFunctionSuccess();
}

void CurrentTrackUIModel::nextTrack() {
    // ...
    emit nextTrackFunctionSuccess();
}

void CurrentTrackUIModel::repeat() {
    // ...
    emit repeatFunctionSuccess();
}

void CurrentTrackUIModel::mute() {
    // ...
    emit muteFunctionSuccess();
}

void CurrentTrackUIModel::moveDurationSlider() {
    // ...
    emit moveDurationSliderSuccess();
}

void CurrentTrackUIModel::moveVolumeSlider() {
    // ...
    emit moveVolumeSliderSuccess();
}

CurrentTrackUIModel::~CurrentTrackUIModel() {
    delete mPlayer_;
}

//////////////////////////////////////// Current Track Controller ////////////////////////////////////////

template <typename CurrentTrackView>
CurrentTrackController::CurrentTrackController(CurrentTrackView* view) 
    : model_(view) {}

void CurrentTrackController::shuffle() {
    model_.shuffle();
}

void CurrentTrackController::previousTrack() {
    model_.previousTrack();
}

void CurrentTrackController::play() {
    model_.play();
}

void CurrentTrackController::nextTrack() {
    model_.nextTrack();
}

void CurrentTrackController::repeat() {
    model_.repeat();
}

void CurrentTrackController::mute() {
    model_.mute();
}

void CurrentTrackController::moveDurationSlider() {
    model_.moveDurationSlider();
}

void CurrentTrackController::moveVolumeSlider() {
    model_.moveVolumeSlider();
}

//////////////////////////////////////// Current Track View ////////////////////////////////////////

CurrentTrackView::CurrentTrackView(QWidget* parent)
    : controller_(this),
      currentTrackWidget_(parent),
      shuffle_(parent),
      previousTrack_(parent),
      play_(parent),
      nextTrack_(parent),
      repeat_(parent),
      mute_(parent),
      durationSlider_(parent),
      volumeSlider_(parent) {

    connect(shuffle_.getPtr(), SIGNAL(clicked()), 
            &controller_, SLOT(shuffle()));
    connect(previousTrack_.getPtr(), SIGNAL(clicked()), 
            &controller_, SLOT(previousTrack()));
    connect(play_.getPtr(), SIGNAL(clicked()), 
            &controller_, SLOT(play()));
    connect(nextTrack_.getPtr(), SIGNAL(clicked()), 
            &controller_, SLOT(nextTrack()));
    connect(repeat_.getPtr(), SIGNAL(clicked()), 
            &controller_, SLOT(repeat()));
    connect(mute_.getPtr(), SIGNAL(clicked()), 
            &controller_, SLOT(mute()));

    shuffle_.setStyle(SHUFFLE_BUTTON_X, BUTTON_Y,
                      BUTTON_WIDTH, BUTTON_HEIGHT,
                      SHUFFLE_NAME);
    previousTrack_.setStyle(PREVIOUS_TRACK_BUTTON_X, BUTTON_Y,
                            BUTTON_WIDTH, BUTTON_HEIGHT,
                            PREVIOUS_TRACK_NAME);
    play_.setStyle(PLAY_BUTTON_X, PLAY_BUTTON_Y,
                   PLAY_BUTTON_WIDTH, PLAY_BUTTON_HEIGHT,
                   PLAY_NAME);
    nextTrack_.setStyle(NEXT_TRACK_BUTTON_X, BUTTON_Y,
                        BUTTON_WIDTH, BUTTON_HEIGHT,
                        NEXT_TRACK_NAME);
    repeat_.setStyle(REPEAT_BUTTON_X, BUTTON_Y,
                     BUTTON_WIDTH, BUTTON_HEIGHT,
                     REPEAT_NAME);
    mute_.setStyle(MUTE_BUTTON_X, BUTTON_Y,
                   BUTTON_WIDTH, BUTTON_HEIGHT,
                   MUTE_NAME);
}

#include <QDebug>

void CurrentTrackView::shuffleClicked() {
    // shuffle_.editStatus();
    qDebug() << 1;
}

void CurrentTrackView::previousTrackClicked() {

}

void CurrentTrackView::playClicked() {

}

void CurrentTrackView::nextTrackClicked() {

}

void CurrentTrackView::repeatClicked() {

}

void CurrentTrackView::muteClicked() {

}

void CurrentTrackView::durationSliderMoved() {

}

void CurrentTrackView::volumeSliderMoved() {

}
