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

// IButton::IButton(QWidget* parent)
//     : button_(new QPushButton(parent)) {}

// IButton::~IButton() {

// }

// CurrentTrackWidget::CurrentTrackWidget(QWidget* parent)
//     : currentTrackWidget_(new QWidget(parent)) {
//     currentTrackWidget_->setObjectName("currentTrackWidget");
//     currentTrackWidget_->setGeometry(QRect(CURRENT_TRACK_WIDGET_X,
//                                            CURRENT_TRACK_WIDGET_Y,
//                                            CURRENT_TRACK_WIDGET_WIDTH,
//                                            CURRENT_TRACK_WIDGET_HEIGHT));
// }

// CurrentTrackWidget::~CurrentTrackWidget() {}

// void IButton::setStyle(int buttonX, int buttonY,
//                        int buttonWidth, int buttonHeight,
//                        const char* buttonName) {
//     button_->setObjectName(buttonName);
//     button_->setGeometry(QRect(buttonX, buttonY,
//                                buttonWidth, buttonHeight));
// }

IButton::IButton(QWidget* parent)
    : button_(new QPushButton(parent)) {}

IButton::~IButton() {
    delete button_;
}

void IButton::setStyle(int buttonX, int buttonY,
                       int buttonWidth, int buttonHeight,
                       const char* buttonName) {
    button_->setObjectName(buttonName);
    button_->setGeometry(QRect(buttonX, buttonY,
                               buttonWidth, buttonHeight));
}

ShuffleButton::ShuffleButton(QWidget* parent)
    : IButton(parent) {
    setStyle(SHUFFLE_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             SHUFFLE_NAME);
}

PreviousTrackButton::PreviousTrackButton(QWidget* parent)
    : IButton(parent) {
    setStyle(PREVIOUS_TRACK_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             PREVIOUS_TRACK_NAME);
}

PlayButton::PlayButton(QWidget* parent)
    : IButton(parent) {
    setStyle(PLAY_BUTTON_X, PLAY_BUTTON_Y,
             PLAY_BUTTON_WIDTH, PLAY_BUTTON_HEIGHT,
             PLAY_NAME);
}

NextTrackButton::NextTrackButton(QWidget* parent)
    : IButton(parent) {
    setStyle(NEXT_TRACK_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             NEXT_TRACK_NAME);
}

RepeatButton::RepeatButton(QWidget* parent)
    : IButton(parent) {
    setStyle(REPEAT_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             REPEAT_NAME);
}

MuteButton::MuteButton(QWidget* parent)
    : IButton(parent) {
    setStyle(MUTE_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             MUTE_NAME);
}

VolumeSlider::VolumeSlider(QWidget* parent)
    : volumeSlider_(new QSlider(Qt::Horizontal, parent)) {
    volumeSlider_->setGeometry(QRect(VOLUME_SLIDER_X, BUTTON_Y,
                                     VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT));
}

VolumeSlider::~VolumeSlider() {
    delete volumeSlider_;
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

//////////////////////////////////////// Current Track Window ////////////////////////////////////////

CurrentTrackWindow::CurrentTrackWindow(QWidget* parent)
    : currentTrackWidget_(parent),
      shuffle_(parent),
      previousTrack_(parent),
      play_(parent),
      nextTrack_(parent),
      repeat_(parent),
      mute_(parent),
      volumeSlider_(parent) {}

//////////////////////////////////////// Current Track UIModel ////////////////////////////////////////

template<typename CurrentTrackView>
CurrentTrackUIModel::CurrentTrackUIModel(CurrentTrackView* view) {
// Связывание вьюшки и сигналов UI модели

    connect(this, SIGNAL(shuffleFunctionSuccess()), view, SLOT(shuffleClicked()));
    connect(this, SIGNAL(previousTrackFunctionSuccess()), view, SLOT(previousTrackClicked()));
    connect(this, SIGNAL(playFunctionSuccess()), view, SLOT(playClicked()));
    connect(this, SIGNAL(nextTrackFunctionSuccess()), view, SLOT(nextTrackClicked()));
    connect(this, SIGNAL(repeatFunctionSuccess()), view, SLOT(repeatClicked()));
    connect(this, SIGNAL(muteFunctionSuccess()), view, SLOT(muteClicked()));
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

CurrentTrackUIModel::~CurrentTrackUIModel() {
    delete mPlayer_;
}

//////////////////////////////////////// Current Track Controller ////////////////////////////////////////

template <typename View>
CurrentTrackController::CurrentTrackController(View* view)
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

//////////////////////////////////////// Current Track View ////////////////////////////////////////

CurrentTrackView::CurrentTrackView(QWidget* parent)
    : baseFunctionalButtons_(parent),
      controller_(this),
      model_(this) {

// Упрощенная запись кнопок

    auto shuffle = baseFunctionalButtons_.shuffle_.button_;
    auto previousTrack = baseFunctionalButtons_.previousTrack_.button_;
    auto play = baseFunctionalButtons_.play_.button_;
    auto nextTrack = baseFunctionalButtons_.nextTrack_.button_;
    auto repeat = baseFunctionalButtons_.repeat_.button_;
    auto mute = baseFunctionalButtons_.mute_.button_;

// Связывание слотов контроллера и сигналов кнопок при нажатии

    connect(shuffle, SIGNAL(clicked()), &controller_, SLOT(shuffle()));
    connect(previousTrack, SIGNAL(clicked()), &controller_, SLOT(previousTrack()));
    connect(play, SIGNAL(clicked()), &controller_, SLOT(play()));
    connect(nextTrack, SIGNAL(clicked()), &controller_, SLOT(nextTrack()));
    connect(repeat, SIGNAL(clicked()), &controller_, SLOT(repeat()));
    connect(mute, SIGNAL(clicked()), &controller_, SLOT(mute()));
}

void CurrentTrackView::shuffleClicked() {}

void CurrentTrackView::previousTrackClicked() {}

void CurrentTrackView::playClicked() {}

void CurrentTrackView::nextTrackClicked() {}

void CurrentTrackView::repeatClicked() {}

void CurrentTrackView::muteClicked() {}

CurrentTrackView::~CurrentTrackView() {}
