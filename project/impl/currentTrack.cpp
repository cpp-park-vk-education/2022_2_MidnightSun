#include "currentTrack.hpp"

#define CURRENT_TRACK_X 150
#define CURRENT_TRACK_Y 500
#define CURRENT_TRACK_WINDOW_WIDTH 700 
#define CURRENT_TRACK_HEIGHT 150

#define SHUFFLE_X 275
#define SHUFFLE_Y 535

#define SHUFFLE_WIDTH 35
#define SHUFFLE_HEIGHT 35



IButton::IButton(QWidget* parent) 
    : button_(new QPushButton(parent)) {
    // connect(button_, SIGNAL(clicked()), this, SLOT(&CurrentTrackUIModel::play()));
}

IButton::~IButton() {}

CurrentTrackWidget::CurrentTrackWidget(QWidget* parent) 
    : currentTrackWindow_(new QWidget(parent)), 
      shufle_(parent), 
      previousTrack_(parent),
      play_(parent),
      nextTrack_(parent),
      repeat_(parent),
      mute_(parent),
      volumeSlider_(parent) {
    currentTrackWindow_->setObjectName("currentTrack");
    currentTrackWindow_->setGeometry(QRect(CURRENT_TRACK_X,
                                     CURRENT_TRACK_Y,
                                     CURRENT_TRACK_WINDOW_WIDTH,
                                     CURRENT_TRACK_HEIGHT));
    // connect(mute_.button_, SIGNAL(clicked()), this, SLOT(model_.play));
}

CurrentTrackWidget::~CurrentTrackWidget() {}

ShuffleButton::ShuffleButton(QWidget* parent)
    : IButton(parent) {
    button_->setGeometry(QRect(SHUFFLE_X + 50, SHUFFLE_Y, SHUFFLE_WIDTH, SHUFFLE_HEIGHT));

    QPixmap f("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/shuffle.png");
    QIcon e(f);
    button_->setIcon(e);
    button_->setIconSize(QSize(35, 35));
}

#define PREVIOUS_TRACK_X 330
#define PREVIOUS_TRACK_Y 535

PreviousTrackButton::PreviousTrackButton(QWidget* parent)
    : IButton(parent) {
    button_->setGeometry(QRect(PREVIOUS_TRACK_X + 40, PREVIOUS_TRACK_Y, SHUFFLE_WIDTH, SHUFFLE_HEIGHT));

    QPixmap f("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/previousTrack.png");
    QIcon e(f);
    button_->setIcon(e);
    button_->setIconSize(QSize(38, 38));
}

#define PLAY_X 375
#define PLAY_Y 535

PlayButton::PlayButton(QWidget* parent)
    : IButton(parent) {
    button_->setGeometry(QRect(PLAY_X + 40, PLAY_Y - 10, 50, 50));
    QPixmap f("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/play.png");
    QIcon e(f);
    button_->setIcon(e);
    button_->setIconSize(QSize(50, 50));
}

#define NEXT_TRACK_X 440
#define NEXT_TRACK_Y 535

NextTrackButton::NextTrackButton(QWidget* parent)
    : IButton(parent) {
    button_->setGeometry(QRect(NEXT_TRACK_X + 40, NEXT_TRACK_Y, SHUFFLE_WIDTH, SHUFFLE_HEIGHT));

    QPixmap f("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/nextTrack.png");
    QIcon e(f);
    button_->setIcon(e); 
    button_->setIconSize(QSize(35, 35));
}

#define REPEAT_X 485
#define REPEAT_Y 535

RepeatButton::RepeatButton(QWidget* parent)
    : IButton(parent) {
    button_->setGeometry(QRect(REPEAT_X + 40, REPEAT_Y, SHUFFLE_WIDTH, SHUFFLE_HEIGHT));
    QPixmap f("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/repeat.png");
    QIcon e(f);
    button_->setIcon(e);
    button_->setIconSize(QSize(35, 35));
}

CurrentTrackView::CurrentTrackView(QWidget* parent) 
                    : baseFunctionalButtons_(parent) {
    // connect(actionPlay_Selected, SIGNAL(triggered()), ui->btnPlay, SLOT(click()));
    connect(baseFunctionalButtons_.play_.button_, SIGNAL(clicked()), &controller_, SLOT(play()));
}

CurrentTrackView::~CurrentTrackView() {}

MuteButton::MuteButton(QWidget* parent) 
    : IButton(parent) {
    button_->setGeometry(QRect(REPEAT_X + 120, REPEAT_Y, SHUFFLE_WIDTH, SHUFFLE_HEIGHT));
    QPixmap f("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/muteOff.png");
    QIcon e(f);
    button_->setIcon(e);
    button_->setIconSize(QSize(35, 35));
}

VolumeSlider::VolumeSlider(QWidget* parent) 
    : volumeSlider_(new QSlider(Qt::Horizontal, parent)) {
    volumeSlider_->setGeometry(QRect(REPEAT_X + 170, REPEAT_Y, 125, SHUFFLE_HEIGHT));
}

VolumeSlider::~VolumeSlider() {}
