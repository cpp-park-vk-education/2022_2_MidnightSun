#include "Playlist.hpp"

#include <gtest/gtest.h>

TEST(Playlist, AddTrack) {
    Playlist playlist;
    Track track;
    size_t countingTracks = 100;
    for (size_t i = 0; i < countingTracks; ++i) {
        playlist.addTrack(track);
    }
    EXPECT_EQ(playlist.getSize(), countingTracks);
}

TEST(Playlist, DeleteTrack) {
    Playlist playlist;
    Track track;
    size_t countingTracks = 100;
    size_t countingTracksAfterDelete = 0;
    for (size_t i = 0; i < countingTracks; ++i) {
        playlist.addTrack(track);
    }
    for (size_t i = 0; i < countingTracks; ++i) {
        playlist.deleteTrack(track);
    }
    EXPECT_EQ(playlist.getSize(), countingTracksAfterDelete);
}

TEST(Playlist, DeleteTrackIfTrackNotInPlaylist) {
    Playlist playlist;
    Track track;
    size_t countingTracksAfterDelete = 0;
    playlist.deleteTrack(track);
    EXPECT_EQ(playlist.getSize(), countingTracksAfterDelete);
}

TEST(Playlist, SetCurrentTrack) {
    Playlist playlist;
    Track track;
    playlist.addTrack(track);
    playlist.setCurrentTrack(track);
    EXPECT_EQ(playlist.getCurrentTrack(), track);
}

TEST(Playlist, SetCurrentTrackIfTrackNotInPlaylist) {
    Playlist playlist;
    Track trackInPlaylist("Track 1");
    Track trackNotInPlaylist("Track 2");
    playlist.addTrack(trackInPlaylist);
    playlist.setCurrentTrack(trackInPlaylist);
    playlist.setCurrentTrack(trackNotInPlaylist);
    EXPECT_EQ(playlist.getCurrentTrack(), trackInPlaylist);
}

TEST(Playlist, SetNextTrack) {
    Playlist playlist;
    Track track("Track 1");
    Track nextTrack("Track 2");
    playlist.addTrack(track);
    playlist.addTrack(nextTrack);
    playlist.setCurrentTrack(track);
    playlist.setNextTrack();
    EXPECT_EQ(playlist.getCurrentTrack(), nextTrack);
}

TEST(Playlist, SetNextTrackIfLastTrack) {
    Playlist playlist;
    Track track("Track 1");
    Track nextTrack("Track 2");
    playlist.addTrack(track);
    playlist.addTrack(nextTrack);
    playlist.setCurrentTrack(nextTrack);
    playlist.setNextTrack();
    EXPECT_EQ(playlist.getCurrentTrack(), track);
}

TEST(Playlist, SetPreviousTrack) {
    Playlist playlist;
    Track previousTrack("Track 1");
    Track track("Track 2");
    playlist.addTrack(previousTrack);
    playlist.addTrack(track);
    playlist.setCurrentTrack(track);
    playlist.setPreviousTrack();
    EXPECT_EQ(playlist.getCurrentTrack(), previousTrack);
}

TEST(Playlist, SetPreviousTrackIfFirstTrack) {
    Playlist playlist;
    Track previousTrack("Track 1");
    Track track("Track 2");
    playlist.addTrack(previousTrack);
    playlist.addTrack(track);
    playlist.setCurrentTrack(previousTrack);
    playlist.setPreviousTrack();
    EXPECT_EQ(playlist.getCurrentTrack(), previousTrack);
}

TEST(Playlist, Shuffle) {
    Playlist playlist;
    Playlist playlistAfterShuffle;
    size_t countingTracks = 20;
    for (size_t i = 0; i < countingTracks; ++i) {
        auto trackName = "track" + std::to_string(i);
        playlist.addTrack(Track(trackName));
    }
    playlistAfterShuffle = playlist;
    playlistAfterShuffle.shuffle();
    for (size_t i = 0; i < countingTracks; ++i) {
        EXPECT_NE(playlist[i], playlistAfterShuffle[i]);
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
