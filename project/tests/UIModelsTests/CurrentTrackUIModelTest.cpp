#include "MockClasses.hpp"
#include "TrackPlaylistModel.hpp"

#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::_;
using ::testing::AtLeast;

TEST(CurrentTrackTriggeredModel, Shuffle) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    EXPECT_CALL(model, doNotify(&currentTrack, Shuffle))
      .Times(1);
    currentTrack.shuffle();
}

TEST(CurrentTrackTriggeredModel, Repeat) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    EXPECT_CALL(model, doNotify(&currentTrack, Repeat))
      .Times(1);
    currentTrack.repeat();
}

TEST(CurrentTrackTriggeredModel, PreviousTrack) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    EXPECT_CALL(model, doNotify(&currentTrack, PreviousTrack))
      .Times(1);
    currentTrack.previousTrack();
}

TEST(CurrentTrackTriggeredModel, NextTrack) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    EXPECT_CALL(model, doNotify(&currentTrack, NextTrack))
      .Times(1);
    currentTrack.nextTrack();
}

TEST(CurrentTrackTriggeredModel, DurationEnd) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    EXPECT_CALL(model, doNotify(&currentTrack, DurationEnd))
      .Times(1);
    currentTrack.moveDuration();
}

TEST(ModelTriggeredCurrentTrack, ChoosePreviousTrack) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    MockPlaylist playlist(&model);
    model.setCurrentTrack(&currentTrack);
    model.setPlaylist(&playlist);
    EXPECT_CALL(currentTrack, doChoosePreviousTrack())
      .Times(1);
    model.notify(&currentTrack, PreviousTrack);
}

TEST(ModelTriggeredCurrentTrack, ChooseNextTrack) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    MockPlaylist playlist(&model);
    model.setCurrentTrack(&currentTrack);
    model.setPlaylist(&playlist);
    EXPECT_CALL(currentTrack, doChooseNextTrack())
      .Times(1);
    model.notify(&currentTrack, NextTrack);
}

TEST(ModelTriggeredCurrentTrack, DurationEnd) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    MockPlaylist playlist(&model);
    model.setCurrentTrack(&currentTrack);
    model.setPlaylist(&playlist);
    EXPECT_CALL(currentTrack, doChooseNextTrack())
      .Times(1);
    model.notify(&currentTrack, DurationEnd);
}

int main(int argc, char *argv[]) {
  ::testing::FLAGS_gmock_verbose = "error";
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
