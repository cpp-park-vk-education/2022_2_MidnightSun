#include "CurrentTrackView.hpp"


const int CURRENT_TRACK_WIDGET_X = 150;
const int SHUFFLE_BUTTON_X = 325;
const int PREVIOUS_TRACK_BUTTON_X = 370;
const int PLAY_BUTTON_X = 415;
const int NEXT_TRACK_BUTTON_X = 480;
const int REPEAT_BUTTON_X = 525;
const int MUTE_BUTTON_X = 605;
const int VOLUME_SLIDER_X = 655;
const int DURATION_SLIDER_X = 250;

//////////////////////////////////////// Coordinats y ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_Y = 475;
const int BUTTON_Y = 535;
const int PLAY_BUTTON_Y = 525;
const int DURATION_SLIDER_Y = 485;

//////////////////////////////////////// Widths ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_WIDTH = 650;
const int BUTTON_WIDTH = 35;
const int PLAY_BUTTON_WIDTH = 50;
const int VOLUME_SLIDER_WIDTH = 125;
const int DURATION_SLIDER_WIDTH = 450;

//////////////////////////////////////// Heights ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_HEIGHT = 150;
const int BUTTON_HEIGHT = 35;
const int PLAY_BUTTON_HEIGHT = 50;

//////////////////////////////////////// Names ////////////////////////////////////////

const char* CURRENT_TRACK_WIDGET_NAME = "currentTrackWidget";
const char* SHUFFLE_NAME = "shuffle";
const char* PREVIOUS_TRACK_NAME = "previousTrack";
const char* PLAY_NAME = "play";
const char* NEXT_TRACK_NAME = "nextTrack";
const char* REPEAT_NAME = "repeat";
const char* MUTE_NAME = "muteOff";
const char* VOLUME_SLIDER_NAME = "volumeSlider";
const char* DURATION_SLIDER_NAME = "durationSlider";

//////////////////////////////////////// Current Track View ////////////////////////////////////////

CurrentTrackView::CurrentTrackView(CurrentTrackUIModel* model, QWidget* parent, int offset)
    : model_(model),
      controller_(new CurrentTrackController(model)),
      currentTrackWidget_(new QWidget(parent)),
      shuffle_(new QPushButton(parent)),
      previousTrack_(new QPushButton(parent)),
      play_(new QPushButton(parent)),
      nextTrack_(new QPushButton(parent)),
      repeat_(new QPushButton(parent)),
      mute_(new QPushButton(parent)),
      durationSlider_(new QSlider(Qt::Horizontal, parent)),
      volumeSlider_(new QSlider(Qt::Horizontal, parent)),
      offset_(offset) {

    connect(play_, SIGNAL(clicked()),
            this, SLOT(play()));

    connect(repeat_, SIGNAL(clicked()),
            this, SLOT(repeat()));

    connect(mute_, SIGNAL(clicked()),
            this, SLOT(mute()));

    connect(shuffle_, SIGNAL(clicked()),
            this, SLOT(shuffle()));

    connect(previousTrack_, SIGNAL(clicked()),
            this, SLOT(previousTrack()));

    connect(nextTrack_, SIGNAL(clicked()),
            this, SLOT(nextTrack()));

    connect(durationSlider_, SIGNAL(valueChanged(int)),
            this, SLOT(setDuration(int)));
   
    connect(volumeSlider_, SIGNAL(valueChanged(int)),
            this, SLOT(setVolume(int)));

    play_->setObjectName("play");
    repeat_->setObjectName("repeat");
    mute_->setObjectName("muteOff");
    volumeSlider_->setSliderPosition(50);

    setStyle(CURRENT_TRACK_WIDGET_X, CURRENT_TRACK_WIDGET_Y,
             CURRENT_TRACK_WIDGET_WIDTH, CURRENT_TRACK_WIDGET_HEIGHT,
             CURRENT_TRACK_WIDGET_NAME, currentTrackWidget_);

    setStyle(SHUFFLE_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             SHUFFLE_NAME, shuffle_);

    setStyle(PREVIOUS_TRACK_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             PREVIOUS_TRACK_NAME, previousTrack_);

    setStyle(PLAY_BUTTON_X, PLAY_BUTTON_Y,
             PLAY_BUTTON_WIDTH, PLAY_BUTTON_HEIGHT,
             PLAY_NAME, play_);

    setStyle(NEXT_TRACK_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             NEXT_TRACK_NAME, nextTrack_);

    setStyle(REPEAT_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             REPEAT_NAME, repeat_);

    setStyle(MUTE_BUTTON_X, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             MUTE_NAME, mute_);

    setStyle(VOLUME_SLIDER_X, BUTTON_Y,
             VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT,
             DURATION_SLIDER_NAME, volumeSlider_);

    setStyle(DURATION_SLIDER_X, DURATION_SLIDER_Y,
             DURATION_SLIDER_WIDTH, BUTTON_HEIGHT,
             VOLUME_SLIDER_NAME, durationSlider_);
}

CurrentTrackView::CurrentTrackView(int offset)
    : offset_(offset) {}

// CurrentTrackView::CurrentTrackView(const CurrentTrackView& rhs) {
//     initializeView();
// }

void CurrentTrackView::setStyle(int buttonX, int buttonY,
                                int buttonWidth, int buttonHeight,
                                const char* buttonName, QWidget* object) {
    object->setObjectName(buttonName);
    object->setGeometry(QRect(buttonX, buttonY - offset_,
                              buttonWidth , buttonHeight));
}

void CurrentTrackView::currentTrackChanged() {
    if (repeat_->objectName() == "repeatOn") {
        controller_->repeat();
    }
    controller_->setDuration(0);
    // controller_->play(currentTrackPosition_);
    // TODO .. в перспективе
    if (mute_->objectName() == "muteOn") {
        controller_->mute();
        // controller_->mute();
        // mute();
    }
//   setVolume(durationSlider_->) // volumeSLider .. вернуть
}

// void CurrentTrackView::currentTrackChanged(int currentTrackPosition) {
//     currentTrackPosition_ = currentTrackPosition;
// }

// void CurrentTrackView::deleteCurrentTrack(int currentTrackPosition) {
//     controller_->
// }

void CurrentTrackView::play() {
    if (play_->objectName() == "play") {
        controller_->play();
        play_->setObjectName("pause");
        play_->setStyleSheet("QPushButton#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pause.png); } QPushButton:hover#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pauseFocus.png); }");
    } else {
        controller_->pause();
        play_->setObjectName("play");
        play_->setStyleSheet("QPushButton#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");
    }
}

void CurrentTrackView::repeat() {
    controller_->repeat();
    if (repeat_->objectName() == "repeat") {
        repeat_->setObjectName("repeatOn");
        repeat_->setStyleSheet("QPushButton#repeatOn { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    } else {
        repeat_->setObjectName("repeat");
        repeat_->setStyleSheet("QPushButton#repeat { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover#repeat { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    }
}

void CurrentTrackView::mute() {
    controller_->mute();
    if (mute_->objectName() == "muteOff") {
        mute_->setObjectName("muteOn");
        mute_->setStyleSheet("QPushButton#muteOn { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOn.png); } QPushButton:hover#muteOn { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOnFocus.png); }");
    } else {
        mute_->setObjectName("muteOff");
        mute_->setStyleSheet("QPushButton#muteOff { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover#muteOff { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");
    }
}

void CurrentTrackView::setDuration(int position) {
//     qDebug() << model_->currentTrack_->track_->duration();
    controller_->setDuration(position * 1000);
}

void CurrentTrackView::setVolume(int position) {
    controller_->setVolume(position);
}


void CurrentTrackView::shuffle() {
    controller_->shuffle();
}

void CurrentTrackView::previousTrack() {
    controller_->previousTrack();
}

void CurrentTrackView::nextTrack() {
    controller_->nextTrack();
}

void CurrentTrackView::setCurrentTrackMediator(Mediator* mediator) {
    model_->setCurrentTrackMediator(mediator);
}

CurrentTrackUIModel* CurrentTrackView::getModel() {
    return model_;
}
