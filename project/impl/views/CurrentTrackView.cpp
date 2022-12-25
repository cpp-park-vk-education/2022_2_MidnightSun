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
const char* REPEAT_NAME = "repeat";
const char* MUTE_NAME = "muteOff";
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
      muteButtons_(10, nullptr),
      repeatButtons_(10, nullptr),
      durationSlider_(10, nullptr),
      trackNames_(10, nullptr),
    //   durationSlider_(std::vector<QSlider*> {new QSlider(Qt::Horizontal, parent)}),
      volumeSlider_(10, nullptr),
      playTracks_(10, nullptr),
      durations_(10) {
    //   a(std::vector<int>(10)) { 

    for (size_t i = 0; i < 10; ++i) {
        currentTracksNumbers_[i] = new QPushButton(parent);
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

    play_->setObjectName("Play");
    repeat_->setObjectName("Off");
    mute_->setObjectName("Off");

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

    setStyle(MUTE_BUTTON_X - 100, PLAY_BUTTON_Y,
             PLAY_BUTTON_WIDTH, PLAY_BUTTON_HEIGHT,
             PLAY_NAME, play_);

    // setStyle(NEXT_TRACK_BUTTON_X - 20, BUTTON_Y,
    //          BUTTON_WIDTH, BUTTON_HEIGHT,
    //          NEXT_TRACK_NAME, nextTrack_);

    setStyle(MUTE_BUTTON_X - 40, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             REPEAT_NAME, repeat_); 

    setStyle(MUTE_BUTTON_X + 10, BUTTON_Y,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             MUTE_NAME, mute_);

    setStyle(VOLUME_SLIDER_X, BUTTON_Y,
             VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT,
             MUTE_NAME, volumeSliderAll_);

    // setStyle(CURRENT_TRACK_TITLE, DURATION_SLIDER_Y - 35,
    //          BUTTON_WIDTH + 120, BUTTON_HEIGHT,
    //          MUTE_NAME, currentTrackTitle_);

    // setStyle(MUTE_BUTTON_X, BUTTON_Y,
    //          BUTTON_WIDTH, BUTTON_HEIGHT,
    //          MUTE_NAME, mute_);

    currentTrackTitle_->setText("Текущий трек:");
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
        for (auto& it : playTracks_) {
            if (it != nullptr) {
                it->repeat();
            }
        }
        std::string string = "On";
        QString a = string.c_str();
        repeat_->setObjectName(a);
        repeat_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");
    } else {
        for (auto& it : playTracks_) {
            if (it != nullptr) {
                it->repeat();
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
        for (auto& it : playTracks_) {
            if (it != nullptr) {
                it->mute();
            }
        }
        std::string string = "On";
        QString a = string.c_str();
        mute_->setObjectName(a);
        mute_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOn.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOnFocus.png); }");
    } else {
        for (auto& it : playTracks_) {
            if (it != nullptr) {
                it->mute();
            }
        }
        std::string string = "Off";
        QString a = string.c_str();
        mute_->setObjectName(a);
        mute_->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");
    }
}

void CurrentTrackView::setVolumeAll(int) {

}

#include "QTrack.hpp"

#include <Track.hpp>

void CurrentTrackView::currentTrackChanged(QString path, int index, bool flag) {

    // qDebug() << "Ok";

    // connect(currentTracksNumbers_[currentTracksCount_], SIGNAL(clicked()),
    //         this, SLOT(numberCurrentTrackClicked()));

    connect(muteButtons_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(mute()));

    connect(repeatButtons_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(repeat()));

    connect(volumeSlider_[currentTracksCount_], SIGNAL(valueChanged(int)),
            this, SLOT(setVolume(int)));

    connect(durationSlider_[currentTracksCount_], SIGNAL(valueChanged(int)),
            this, SLOT(setDuration(int)));

// qDebug() << model_->currentTracks_[0]->track_->duration();
    currentTracksNumbers_[currentTracksCount_]->setObjectName("On" + QString(currentTracksCount_));
    currentTracksNumbers_[currentTracksCount_]->setStyleSheet("QPushButton {background-color: red}");

    // muteButtons_[currentTracksCount_]->setObjectName("Off" + QString(currentTracksCount_));
    // muteButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");

    // repeatButtons_[currentTracksCount_]->setObjectName("Off" + QString(currentTracksCount_));
    // repeatButtons_[currentTracksCount_]->setObjectName("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");

    currentTracksNumbers_[currentTracksCount_]->setText(QString::fromStdString(std::to_string(currentTracksCount_ + 1)));

    // volumeSlider_[currentTracksCount_]->setText(QString::fromStdString(std::to_string(currentTracksCount_)));
    // currentTracksNumbers_[currentTracksCount_]->setText(QString::fromStdString(std::to_string(currentTracksCount_ + 1)));
    

    std::string on = "On" + std::to_string(currentTracksCount_ + 1);
    std::string off = "Off" + std::to_string(currentTracksCount_ + 1);

    const char* On = &on[0];
    const char* Off = &off[0];

    if (flag) {
        auto qtrack = new QTrack;
        qtrack->setCurrentTrack(path);
        auto track = new Track(qtrack);
        track->setData(path.toStdString(),
                        path.toStdString().substr(0, path.toStdString().find('-')),
                        path.toStdString().substr(path.toStdString().find('-') + 1));
        playTracks_[currentTracksCount_] = track;
        playTracks_[currentTracksCount_]->track_->mplayer()->setObjectName(On);


        connect(playTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(positionChanged(qint64)), this, SLOT(elapsedTime(qint64)));
        connect(playTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(durationChanged(qint64)), this, SLOT(remaningTime(qint64)));
    }
    
    // qDebug() << "OK";

    trackNames_[currentTracksCount_]->setText(path);


    setStyle(CURRENT_TRACK_WIDGET_X - 200, CURRENT_TRACK_WIDGET_Y - 40 * currentTracksCount_,
             CURRENT_TRACK_WIDGET_WIDTH + 200, CURRENT_TRACK_WIDGET_HEIGHT + 40 * currentTracksCount_,
             CURRENT_TRACK_WIDGET_NAME, currentTrackWidget_);

    setStyle(5, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH - 6, BUTTON_HEIGHT - 6,
             On, currentTracksNumbers_[currentTracksCount_]);

    setStyle(MUTE_BUTTON_X + 10, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             Off, muteButtons_[currentTracksCount_]);

    setStyle(MUTE_BUTTON_X - 40, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             BUTTON_WIDTH, BUTTON_HEIGHT,
             Off, repeatButtons_[currentTracksCount_]);

    setStyle(DURATION_SLIDER_X - 20, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             DURATION_SLIDER_WIDTH, BUTTON_HEIGHT,
             On, durationSlider_[currentTracksCount_]);

    setStyle(VOLUME_SLIDER_X, DURATION_SLIDER_Y - 40 * currentTracksCount_,
             VOLUME_SLIDER_WIDTH, BUTTON_HEIGHT,
             On, volumeSlider_[currentTracksCount_]);

    setStyle(DURATION_SLIDER_X - 20, DURATION_SLIDER_Y - 20 - 37 * currentTracksCount_,
             DURATION_SLIDER_WIDTH, BUTTON_HEIGHT,
             On, trackNames_[currentTracksCount_]);

    // setStyle(CURRENT_TRACK_TITLE, DURATION_SLIDER_Y - 35 - 20 * currentTracksCount_,
    //          BUTTON_WIDTH + 120, BUTTON_HEIGHT,
    //          MUTE_NAME, currentTrackTitle_);

    // qDebug() << "Ok";

    // // currentTracksNumbers_[currentTracksCount_]->setObjectName(On);
    // currentTracksNumbers_[currentTracksCount_]->setStyleSheet("QPushButton {background-color: red}");

    //  qDebug() << "OK";

    muteButtons_[currentTracksCount_]->setObjectName(Off);
    muteButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOffFocus.png); }");

    repeatButtons_[currentTracksCount_]->setObjectName(Off);
    repeatButtons_[currentTracksCount_]->setStyleSheet("QPushButton { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png); } QPushButton:hover { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeatFocus.png); }");

    // model_->currentTracks_[currentTracksCount_]->track_->mplayer()->setObjectName(On);
    // playTracks_[currentTracksCount_]->track_->mplayer()->setObjectName(On);

    // //  qDebug() << "OK";
    // //     qDebug() << "pizda";

    // // connect(model_->currentTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(positionChanged(qint64)), this, SLOT(elapsedTime(qint64)));
    // // connect(model_->currentTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(durationChanged(qint64)), this, SLOT(remaningTime(qint64)));

    // connect(playTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(positionChanged(qint64)), this, SLOT(elapsedTime(qint64)));
    // connect(playTracks_[currentTracksCount_]->track_->mplayer(), SIGNAL(durationChanged(qint64)), this, SLOT(remaningTime(qint64)));

    connect(currentTracksNumbers_[currentTracksCount_], SIGNAL(clicked()),
            this, SLOT(numberCurrentTrackClicked()));

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
    // qDebug() << position;
}

// TODO

void CurrentTrackView::remaningTime(qint64 position) {
    //  qDebug() << position;
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    durationSlider_[index]->setRange(0, position);
    durations_[index] = position;
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

#include <QMessageBox>
#include <QInputDialog>

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
    durations_[index] = durationEndInt * 1000;


    // qDebug() << index;
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
        for (auto it : playTracks_) {
            // qDebug() << it;
            if (it != nullptr) {
                // qDebug() << it;
                // controller_->play(it);
                // it->setDuration(30000);
                // it->setDuration(100000);
                it->play();
                // it->setDuration(30000);
                // it->setDuration(100000);
            //    qDebug() <<  it->track_->mplayer()->duration();
                // it->setDuration(30000);
            }
        }
        play_->setObjectName("pause");
        play_->setStyleSheet("QPushButton#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pause.png); } QPushButton:hover#pause { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/pauseFocus.png); }");
    } else {
        for (auto it : playTracks_) {
            // qDebug() << it;
            if (it != nullptr) {
                // qDebug() << it;
                // controller_->play(it);
                it->pause();
            }
        }
        play_->setObjectName("play");
        play_->setStyleSheet("QPushButton#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png); } QPushButton:hover#play { border-image: url(/home/marcussss1/2022_2_MidnightSun/project/impl/icons/playFocus.png); }");
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

void CurrentTrackView::setDuration(int position) {
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    if (position < durations_[index]) {
        playTracks_[index]->setDuration(position);
    } else {
        playTracks_[index]->stop();
    }
    // } else {
    //     playTracks_[index]->stop();
    // }
    // controller_->setDuration(index, position);
}

void CurrentTrackView::setVolume(int position) {
    int index = sender()->objectName().toStdString().back() - '0' - 1;
    playTracks_[index]->setVolume(position);
    // playTracks_[index]->repeat();
    // controller_->setVolume(index, position);
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
