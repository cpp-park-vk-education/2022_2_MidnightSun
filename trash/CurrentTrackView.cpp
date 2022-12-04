#include "CurrentTrackView.hpp"

//////////////////////////////////////// Current Track Buttons ////////////////////////////////////////

Sender::Sender(Mediator* mediator)
    : mediator_(mediator) {}

DefaultButton::DefaultButton(Mediator* mediator) 
    : Sender(mediator) {}

void DefaultButton::click() {}

HoverButton::HoverButton(Mediator* mediator) 
    : Sender(mediator) {}

void HoverButton::click() {}

void HoverButton::editStatus() {}

bool HoverButton::isClicked() {
    return isClicked_;
}

Slider::Slider(Mediator* mediator) 
    : Sender(mediator) {}

void Slider::editStatus() {}

// DefaultButton::DefaultButton(Mediator* mediator) 
//     : Sender(mediator) {}

// void DefaultButton::click() {}

// DefaultButton::DefaultButton(Mediator* mediator) 
//     : Sender(mediator) {}

// struct DefaultButton : public Sender {
//     explicit DefaultButton(Mediator* mediator);
//     void click();
// };

// struct HoverButton : public Sender {
//     explicit HoverButton(Mediator* mediator);
//     void click();
//     bool isClicked();
//  private:
//     bool isClicked_ = false;
// };

// struct Slider : public Sender {
//     explicit Slider(Mediator* mediator);
//     void editStatus();
//  private:
//     size_t position_ = 0;
// };

// Button::Button(Mediator* mediator)
//     : Sender(mediator) {}

// void Button::click() {
//     mediator_->notify(this);
// }

// Status Button::isClicked() {
//     return isClicked_;
// }

// ShuffleButton::ShuffleButton(Mediator* mediator)
//     : Button(mediator) {}

// void ShuffleButton::editStatus() {}

// PreviousTrackButton::PreviousTrackButton(Mediator* mediator)
//     : Button(mediator) {}

// void PreviousTrackButton::editStatus() {}

// PlayButton::PlayButton(Mediator* mediator)
//     : Button(mediator) {}

// void PlayButton::editStatus() {}

// NextTrackButton::NextTrackButton(Mediator* mediator)
//     : Button(mediator) {}

// void NextTrackButton::editStatus() {}

// RepeatButton::RepeatButton(Mediator* mediator)
//     : Button(mediator) {}

// void RepeatButton::editStatus() {}

// MuteButton::MuteButton(Mediator* mediator)
//     : Button(mediator) {}

// void MuteButton::editStatus() {}

// DurationSlider::DurationSlider(Mediator* mediator)
//     : Slider(mediator) {}

// void DurationSlider::editStatus() {}

// VolumeSlider::VolumeSlider(Mediator* mediator)
//     : Slider(mediator) {}

// void VolumeSlider::editStatus() {}

//////////////////////////////////////// Current Track UIModel ////////////////////////////////////////

CurrentTrackUIModel::CurrentTrackUIModel(Mediator* mediator)
    : Sender(mediator) {}

Status CurrentTrackUIModel::shuffle() {
    mediator_->notify(this, shuffleButton);
}

Status CurrentTrackUIModel::previousTrack() {
    mediator_->notify(this, previousTrackButton);
}

Status CurrentTrackUIModel::play() {
    mediator_->notify(this, playButton);
}

Status CurrentTrackUIModel::nextTrack() {
    mediator_->notify(this, nextTrackButton);
}

Status CurrentTrackUIModel::repeat() {
    mediator_->notify(this, repeatButton);
}

Status CurrentTrackUIModel::mute() {
    mediator_->notify(this, muteButton);
}

Status CurrentTrackUIModel::moveDuration() {
    mediator_->notify(this, durationSlider);
}

Status CurrentTrackUIModel::moveVolume() {
    mediator_->notify(this, volumeSlider);
}

//////////////////////////////////////// Current Track Controller ////////////////////////////////////////

CurrentTrackController::CurrentTrackController(Mediator* mediator)
    : Sender(mediator) {}

Status CurrentTrackController::shuffleClicked() {
    mediator_->notify(this, shuffleButton);
}

Status CurrentTrackController::previousTrackClicked() {
    mediator_->notify(this, previousTrackButton);
}

Status CurrentTrackController::playClicked() {
    mediator_->notify(this, playButton);
}

Status CurrentTrackController::nextTrackClicked() {
    mediator_->notify(this, nextTrackButton);
}

Status CurrentTrackController::repeatClicked() {
    mediator_->notify(this, repeatButton);
}

Status CurrentTrackController::muteClicked() {
    mediator_->notify(this, muteButton);
}

Status CurrentTrackController::durationSliderMoved() {
    mediator_->notify(this, durationSlider);
}

Status CurrentTrackController::volumeSliderMoved() {
    mediator_->notify(this, volumeSlider);
}

//////////////////////////////////////// Current Track View ////////////////////////////////////////

void CurrentTrackView::notify(Sender* sender, std::string button) {

    // Контроллер
    if (sender == shuffle_ && button == "") {
        controller_->shuffleClicked();
    } else if (sender == previousTrack_ && button == "") {
        controller_->previousTrackClicked();
    } else if (sender == play_ && button == "") {
        controller_->playClicked();
    } else if (sender == nextTrack_ && button == "") {
        controller_->nextTrackClicked();
    } else if (sender == repeat_ && button == "") {
        controller_->repeatClicked();
    } else if (sender == mute_ && button == "") {
        controller_->muteClicked();
    } else if (sender == durationSlider_ && button == "") {
        controller_->durationSliderMoved();
    } else if (sender == volumeSlider_ && button == "") {
        controller_->volumeSliderMoved();
    }

    // UI Модель
    else if (sender == controller_ && button == shuffleButton) {
        // shuffle_->editStatus();
        model_->shuffle();
    } else if (sender == controller_ && button == previousTrackButton) {
        // previousTrack_->editStatus();
        model_->previousTrack();
    } else if (sender == controller_ && button == playButton) {
        // play_->editStatus();
        model_->play();
    } else if (sender == controller_ && button == nextTrackButton) {
        // nextTrack_->editStatus();
        model_->nextTrack();
    } else if (sender == controller_ && button == repeatButton) {
        // repeat_->editStatus();
        model_->repeat();
    } else if (sender == controller_ && button == muteButton) {
        // mute_->editStatus();
        model_->mute();
    } else if (sender == controller_ && button == durationSlider) {
        // durationSlider_->editStatus();
        model_->moveDuration();
    } else if (sender == controller_ && button == volumeSlider) {
        // volumeSlider_->editStatus();
        model_->moveVolume();
    }

    // Если UI Модель успешно отработала, изменяем статус кнопки
    else if (sender == model_ && button == shuffleButton) {

    } else if (sender == model_ && button == previousTrackButton) {

    } else if (sender == model_ && button == playButton) {

    } else if (sender == model_ && button == nextTrackButton) {

    } else if (sender == model_ && button == repeatButton) {

    } else if (sender == model_ && button == muteButton) {

    } else if (sender == model_ && button == durationSlider) {

    } else if (sender == model_ && button == volumeSlider) {
        
    }
}

void CurrentTrackView::initializeView(CurrentTrackView* view) {
    shuffle_ = new HoverButton(view);
    previousTrack_ = new DefaultButton(view); 
    play_ = new DefaultButton(view);
    nextTrack_ = new DefaultButton(view);
    repeat_ = new HoverButton(view);
    mute_ = new HoverButton(view);
    durationSlider_ = new Slider(view);
    volumeSlider_ = new Slider(view);
    model_ = new CurrentTrackUIModel(view);
    controller_ = new CurrentTrackController(view);
}
