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

const int CURRENT_TRACK_WIDGET_HEIGHT = 250;
const int BUTTON_HEIGHT = 35;
const int PLAY_BUTTON_HEIGHT = 50;

//////////////////////////////////////// Names ////////////////////////////////////////

const char* SHUFFLE_NAME = "shuffle";
const char* PREVIOUS_TRACK_NAME = "previousTrack";
const char* PLAY_NAME = "play";
const char* NEXT_TRACK_NAME = "nextTrack";
const char* REPEAT_NAME = "repeat";
const char* MUTE_NAME = "mute";
const char* VOLUME_SLIDER_NAME = "volumeSlider";
const char* DURATION_SLIDER_NAME = "durationSlider";

//////////////////////////////////////// Current Track View ////////////////////////////////////////

CurrentTrackView::CurrentTrackView(CurrentTrackUIModel* model, QWidget* parent)
    : model_(new QCurrentTrackUIModel(model)),
      controller_(new QCurrentTrackController(model)),
      currentTrackWidget_(new QWidget(parent)),
      shuffle_(new QPushButton(parent)),
      previousTrack_(new QPushButton(parent)),
      play_(new QPushButton(parent)),
      nextTrack_(new QPushButton(parent)),
      repeat_(new QPushButton(parent)),
      mute_(new QPushButton(parent)),
      durationSlider_(new QSlider(Qt::Horizontal, parent)),
      volumeSlider_(new QSlider(Qt::Horizontal, parent)) {

    currentTrackWidget_->setObjectName("currentTrackWidget");
    currentTrackWidget_->setGeometry(QRect(CURRENT_TRACK_WIDGET_X,
                                           CURRENT_TRACK_WIDGET_Y,
                                           CURRENT_TRACK_WIDGET_WIDTH,
                                           CURRENT_TRACK_WIDGET_HEIGHT));

    // connect(mute_, SIGNAL(clicked()),
    //         controller_, SLOT(mute()));

    // connect(mute_, SIGNAL(click()),
    //         this, SLOT(muteOffButtonChanged()));

    // connect(model_->mplayer_, SIGNAL(volumeChanged(int)),
    //         this, SLOT(volumeTime(int)));

    connect(shuffle_, SIGNAL(clicked()),
            controller_, SLOT(shuffle()));

    connect(previousTrack_, SIGNAL(clicked()),
            controller_, SLOT(previousTrack()));

    connect(play_, SIGNAL(clicked()),
            controller_, SLOT(play()));
    
    connect(play_, SIGNAL(clicked()), 
            controller_, SLOT(pause()));

    // connect(stop_, SIGNAL(clicked()), 
            // controller_, SLOT(stop()));

    connect(nextTrack_, SIGNAL(clicked()),
            controller_, SLOT(nextTrack()));

    connect(repeat_, SIGNAL(clicked()),
            controller_, SLOT(repeat()));

    connect(mute_, SIGNAL(clicked()),
            controller_, SLOT(mute()));

    connect(volumeSlider_, SIGNAL(sliderMoved(int)),
            controller_, SLOT(setVolume(int)));

    connect(volumeSlider_, SIGNAL(sliderMoved(int)),
            controller_, SLOT(setDuration(int)));

    // connect(model_, SIGNAL(playClicked()),
    //         this, SLOT(playButtonChanged()));

    // connect(model_, SIGNAL(pauseClicked()),
    //         this, SLOT(pauseButtonChanged()));

    // connect(model_, SIGNAL(volumeSliderMoved(int)),
    //         controller_, SLOT(moveVolumeSlider(int)));

    // connect(model_, SIGNAL(muteOffClicked()),
    //         this, SLOT(muteOffButtonChanged()));

    // connect(model_, SIGNAL(muteOnClicked()),
    //         this, SLOT(muteOnButtonChanged()));


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
             VOLUME_SLIDER_NAME, volumeSlider_);

    setStyle(DURATION_SLIDER_X, DURATION_SLIDER_Y,
             DURATION_SLIDER_WIDTH, BUTTON_HEIGHT,
             DURATION_SLIDER_NAME, durationSlider_);
}

void CurrentTrackView::setStyle(int buttonX, int buttonY,
                                int buttonWidth, int buttonHeight,
                                const char* buttonName, QWidget* object) {
    object->setObjectName(buttonName);
    object->setGeometry(QRect(buttonX, buttonY,
                              buttonWidth, buttonHeight));
}

void CurrentTrackView::playButtonChanged() {
    play_->setObjectName("play");
    play_->setStyleSheet("QPushButton#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");
}

void CurrentTrackView::pauseButtonChanged() {
    play_->setObjectName("pause");
    play_->setStyleSheet("QPushButton#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pause.png); } QPushButton:hover#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pauseFocus.png); }");
}

void CurrentTrackView::shuffleOffButtonChanged() {

}

void CurrentTrackView::shuffleOnButtonChanged() {

}

void CurrentTrackView::repeatOffButtonChanged() {

}

void CurrentTrackView::repeatOnButtonChanged() {

}

void CurrentTrackView::muteOffButtonChanged() {

}

void CurrentTrackView::muteOnButtonChanged() {

}

// void CurrentTrackView::playButtonChanged() {
//     play_->setObjectName("play");
//     play_->setStyleSheet("QPushButton#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");
// }

// void CurrentTrackView::pauseButtonChanged() {
//     play_->setObjectName("pause");
//     play_->setStyleSheet("QPushButton#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pause.png); } QPushButton:hover#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pauseFocus.png); }");

// }

// void CurrentTrackView::shuffleOffButtonChanged() {

// }

// void CurrentTrackView::shuffleOnButtonChanged() {

// }

// void CurrentTrackView::repeatOffButtonChanged() {

// }

// void CurrentTrackView::repeatOnButtonChanged() {

// }

// void CurrentTrackView::muteOffButtonChanged() {
//     mute_->setObjectName("muteOn");
//     mute_->setStyleSheet("QPushButton#muteOn { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOn.png); } QPushButton:hover#muteOn { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOnFocus.png); }");
// }

// void CurrentTrackView::muteOnButtonChanged() {
//     mute_->setObjectName("muteOff");
//     mute_->setStyleSheet("QPushButton#muteOff { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover#muteOff { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");
// }

void CurrentTrackView::setCurrentTrackMediator(Mediator* mediator) {
    model_->setCurrentTrackMediator(mediator);
}

CurrentTrackUIModel* CurrentTrackView::getModel() {
    return model_->model_;
}
