#include "MockClasses.hpp"
#include "TrackPlaylistModel.hpp"

#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::_;
using ::testing::AtLeast;

TEST(PlaylistTriggeredModel, ChooseTrack) {
    MockModel model;
    MockPlaylist playlist(&model);
    EXPECT_CALL(model, doNotify(&playlist, ChooseTrack))
      .Times(1);
    playlist.chooseTrack();
}

TEST(ModelTriggeredPlaylist, Shuffle) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    MockPlaylist playlist(&model);
    model.setCurrentTrack(&currentTrack);
    model.setPlaylist(&playlist);
    EXPECT_CALL(playlist, doSetShuffle())
      .Times(1);
    model.notify(&currentTrack, Shuffle);
}

TEST(ModelTriggeredPlaylist, PreviousTrack) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    MockPlaylist playlist(&model);
    model.setCurrentTrack(&currentTrack);
    model.setPlaylist(&playlist);
    EXPECT_CALL(playlist, doChoosePreviousTrack())
      .Times(1);
    model.notify(&currentTrack, PreviousTrack);
}

TEST(ModelTriggeredPlaylist, NextTrack) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    MockPlaylist playlist(&model);
    model.setCurrentTrack(&currentTrack);
    model.setPlaylist(&playlist);
    EXPECT_CALL(playlist, doChooseNextTrack())
      .Times(1);
    model.notify(&currentTrack, NextTrack);
}

TEST(ModelTriggeredPlaylist, Repeat) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    MockPlaylist playlist(&model);
    model.setCurrentTrack(&currentTrack);
    model.setPlaylist(&playlist);
    EXPECT_CALL(playlist, doSetRepeat())
      .Times(1);
    model.notify(&currentTrack, Repeat);
}

TEST(ModelTriggeredPlaylist, DurationEnd) {
    MockModel model;
    MockCurrentTrack currentTrack(&model);
    MockPlaylist playlist(&model);
    model.setCurrentTrack(&currentTrack);
    model.setPlaylist(&playlist);
    EXPECT_CALL(playlist, doChooseNextTrack())
      .Times(1);
    model.notify(&currentTrack, DurationEnd);
}

int main(int argc, char *argv[]) {
  ::testing::FLAGS_gmock_verbose = "error";
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
