#pragma once

enum Function {
// Значения, указывающие какие функции нужно стриггерить у Playlist
    Shuffle,
    PreviousTrack,
    NextTrack,
    Repeat,
    DurationEnd,
// Значения, указывающие какие функции нужно стриггерить у Current Track
    ChooseTrack
};

enum Status {
    Success,
    Failure
};

class Sender;

struct Mediator {
    virtual void notify(Sender* sender, Function function) = 0;
};

class Sender {
 public:
    explicit Sender(Mediator *mediator);
 protected:
    Mediator* mediator_;
};

class CurrentTrackUIModel : public Sender {
 public:
    explicit CurrentTrackUIModel(Mediator* Mediator);

// функции, которые триггерятся контроллером
    virtual Status shuffle();
    virtual Status previousTrack();
    virtual Status play();
    virtual Status nextTrack();
    virtual Status repeat();
    virtual Status mute();
    virtual Status moveDuration();
    virtual Status moveVolume();

// функции, которые триггерятся Playlist моделью
    virtual Status chooseTrack();

// функции, которые триггерятся Model
    virtual Status choosePreviousTrack();
    virtual Status chooseNextTrack();
};

class PlaylistUIModel : public Sender {
 public:
    explicit PlaylistUIModel(Mediator* mediator);

// функции, которые триггерятся контроллером
    virtual Status addTrack();
    virtual Status deleteTrack();
    virtual Status chooseTrack();
    virtual Status addQueue();
    virtual Status deleteQueue();

// функции, которые триггерятся Current Track моделью
    virtual Status setShuffle();
    virtual Status setRepeat();
    virtual Status choosePreviousTrack();
    virtual Status chooseNextTrack();
};


class TrackPlaylistModel : public Mediator {
 public:
    virtual void setCurrentTrack(CurrentTrackUIModel* model);
    virtual void setPlaylist(PlaylistUIModel* model);

    virtual void notify(Sender* sender, Function function) override;
 protected:
    CurrentTrackUIModel* currentTrack_;
    PlaylistUIModel* playlist_;
};

// class CurrentTrackController {
//  public:
//     explicit CurrentTrackController(Mediator* mediator);
//     Status shuffle();
//     Status previousTrack();
//     Status play();
//     Status nextTrack();
//     Status repeat();
//     Status mute();
//     Status moveDuration();
//     Status moveVolume();
//  private:
//     CurrentTrackUIModel* model_;
// };

// class PlaylistController {
//  public:
//     Status addTrack();
//     Status deleteTrack();
//     Status chooseTrack();
//     Status addQueue();
//     Status deelteQueue();
//  private:
//     PlaylistUIModel* model_;
// };
