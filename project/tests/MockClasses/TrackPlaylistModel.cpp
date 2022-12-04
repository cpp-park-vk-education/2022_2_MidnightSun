#include "TrackPlaylistModel.hpp"

Sender::Sender(Mediator* mediator)
    : mediator_(mediator) {}



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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PlaylistUIModel::PlaylistUIModel(Mediator* mediator)
    : Sender(mediator) {}

// функции, которые триггерятся контроллером

Status PlaylistUIModel::addTrack() {
    return Success;
}

Status PlaylistUIModel::deleteTrack() {
    return Success;
}

Status PlaylistUIModel::chooseTrack() {
    mediator_->notify(this, ChooseTrack);
    return Success;
}

Status PlaylistUIModel::addQueue() {
    return Success;
}

Status PlaylistUIModel::deleteQueue() {
    return Success;
}

// функции, которые триггерятся Current Track моделью

Status PlaylistUIModel::setShuffle() {
    return Success;
}

Status PlaylistUIModel::setRepeat() {
    return Success;
}

Status PlaylistUIModel::choosePreviousTrack() {
    return Success;
}

Status PlaylistUIModel::chooseNextTrack() {
    return Success;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TrackPlaylistModel::setCurrentTrack(CurrentTrackUIModel* model) {
    currentTrack_ = model;
}

void TrackPlaylistModel::setPlaylist(PlaylistUIModel* model) {
    playlist_ = model;
}

void TrackPlaylistModel::notify(Sender* sender, Function function) {

    if (sender == currentTrack_ && function == Shuffle) {
        playlist_->setShuffle();
    } else if (sender == currentTrack_ && function == PreviousTrack) {
        playlist_->choosePreviousTrack();
        currentTrack_->choosePreviousTrack();
    } else if (sender == currentTrack_ && function == NextTrack) {
        playlist_->chooseNextTrack();
        currentTrack_->chooseNextTrack();
    } else if (sender == currentTrack_ && function == Repeat) {
        playlist_->setRepeat();
    } else if (sender == currentTrack_ && function == DurationEnd) {
        playlist_->chooseNextTrack(); 
        currentTrack_->chooseNextTrack();
    }

    else if (sender == playlist_ && function == ChooseTrack) {
        currentTrack_->chooseTrack();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// CurrentTrackController::CurrentTrackController(Mediator* mediator)
//     model_(new CurrentTrackUIModel(mediator)) {}

// Status CurrentTrackController::shuffle() {
//     model_->shuffle();
//     return Success;
// }

// Status CurrentTrackController::previousTrack() {
//     model_->previousTrack();
//     return Success;
// }

// Status CurrentTrackController::play() {
//     model_->play();
//     return Success;
// }

// Status CurrentTrackController::nextTrack() {
//     model_->nextTrack();
//     return Success;
// }

// Status CurrentTrackController::repeat() {
//     model_->repeat();
//     return Success;
// }

// Status CurrentTrackController::mute() {
//     model_->mute();
//     return Success;
// }

// Status CurrentTrackController::moveDuration() {
//     model_->moveDuration();
//     return Success;
// }

// Status CurrentTrackController::moveVolume() {
//     model_->moveVolume();
//     return Success;
// }



// Status PlaylistController::addTrack() {
//     model_->addTrack();
//     return Success;
// }

// Status PlaylistController::deleteTrack() {
//     model_->deleteTrack();
//     return Success;
// }

// Status PlaylistController::chooseTrack() {
//     model_->chooseTrack();
//     return Success;
// }

// Status PlaylistController::addQueue() {
//     model_->addQueue();
//     return Success;
// }

// Status PlaylistController::deelteQueue() {
//     model_->addQueue();
//     return Success;
// }
