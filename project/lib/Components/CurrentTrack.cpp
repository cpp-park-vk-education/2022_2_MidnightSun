#include "CurrentTrack.hpp"

CurrentTrackUIModel::CurrentTrackUIModel(Mediator* mediator)
    : Sender(mediator) {}

// функции, которые триггерятся контроллером
Status CurrentTrackUIModel::shuffle() {
    mediator_->notify(this, Shuffle);
    return Success;
}

Status CurrentTrackUIModel::previousTrack() {
    mediator_->notify(this, PreviousTrack);
    return Success;
}

Status CurrentTrackUIModel::play() {
    return Success;
}

Status CurrentTrackUIModel::nextTrack() {
    mediator_->notify(this, NextTrack);
    return Success;
}

Status CurrentTrackUIModel::repeat() {
    mediator_->notify(this, Repeat);
    return Success;
}

Status CurrentTrackUIModel::mute() {
    return Success;
}

Status CurrentTrackUIModel::moveDuration() {
    mediator_->notify(this, DurationEnd); // узнаем, промотали на конец трека или нет
                                          // если полоску промотали на конец трека,
                                          // включаем следующий трек
    return Success;
}

Status CurrentTrackUIModel::moveVolume() {
    return Success;
}

// функции, которые триггерятся Playlist моделью

Status CurrentTrackUIModel::chooseTrack() {
    return Success;
}

Status CurrentTrackUIModel::choosePreviousTrack() {
    return Success;
}

Status CurrentTrackUIModel::chooseNextTrack() {
    return Success;
}