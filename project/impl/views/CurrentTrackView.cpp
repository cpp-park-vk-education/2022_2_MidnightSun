#include "CurrentTrackView.hpp"


const int CURRENT_TRACK_WIDGET_X = 150 - 125;
const int SHUFFLE_BUTTON_X = 325 - 70 - 125;
const int PREVIOUS_TRACK_BUTTON_X = 370 - 70 - 125;
const int PLAY_BUTTON_X = 415 - 70 - 125;
const int NEXT_TRACK_BUTTON_X = 480 - 70 - 125;
const int REPEAT_BUTTON_X = 525 - 70 - 125;
const int MUTE_BUTTON_X = 605 - 110;
const int VOLUME_SLIDER_X = 655 - 110;
const int DURATION_SLIDER_X = 250 - 70 - 110;
const int CURRENT_TRACK_TITLE = 1;

//////////////////////////////////////// Coordinats y ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_Y = 450;
const int BUTTON_Y = 535;
const int PLAY_BUTTON_Y = 525;
const int DURATION_SLIDER_Y = 485;

//////////////////////////////////////// Widths ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_WIDTH = 650;
const int BUTTON_WIDTH = 35;
const int PLAY_BUTTON_WIDTH = 50;
const int VOLUME_SLIDER_WIDTH = 125;
const int DURATION_SLIDER_WIDTH = 400;

//////////////////////////////////////// Heights ////////////////////////////////////////

const int CURRENT_TRACK_WIDGET_HEIGHT = 275;
const int BUTTON_HEIGHT = 35;
const int PLAY_BUTTON_HEIGHT = 50;

//////////////////////////////////////// Names ////////////////////////////////////////

const char* CURRENT_TRACK_WIDGET_NAME = "currentTrackWidget";
const char* SHUFFLE_NAME = "shuffle";
const char* PREVIOUS_TRACK_NAME = "previousTrack";
const char* PLAY_NAME = "play";
const char* NEXT_TRACK_NAME = "nextTrack";
const char* REPEAT_NAME = "Off";
const char* MUTE_NAME = "Off";
const char* VOLUME_SLIDER_NAME = "volumeSlider";
const char* DURATION_SLIDER_NAME = "durationSlider";

//////////////////////////////////////// Current Track View ////////////////////////////////////////

CurrentTrackView::CurrentTrackView(CurrentTrackUIModel* model, QWidget* parent)
    : currentTracksCount_(0),
    //   currentTracks_(10, 999),
      model_(model),
      controller_(new CurrentTrackController(model)),
      parent_(parent),
      currentTrackWidget_(new QWidget(parent)),
    //   shuffle_(new QPushButton(parent)),
    //   previousTrack_(new QPushButton(parent)),
      play_(new QPushButton(parent)),
      repeat_(new QPushButton(parent)),
      mute_(new QPushButton(parent)),
      volumeSliderAll_(new QSlider(Qt::Horizontal, parent)),
    //   nextTrack_(new QPushButton(parent)),
    //   repeat_(new QPushButton(parent)),
    //   mute_(new QPushButton(parent)),
      currentTrackTitle_(new QLabel(parent)),
      currentTracksNumbers_(10, nullptr),
      playButtons_(10, nullptr),
      muteButtons_(10, nullptr),
      repeatButtons_(10, nullptr),
      durationSlider_(10, nullptr),
      trackNames_(10, nullptr),
      paths_(10),
    //   durationSlider_(std::vector<QSlider*> {new QSlider(Qt::Horizontal, parent)}),
      volumeSlider_(10, nullptr),
      playTracks_(10, nullptr),
      durationsBegin_(10),
      durationsEnd_(10) {
    //   a(std::vector<int>(10)) { 

    for (size_t i = 0; i < 10; ++i) {
        currentTracksNumbers_[i] = new QPushButton(parent);
        playButtons_[i] = new QPushButton(parent);
        muteButtons_[i] = new QPushButton(parent);
        repeatButtons_[i] = new QPushButton(parent);
        durationSlider_[i] = new QSlider(Qt::Horizontal, parent);
        volumeSlider_[i] = new QSlider(Qt::Horizontal, parent);
        trackNames_[i] = new QLabel(parent);
    }

    connect(play_, SIGNAL(clicked()),
            this, SLOT(playAll()));

    connect(repeat_, SIGNAL(clicked()),
            this, SLOT(repeatAll()));

    connect(mute_, SIGNAL(clicked()),
            this, SLOT(muteAll()));

    connect(volumeSliderAll_, SIGNAL(valueChanged(int)),
            this, SLOT(setVolumeAll(int)));

    // play_->setObjectName("Play");
    // repeat_->setObjectName("Off");
    // mute_->setObjectName("Off");

    // connect(repeat_, SIGNAL(clicked()),
    //         this, SLOT(repeat()));

    // connect(mute_, SIGNAL(clicked()),
    //         this, SLOT(mute()));

    // connect(shuffle_, SIGNAL(clicked()),
    //         this, SLOT(shuffle()));

    // connect(previousTrack_, SIGNAL(clicked()),
    //         this, SLOT(previousTrack()));

    // connect(nextTrack_, SIGNAL(clicked()),
            // this, SLOT(nextTrack()));

    // connect(durationSlider_, SIGNAL(valueChanged(int)),
            // this, SLOT(setDuration(int)));
   
    // connect(currentTracksNumbers_[0], SIGNAL(clicked()),
    //         this, SLOT(firstCurrentTrackClcked()));

    // connect(volumeSlider_, SIGNAL(valueChanged(int)),
    //         this, SLOT(setVolume(int)));

    // play_->setObjectName("play");
    // repeat_->setObjectName("repeat");
    // mute_->setObjectName("muteOff");
    // volumeSlider_->setSliderPosition(50);

    setStyle(CURRENT_TRACK_WIDGET_X - 200, CURRENT_TRACK_WIDGET_Y,
             CURRENT_TRACK_WIDGET_WIDTH + 200, CURRENT_TRACK_WIDGET_HEIGHT,
             CURRENT_TRACK_WIDGET_NAME, currentTrackWidget_);

    // setStyle(SHUFFLE_BUTTON_X - 20, BUTTON_Y,
    //          BUTTON_WIDTH, BUTTON_HEIGHT,
    //          SHUFFLE_NAME, shuffle_);

    // setStyle(PREVIOUS_TRACK_BUTTON_X - 20, BUTTON_Y,
    //          BUTTON_WIDTH, BUTTON_HEIGHT,
    //          PREVIOUS_TRACK_NAME, previousTrack_);

    setStyle(MUTE_BUTTON_X - 240, PLAY_BUTTON_Y,
             PLAY_BUTTON_WIDTH, PLAY_BUTTON_HEIGHT,
             PLAY_NAME, play_);

    // setStyle(NEXT_TRACK_BUTTON_X - 20, BUTTON_Y,
    //          BUTTON_WIDTH, BUTTON_HEIGHT,
    //          NEXT_TRACK_NAME, nextTrack_);

    setStyle(MUTE_BUTTON_X - 180, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             REPEAT_NAME, repeat_); 

    setStyle(MUTE_BUTTON_X - 180 + 50, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             MUTE_NAME, mute_);

    setStyle(MUTE_BUTTON_X - 180 + 90, BUTTON_Y,
             VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT,
             MUTE_NAME, volumeSliderAll_);

    play_->setObjectName("play");
    play_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");

    repeat_->setObjectName("Off");
    repeat_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");

    mute_->setObjectName("Off");
    mute_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");

    // setStyle(CURRENT_TRACK_TITLE, DURATION_SLIDER_Y - 35,
    //          BUTTON_WIDTH + 120, BUTTON_HEIGHT,
    //          MUTE_NAME, currentTrackTitle_);

    // setStyle(MUTE_BUTTON_X, BUTTON_Y,
    //          BUTTON_WIDTH, BUTTON_HEIGHT,
    //          MUTE_NAME, mute_);

    currentTrackTitle_->setText("Текущий трек:");
    volumeSliderAll_->setValue(50);
}

void CurrentTrackView::setStyle(int buttonX, int buttonY,
                                int buttonWidth, int buttonHeight,
                                const char* buttonName, QWidget* object) {
    object->setObjectName(buttonName);
    object->setGeometry(QRect(buttonX, buttonY,
                              buttonWidth, buttonHeight));
}

// int index = sender()->objectName().toStdString().back() - '0' - 1;
//     playTracks_[index]->repeat();
//     // controller_->repeat(index);
//     if (repeatButtons_[index]->objectName()[1] == "f") {
//         std::string string = "On" + std::to_string(index + 1);
//         QString a = string.c_str();
//         repeatButtons_[index]->setObjectName(a);
//         repeatButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
//     } else {
//         std::string string = "Off" + std::to_string(index + 1);
//         QString a = string.c_str();
//         repeatButtons_[index]->setObjectName(a);
//         repeatButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
//     }
// }

// void CurrentTrackView::mute() {
//     // qDebug() << "OK";
//     int index = sender()->objectName().toStdString().back() - '0' - 1;
//     // controller_->mute(index);
//     // playTracks_[index]->mute();
//     if (muteButtons_[index]->objectName()[1] == "f") {
//         playTracks_[index]->mute();
//         std::string string = "On" + std::to_string(index + 1);
//         QString a = string.c_str();
//         muteButtons_[index]->setObjectName(a);
//         muteButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOn.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOnFocus.png); }");
//     } else {
//         playTracks_[index]->mute();
//         std::string string = "Off" + std::to_string(index + 1);
//         QString a = string.c_str();
//         muteButtons_[index]->setObjectName(a);
//         muteButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");
//     }
// }

// void CurrentTrackView::playAll() {

// }



void CurrentTrackView::repeatAll() {
    if (repeat_->objectName()[1] == "f") {
        for (size_t i = 0; i < playTracks_.size(); ++i) {
            if (playTracks_[i] != nullptr) {
                emit repeatButtons_[i]->clicked();
            }
            if (playTracks_[i] != nullptr && !playTracks_[i]->isRepeating()) {
                emit repeatButtons_[i]->clicked();
            }
        }
        std::string string = "On";
        QString a = string.c_str();
        repeat_->setObjectName(a);
        repeat_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    } else {
        for (size_t i = 0; i < playTracks_.size(); ++i) {
            if (playTracks_[i] != nullptr) {
                emit repeatButtons_[i]->clicked();
            }
            if (playTracks_[i] != nullptr && playTracks_[i]->isRepeating()) {
                emit repeatButtons_[i]->clicked();
            }
        }
        std::string string = "Off";
        QString a = string.c_str();
        repeat_->setObjectName(a);
        repeat_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    }
}

void CurrentTrackView::muteAll() {
    if (mute_->objectName()[1] == "f") {
        for (size_t i = 0; i < playTracks_.size(); ++i) {
            if (playTracks_[i] != nullptr) {
                emit muteButtons_[i]->clicked();
            }
            if (playTracks_[i] != nullptr && !playTracks_[i]->isMuting()) {
                emit muteButtons_[i]->clicked();
            }
        }
        std::string string = "On";
        QString a = string.c_str();
        mute_->setObjectName(a);
        mute_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOn.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOnFocus.png); }");
    } else {
        for (size_t i = 0; i < playTracks_.size(); ++i) {
            if (playTracks_[i] != nullptr) {
                emit muteButtons_[i]->clicked();
            }
            if (playTracks_[i] != nullptr && playTracks_[i]->isMuting()) {
                emit muteButtons_[i]->clicked();
            }
        }
        std::string string = "Off";
        QString a = string.c_str();
        mute_->setObjectName(a);
        mute_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");
    }
}

void CurrentTrackView::setVolumeAll(int position) {
    for (size_t i = 0; i < playTracks_.size(); ++i) {
        if (playTracks_[i] != nullptr) {
            // qDebug() << i;
            emit volumeSlider_[i]->valueChanged(position);
        }
    }
}

#include "QTrack.hpp"
#include <Track.hpp>

void CurrentTrackView::currentTrackChanged(QString path, int index, bool flag) {

    connect(playButtons_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(play()));

    connect(muteButtons_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(mute()));

    connect(repeatButtons_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(repeat()));

    connect(volumeSlider_[currentTracksCount_], SIGNAL(valueChanged(int)),
            this, SLOT(setVolume(int)));

    connect(durationSlider_[currentTracksCount_], SIGNAL(valueChanged(int)),
            this, SLOT(setDuration(int)));

    currentTracksNumbers_[currentTracksCount_]->setObjectName("On" + QString(currentTracksCount_));
    currentTracksNumbers_[currentTracksCount_]->setStyleSheet("QPushButton { border: solid; border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/otrezok.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/otrezokFocus.png); }");

    std::string on = "On" + std::to_string(currentTracksCount_ + 1);
    std::string off = "Off" + std::to_string(currentTracksCount_ + 1);

    const char* On = &on[0];
    const char* Off = &off[0];

    if (flag) {
        auto qtrack = new QTrack;
        qtrack->setCurrentTrack(path);
        auto track = new Track(qtrack);

        auto string = path.toStdString();
        std::reverse(string.begin(), string.end());
        
        string = string.substr(string.find('.') + 1);
        string = string.substr(0, string.find('/'));
        
        std::reverse(string.begin(), string.end());

        track->setData(path.toStdString(),
                       string.substr(0, string.find('-')),
                       string.substr(string.find('-') + 1));

        playTracks_[currentTracksCount_] = track;
        playTracks_[currentTracksCount_]->track_->mplayer()->setObjectName(On);

        connect(playTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(positionChanged(qint64)), this, SLOT(elapsedTime(qint64)));
        connect(playTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(durationChanged(qint64)), this, SLOT(remaningTime(qint64)));
    }

    trackNames_[currentTracksCount_]->setText(QString::fromStdString(playTracks_[currentTracksCount_]->getData()));
    paths_[currentTracksCount_] = path;

    setStyle(CURRENT_TRACK_WIDGET_X - 200, CURRENT_TRACK_WIDGET_Y - 40 * currentTracksCount_,
             CURRENT_TRACK_WIDGET_WIDTH + 200, CURRENT_TRACK_WIDGET_HEIGHT + 40 * currentTracksCount_,
             CURRENT_TRACK_WIDGET_NAME, currentTrackWidget_);

    setStyle(5, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             On, currentTracksNumbers_[currentTracksCount_]);

    setStyle(MUTE_BUTTON_X - 90, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             Off, playButtons_[currentTracksCount_]);

    setStyle(MUTE_BUTTON_X + 10, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             Off, muteButtons_[currentTracksCount_]);

    setStyle(MUTE_BUTTON_X - 40, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             Off, repeatButtons_[currentTracksCount_]);

    setStyle(DURATION_SLIDER_X - 20, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             DURATION_SLIDER_WIDTH - 50, BUTTON_HEIGHT,
             On, durationSlider_[currentTracksCount_]);

    setStyle(VOLUME_SLIDER_X, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT,
             On, volumeSlider_[currentTracksCount_]);

    setStyle(DURATION_SLIDER_X - 20, DURATION_SLIDER_Y - 20 - 37 * currentTracksCount_,
             DURATION_SLIDER_WIDTH - 50, BUTTON_HEIGHT,
             On, trackNames_[currentTracksCount_]);

    playButtons_[currentTracksCount_]->setObjectName(Off);
    playButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");

    muteButtons_[currentTracksCount_]->setObjectName(Off);
    muteButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");

    repeatButtons_[currentTracksCount_]->setObjectName(Off);
    repeatButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");

    volumeSlider_[currentTracksCount_]->setValue(50);

    auto durationBegin = QInputDialog::getText(nullptr, tr(""),
                                           tr("Начало проигрывания(в секундах)"));
    auto durationBeginInt = durationBegin.toInt();
    durationSlider_[currentTracksCount_]->setValue(durationBeginInt * 1000);
    playTracks_[currentTracksCount_]->setDuration(durationBeginInt * 1000);

    connect(currentTracksNumbers_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(numberCurrentTrackClicked()));

    ++currentTracksCount_;
}

#include <fstream>
#include <iostream>

void CurrentTrackView::saveData() {
    std::ofstream outfile("/home/marcussss1/2022_2_MidnightSun/newPlayer.txt");
    for (size_t i = 0; i < playTracks_.size(); ++i) {
        if (playTracks_[i]) {
            outfile << paths_[i].toStdString() << "\n";
            outfile << std::to_string(durationsBegin_[i]) << "\n";
            outfile << std::to_string(durationsEnd_[i]) << "\n";
            outfile << std::to_string(int(playTracks_[i]->isRepeating())) << "\n";
            outfile << std::to_string(volumeSlider_[i]->value()) << "\n";
        }
    }
    outfile << "\n";
    outfile.close();
}

void CurrentTrackView::addTrack(QString path, int beginDuration, int endDuration, int isRepeating, int volume) {

    connect(playButtons_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(play()));

    connect(muteButtons_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(mute()));

    connect(repeatButtons_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(repeat()));

    connect(volumeSlider_[currentTracksCount_], SIGNAL(valueChanged(int)),
            this, SLOT(setVolume(int)));

    connect(durationSlider_[currentTracksCount_], SIGNAL(valueChanged(int)),
            this, SLOT(setDuration(int)));

    currentTracksNumbers_[currentTracksCount_]->setObjectName("On" + QString(currentTracksCount_));
    currentTracksNumbers_[currentTracksCount_]->setStyleSheet("QPushButton { border: solid; border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/otrezok.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/otrezokFocus.png); }");

    std::string on = "On" + std::to_string(currentTracksCount_ + 1);
    std::string off = "Off" + std::to_string(currentTracksCount_ + 1);

    const char* On = &on[0];
    const char* Off = &off[0];

    auto qtrack = new QTrack;
    qtrack->setCurrentTrack(path);
    auto track = new Track(qtrack);

    auto string = path.toStdString();
    std::reverse(string.begin(), string.end());
    
    string = string.substr(string.find('.') + 1);
    string = string.substr(0, string.find('/'));
    
    std::reverse(string.begin(), string.end());

    track->setData(path.toStdString(),
                    string.substr(0, string.find('-')),
                    string.substr(string.find('-') + 1));

    playTracks_[currentTracksCount_] = track;
    playTracks_[currentTracksCount_]->track_->mplayer()->setObjectName(On);

    connect(playTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(positionChanged(qint64)), this, SLOT(elapsedTime(qint64)));
    connect(playTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(durationChanged(qint64)), this, SLOT(remaningTime(qint64)));

    trackNames_[currentTracksCount_]->setText(QString::fromStdString(playTracks_[currentTracksCount_]->getData()));

    setStyle(CURRENT_TRACK_WIDGET_X - 200, CURRENT_TRACK_WIDGET_Y - 40 * currentTracksCount_,
             CURRENT_TRACK_WIDGET_WIDTH + 200, CURRENT_TRACK_WIDGET_HEIGHT + 40 * currentTracksCount_,
             CURRENT_TRACK_WIDGET_NAME, currentTrackWidget_);

    setStyle(5, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             On, currentTracksNumbers_[currentTracksCount_]);

    setStyle(MUTE_BUTTON_X - 90, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             Off, playButtons_[currentTracksCount_]);

    setStyle(MUTE_BUTTON_X + 10, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             Off, muteButtons_[currentTracksCount_]);

    setStyle(MUTE_BUTTON_X - 40, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             Off, repeatButtons_[currentTracksCount_]);

    setStyle(DURATION_SLIDER_X - 20, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             DURATION_SLIDER_WIDTH - 50, BUTTON_HEIGHT,
             On, durationSlider_[currentTracksCount_]);

    setStyle(VOLUME_SLIDER_X, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT,
             On, volumeSlider_[currentTracksCount_]);

    setStyle(DURATION_SLIDER_X - 20, DURATION_SLIDER_Y - 20 - 37 * currentTracksCount_,
             DURATION_SLIDER_WIDTH - 50, BUTTON_HEIGHT,
             On, trackNames_[currentTracksCount_]);

    playButtons_[currentTracksCount_]->setObjectName(Off);
    playButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");

    muteButtons_[currentTracksCount_]->setObjectName(Off);
    muteButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");

    // repeatButtons_[currentTracksCount_]->setObjectName(Off);
    // repeatButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");

    volumeSlider_[currentTracksCount_]->setValue(50);

    auto durationBegin = QInputDialog::getText(nullptr, tr(""),
                                           tr("Начало проигрывания(в секундах)"));
    auto durationBeginInt = durationBegin.toInt();
    durationSlider_[currentTracksCount_]->setValue(durationBeginInt * 1000);
    playTracks_[currentTracksCount_]->setDuration(durationBeginInt * 1000);

    connect(currentTracksNumbers_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(numberCurrentTrackClicked()));

// QString path, int beginDuration, int endDuration, int isRepeating, int volume

    durationsBegin_[currentTracksCount_] = beginDuration;
    durationsEnd_[currentTracksCount_] = endDuration;

    playTracks_[currentTracksCount_]->setVolume(volume);
    playTracks_[currentTracksCount_]->setDuration(beginDuration);

    if (isRepeating) {
        playTracks_[currentTracksCount_]->repeat();
        repeatButtons_[currentTracksCount_]->setObjectName(On);
        repeatButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    } else {
        repeatButtons_[currentTracksCount_]->setObjectName(Off);
        repeatButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    }

    // repeatButtons_[currentTracksCount_];

    ++currentTracksCount_;
}

void CurrentTrackView::deleteCurrentTrack(QString path, int index) {


    
    // qDebug() << "OK";
    // auto findTrack = std::find(currentTracks_.begin(), currentTracks_.end(), index);
    // if (findTrack == currentTracks_.end()) {
    //     return;
    // } else {
    //     currentTracks_.erase(std::find(currentTracks_.begin(), currentTracks_.end(), index));
    // }

    // currentTracks_[index] = 999;

    // qDebug() << index;

    // auto find = std::find(currentTracks_.begin(), currentTracks_.end(), index);
    // *find = 999;

    // currentTracks_[index] = 999;
    // qDebug() << index;
    playTracks_[index] = nullptr;
    // for (size_t i = 0; i < currentTracks_.size(); ++i) {
    //     if (currentTracks_[i] == index) {
    //         currentTracks_[i] = 999;
    //     }
    // }

    std::vector<QString> arr;
    // std::vector<int> arrNums(10);

    currentTracksCount_ = 0;

    // for (size_t i = 0; i < arr.size(); ++i) {
        // if (curre[i] != index) {
            // arr
        // }
    // }
    // int index = 0;
    for (size_t i = 0; i < trackNames_.size(); ++i) {
        if (trackNames_[i] && trackNames_[i]->text() != "" && trackNames_[i]->text() != "Deleted" && trackNames_[i]->text() != path) {
            arr.push_back(trackNames_[i]->text());
        }
        // arrNums[i] = currentTracks_[i];
        // qDebug() << arrNums[i];
        // currentTracks_[i] = 999;
    }

    for (size_t i = 0; i < 10; ++i) {
        setStyle(0, 0, 0, 0, "Deleted", currentTracksNumbers_[i]);
        setStyle(0, 0, 0, 0, "Deleted", playButtons_[i]);
        setStyle(0, 0, 0, 0, "Deleted", muteButtons_[i]);
        setStyle(0, 0, 0, 0, "Deleted", repeatButtons_[i]);
        setStyle(0, 0, 0, 0, "Deleted", durationSlider_[i]);
        setStyle(0, 0, 0, 0, "Deleted", volumeSlider_[i]);
        setStyle(0, 0, 0, 0, "Deleted", trackNames_[i]);
    }

    // qDebug() << currentTracks_.size();

    // auto copy = std::move(currentTracks_);
    // currentTracks_ = {};
    // qDebug() << "OK";

    for (size_t i = 0, j = 0; i < playTracks_.size(); ++i) {
        // qDebug() << currentTracks_[i];
        if (playTracks_[i] != nullptr) {
            // qDebug() << arrNums[i];
            currentTrackChanged(arr[j], i, false); // не совпадение индеков, в названии истина
            ++j;
        }
    }
}

// TODO

void CurrentTrackView::elapsedTime(qint64 position) {
    // int index = sender()->objectName().toStdString().back() - '0' - 1;
    // durationSlider_[index]->setValue(position);
    // [ *std::find(index - 1) ]...
    
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    durationSlider_[index]->setValue(position);
    // if (durationSlider_[index] == nullptr) {
    //     // durationSlider_[index]
    //     return;
    // }
    // if (position < durationsEnd_[index] && durationSlider_[index]) {
        // durationSlider_[index]->s(position);
    // } else if (playTracks_[index]) {
    //     // qDebug() << 55;
    //     playTracks_[index]->stop();
    //     durationSlider_[index]->setValue(0);
    // }
    // durationSlider_[index]->setValue(position);
    // qDebug() << position;
}

// TODO

void CurrentTrackView::remaningTime(qint64 position) {
    //  qDebug() << position;
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    durationSlider_[index]->setRange(0, position);
    durationsEnd_[index] = position;
    // qDebug() << position;
    // durationsEnd_[index] = position;
    // qDebug() << 1111;
    // qDebug() << position;
}

// void CurrentTrackView::currentTrackChanged(int currentTrackPosition) {
//     currentTrackPosition_ = currentTrackPosition;
// }

// void CurrentTrackView::deleteCurrentTrack(int currentTrackPosition) {
//     controller_->
// }

void CurrentTrackView::currentTrackStatus(int index) {
    // if (currentTracksNumbers_[index]->objectName()[1] == "f") {
    //     currentTracks_.push_back(index);
    //     QString a = "On";
    //     a.push_back(QString(index));
    //     currentTracksNumbers_[index]->setObjectName(a);
    //     currentTracksNumbers_[index]->setStyleSheet("QPushButton {background-color: red}");
    // } else {
        // controller_->stop(index);
        // currentTracks_.erase(std::find(currentTracks_.begin(), currentTracks_.end(), index));
    //     QString a = "Off";
    //     a.push_back(QString(index));
    //     currentTracksNumbers_[index]->setObjectName(a);
    //     currentTracksNumbers_[index]->setStyleSheet("QPushButton {background-color: #1f2936}");
    // }

    // int index = sender()->objectName().toStdString().back() - '0' - 1;
    // controller_->mute(index);


    // qDebug() << currentTracksNumbers_[index]->objectName();

    // if (currentTracksNumbers_[index]->objectName()[1] == "f") {
    //     currentTracks_.push_back(index);
    //     // playTracks_[currentTracksCount_] = index;
    //     std::string string = "On" + std::to_string(index + 1);
    //     QString a = string.c_str();
    //     currentTracksNumbers_[index]->setObjectName(a);
    //     currentTracksNumbers_[index]->setStyleSheet("QPushButton {background-color: red}");
    // } else {
    //     // controller_->stop(index);
    //     playTracks_[index]->stop();
    //     currentTracks_.erase(std::find(currentTracks_.begin(), currentTracks_.end(), index));
    //     playTracks_[index] = nullptr;
    //     // currentTracks_.erase(std::find(currentTracks_.begin(), currentTracks_.end(), index));
    //     std::string string = "Off" + std::to_string(index + 1);
    //     QString a = string.c_str();
    //     currentTracksNumbers_[index]->setObjectName(a);
    //     currentTracksNumbers_[index]->setStyleSheet("QPushButton {background-color: #1f2936}");
    // }
}



void CurrentTrackView::numberCurrentTrackClicked() {

    auto durationBegin = QInputDialog::getText(nullptr, tr(""),
                                         tr("Начало(в секундах)"));
    auto durationEnd = QInputDialog::getText(nullptr, tr(""),
                                         tr("Конец(в секундах)"));

    auto durationBeginInt = durationBegin.toInt();
    auto durationEndInt = durationEnd.toInt();

    auto index = sender()->objectName().toStdString().back() - '0' - 1;

    // durationSlider_[index]->setRange(0, durationEndInt);
    durationSlider_[index]->setValue(durationBeginInt * 1000);

    // playTracks_[index]->set(durationBegin);
    playTracks_[index]->setDuration(durationBeginInt * 1000);
    durationsBegin_[index] = durationBeginInt * 1000;
    durationsEnd_[index] = durationEndInt * 1000;


    // qDebug() << durationsBegin_[index];
    // auto intIndex = index.back() - '0' - 1;

    // auto index = index.back() - '0' - 1;
    // QInputDialog::getInt()

// int i = QInputDialog::getInt(nullptr, tr("Ввод целого числа"),
//                       tr("Количество процентов:"), 50, 0, 100);
// if (ok)
    // ui->myLabel->setText(tr("%1%").arg(i));





    // bool ok;
    // int i = QInputDialog::getInt(this, tr("QInputDialog::getInt()"),
    //                              tr("Percentage:"), 25, 0, 100, 1, &ok);
    // if (ok)
    //     integerLabel->setText(tr("%1%").arg(i));

	
//     QMessageBox msgBox;  //www.itmathrepetitor.ru
//     msgBox.setText("Введите отрезок проигрывания\n(в секундах)");
//     // msgBox.setInformativeText("Введите отрезок проигрывания(в секундах)");
//     // msgBox.setStandardButtons();
//     msgBox.setIcon(QMessageBox::Information);

//     QPushButton *edit = msgBox.addButton(tr("Начало"), QMessageBox::ActionRole);
//     // QLabel *cc = msgBox.addAction(tr("d"), QMessageBox::ActionRole);
//     // QMessageBox::
//     // edit->setGeometry(QRect(0, 0, 25, 25));



//     QPushButton *del = msgBox.addButton(tr("Конец"), QMessageBox::ActionRole);
    
//     msgBox.setStandardButtons(QMessageBox::Yes);
// msgBox.addButton(QMessageBox::No);
// msgBox.setDefaultButton(QMessageBox::No);
    
    // auto reply = QMessageBox::question(nullptr, "Test", "Quit?", QMessageBox::);
    // QPushButton *Output = msgBox.addButton(tr("Выдать"), QMessageBox::ActionRole);
    // QPushButton *Remont = msgBox.addButton(tr("Отремонтировать"), QMessageBox::ActionRole);
    // msgBox.addButton(QObject::tr("Отмена"), QMessageBox::ActionRole);
    // msgBox.setDefaultButton(Output);

    // QPushButton* a = new QPushButton(nullptr);
    // msgBox.addButton(a);
    // msgBox.addAction(new QAction(nullptr));
    // QString text1 = QInputDialog::getText(currentTrackWidget_, "Начало", "text");
    // QString text2 = QInputDialog::getText(currentTrackWidget_, "Конец", "text");
    // msgBox.setDefaultButton(QMessageBox::Ok);
    // msgBox.exec();
    // if (res != QMessageBox::Cancel) {
        // msgBox.close(); //нажата кнопка Ok
    // }
    //         doSomething();
    // else //отмена
    //         stopSomething(); //  отмена 
    // showMe
    // qDebug() << 555;
    // QSignalSpy spy(SIGNAL(clicked()));
    // spy.wait(15000);  //wait until signal fires or 5 second timeout expires

    // while(1) {}
    // std::string index = sender()->objectName().toStdString();
    // auto intIndex = index.back() - '0' - 1;
    // qDebug() << intIndex;
    // qDebug() << index.back() - '0';
    // currentTrackStatus(index.back() - '0' - 1);
}

void CurrentTrackView::playAll() {
    if (play_->objectName() == "play") {
        for (size_t i = 0; i < playTracks_.size(); ++i) {
            if (playTracks_[i] != nullptr) {
                emit playButtons_[i]->clicked();
            }
            if (playTracks_[i] != nullptr && !playTracks_[i]->isPlaying()) {
                emit playButtons_[i]->clicked();
            }
        }
        play_->setObjectName("pause");
        play_->setStyleSheet("QPushButton#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pause.png); } QPushButton:hover#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pauseFocus.png); }");
    } else {
        for (size_t i = 0; i < playTracks_.size(); ++i) {
            if (playTracks_[i] != nullptr) {
                emit playButtons_[i]->clicked();
            }
            if (playTracks_[i] != nullptr && playTracks_[i]->isPlaying()) {
                emit playButtons_[i]->clicked();
            }
        }
        play_->setObjectName("play");
        play_->setStyleSheet("QPushButton#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");
    }
}

void CurrentTrackView::play() {
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    // playTracks_[index]->play();
    // controller_->repeat(index);
    // qDebug() << sender()->objectName();
    if (playButtons_[index]->objectName()[1] == "f") {
        playTracks_[index]->play();
        std::string string = "On" + std::to_string(index + 1);
        QString a = string.c_str();
        playButtons_[index]->setObjectName(a);
        playButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pause.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pauseFocus.png); }");
    } else {
        playTracks_[index]->pause();
        std::string string = "Off" + std::to_string(index + 1);
        QString a = string.c_str();
        playButtons_[index]->setObjectName(a);
        playButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");
    }
}

//TODO REPEAT он ставит чисто флаг

void CurrentTrackView::repeat() {
    // int index = sender()->objectName().toStdString().back() - '0';
    // controller_->repeat(index);
    // if (muteButtons_[index]->objectName()[1] == "f") {
    //     QString a = "On";
    //     a.push_back(QString(index));
    //     muteButtons_[index]->setObjectName(a);
    //     muteButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    // } else {
    //     QString a = "Off";
    //     a.push_back(QString(index));
    //     currentTracksNumbers_[index]->setObjectName(a);
    //     currentTracksNumbers_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    // }
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    playTracks_[index]->repeat();
    // controller_->repeat(index);
    if (repeatButtons_[index]->objectName()[1] == "f") {
        std::string string = "On" + std::to_string(index + 1);
        QString a = string.c_str();
        repeatButtons_[index]->setObjectName(a);
        repeatButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    } else {
        std::string string = "Off" + std::to_string(index + 1);
        QString a = string.c_str();
        repeatButtons_[index]->setObjectName(a);
        repeatButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    }
}

void CurrentTrackView::mute() {
    // qDebug() << "OK";
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    // controller_->mute(index);
    // playTracks_[index]->mute();
    if (muteButtons_[index]->objectName()[1] == "f") {
        playTracks_[index]->mute();
        std::string string = "On" + std::to_string(index + 1);
        QString a = string.c_str();
        muteButtons_[index]->setObjectName(a);
        muteButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOn.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOnFocus.png); }");
    } else {
        playTracks_[index]->mute();
        std::string string = "Off" + std::to_string(index + 1);
        QString a = string.c_str();
        muteButtons_[index]->setObjectName(a);
        muteButtons_[index]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");
    }
}

// #include <QMediaPlaylist>>

void CurrentTrackView::setDuration(int position) {
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    // qDebug() << durationsEnd_[index];
    if (playTracks_[index]->isRepeating() && durationsEnd_[index] - position < 1000) {
        // qDebug() << durationsBegin_[index];
        if (durationsBegin_[index] - 1000 < 0) {
            playTracks_[index]->setDuration(0);
        } else {
            playTracks_[index]->setDuration(durationsBegin_[index] - 1000);
        }
        return;
    }

    if (position < durationsEnd_[index]) {
        playTracks_[index]->setDuration(position);
    }
    // } else if (playTracks_[index]->isRepeating() && durationsEnd_[index] - position < 2000) {
    //     playTracks_[index]->setDuration(0);
    // }
    // } else {
    //     playTracks_[index]->stop();
    // }
    // qDebug() << (posi;

    // if (position < durationsEnd_[index]) {
    //     playTracks_[index]->setDuration(position);
    // }
    // if (playTracks_[index]->isRepeating() && durationsEnd_[index] - position < 1000) {
    //     playTracks_[index]->setDuration(0);
    // }
    //     // if (playTracks_[index]->isRepeating() && durationsEnd_[index] - position < 1000) {
    //     //     playTracks_[index]->setDuration(0);
    //     // } else {
        
    //     // if (position == durationsEnd_[index]) {
    //     //     // playTracks_[index]->pause();
    //     //     qDebug() << "Ok";
    //     //     playTracks_[index + 1]->play();
    //     //     // uslee
    //     // }
    //     // else {
    //         playTracks_[index]->setDuration(position);
    //     // }
    // } else if (position == durationsEnd_[index] - position < 2000) {
    //     playTracks_[index]->setDuration(0);
    //     // playTracks_[index]->play();
    //     // playTracks_[index]->pause();
    //     // playTracks_[index]->play();
    // }

    // if (position < durationsEnd_[index]) {
    //     if (position > 10000) {
    //         playTracks_[index]->setDuration(0);
    //     } else
    //     playTracks_[index]->setDuration(position);
    // } else if (position == durationsEnd_[index] && playTracks_[index]->isRepeating()) {
    //     // playTracks_[index]->setDuration(0);
    //     // qDebug() << playTracks_[index]->isRepeating();
    //     // playTracks_[index]->stop();
    //     // playTracks_[index]->play();
    //     // QMediaPlaylist *playlist = new QMediaPlaylist();
    //     // playlist->setPlaybackMode(QMediaPlaylist::Loop);

    //     // QMediaPlayer *music = new QMediaPlayer();
    //     // playTracks_[index]->track_->mplayer()->setPlaylist(playlist);
    //     // playTracks_[index]->play();
    // } else {
    //     playTracks_[index]->stop();
    // }
    // } else {
    //     playTracks_[index]->stop();
    // }
    // controller_->setDuration(index, position);
}

void CurrentTrackView::setVolume(int position) {
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    playTracks_[index]->setVolume(position);
    volumeSlider_[index]->setValue(position);
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
