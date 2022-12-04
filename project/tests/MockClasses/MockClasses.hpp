#pragma once

#include "TrackPlaylistModel.hpp"
#include <gmock/gmock.h>

class MockCurrentTrack : public CurrentTrackUIModel {
 public:
    explicit MockCurrentTrack(Mediator* mediator);

    MOCK_METHOD0(doShuffle, Status());
    MOCK_METHOD0(doPreviousTrack, Status());
    MOCK_METHOD0(doPlay, Status());
    MOCK_METHOD0(doNextTrack, Status());
    MOCK_METHOD0(doRepeat, Status());
    MOCK_METHOD0(doMute, Status());
    MOCK_METHOD0(doMoveDuration, Status());
    MOCK_METHOD0(doMoveVolume, Status());

    MOCK_METHOD0(doChooseTrack, Status());
    MOCK_METHOD0(doChoosePreviousTrack, Status());
    MOCK_METHOD0(doChooseNextTrack, Status());

    Status shuffle() override;
    Status previousTrack() override;
    Status play() override;
    Status nextTrack() override;
    Status repeat() override;
    Status mute() override;
    Status moveDuration() override;
    Status moveVolume() override;

    Status chooseTrack() override;

    Status choosePreviousTrack() override;
    Status chooseNextTrack() override;
};

class MockPlaylist : public PlaylistUIModel {
 public:
    explicit MockPlaylist(Mediator* mediator);
    MOCK_METHOD0(doAddTrack, Status());
    MOCK_METHOD0(doDeleteTrack, Status());
    MOCK_METHOD0(doChooseTrack, Status());
    MOCK_METHOD0(doAddQueue, Status());
    MOCK_METHOD0(doDeleteQueue, Status());

    MOCK_METHOD0(doSetShuffle, Status());
    MOCK_METHOD0(doSetRepeat, Status());
    MOCK_METHOD0(doChoosePreviousTrack, Status());
    MOCK_METHOD0(doChooseNextTrack, Status());

    Status addTrack() override;
    Status deleteTrack() override;
    Status chooseTrack() override;
    Status addQueue() override;
    Status deleteQueue() override;

    Status setShuffle() override;
    Status setRepeat() override;
    Status choosePreviousTrack() override;
    Status chooseNextTrack() override;
};

class MockModel : public TrackPlaylistModel {
  public:
    MOCK_METHOD2(doNotify, void(Sender*, Function));
    void notify(Sender* sender, Function function) override;

    void setCurrentTrack(MockCurrentTrack* model);
    void setPlaylist(MockPlaylist* model);
};