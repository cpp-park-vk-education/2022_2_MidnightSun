#include "Models.hpp"

#include <gtest/gtest.h>

TEST(Track, ConstructorWithDuration) {
    auto duration = std::chrono::seconds{ 555 };
    TrackModel track(duration);
    EXPECT_EQ(track.getDuration(), duration);
}

TEST(Track, SetDurationPosition) {
    auto duration = std::chrono::seconds{ 555 };
    auto time = std::chrono::seconds{ 128 };
    TrackModel track(duration);
    track.setDurationPosition(time);
    EXPECT_EQ(track.getCurrentTime(), time);
}

TEST(Track, SetDurationPositionIfTimeBiggerDuration) {
    auto duration = std::chrono::seconds{ 555 };
    auto time = std::chrono::seconds{ 566 };
    TrackModel track(duration);
    track.setDurationPosition(time);
    EXPECT_EQ(track.getCurrentTime(), duration);
}

TEST(Track, SetVolume) {
    auto volume = 75.0;
    TrackModel track;
    track.setVolume(volume);
    EXPECT_EQ(track.getVolume(), volume);
}

TEST(Track, SetVolumeIfVolumeBiggerMaximum) {
    float volume = 125.0;
    TrackModel track;
    track.setVolume(volume);
    EXPECT_FLOAT_EQ(track.getVolume(), 100.0);
}

TEST(Track, PlayIfTrackNotIsPlaying) {
    auto trackIsPlaying = true;
    TrackModel track;
    track.play();
    EXPECT_EQ(track.isPlaying(), trackIsPlaying);
}

TEST(Track, PlayIfTrackIsPlaying) {
    auto trackIsPlaying = true;
    TrackModel track;
    track.play();
    track.play();
    EXPECT_EQ(track.isPlaying(), trackIsPlaying);
}

TEST(Track, PauseIfTrackNotIsPlaying) {
    auto trackIsPlaying = false;
    TrackModel track;
    track.pause();
    EXPECT_EQ(track.isPlaying(), trackIsPlaying);
}

TEST(Track, PauseIfTrackIsPlaying) {
    auto trackIsPlaying = false;
    TrackModel track;
    track.play();
    track.pause();
    EXPECT_EQ(track.isPlaying(), trackIsPlaying);
}

TEST(Track, StopIfTrackIsPlaying) {
    auto duration = std::chrono::seconds { 555 };
    auto timeBeforeStop = std::chrono::seconds{ 100 };
    auto timeAfterStop = std::chrono::seconds::zero();
    auto trackIsPlaying = false;
    TrackModel track(duration);
    track.play();
    track.setDurationPosition(timeBeforeStop);
    track.stop();
    EXPECT_EQ(track.isPlaying(), trackIsPlaying);
    EXPECT_EQ(track.getCurrentTime(), timeAfterStop);
}

TEST(Track, StopIfTrackNotIsPlaying) {
    auto duration = std::chrono::seconds { 555 };
    auto timeBeforeStop = std::chrono::seconds{ 100 };
    auto timeAfterStop = std::chrono::seconds::zero();
    auto trackIsPlaying = false;
    TrackModel track(duration);
    track.setDurationPosition(timeBeforeStop);
    track.stop();
    EXPECT_EQ(track.isPlaying(), trackIsPlaying);
    EXPECT_EQ(track.getCurrentTime(), timeAfterStop);
}


TEST(Track, RepeatIfTrackNotIsRepeating) {
    auto trackIsRepeating = true;
    TrackModel track;
    track.repeat();
    EXPECT_EQ(track.isRepeating(), trackIsRepeating);
}

TEST(Track, RepeatIfTrackIsRepeating) {
    auto trackIsRepeating = false;
    TrackModel track;
    track.repeat();
    track.repeat();
    EXPECT_EQ(track.isRepeating(), trackIsRepeating);
}

TEST(Track, Mute) {
    float volumeAfterMute = 0.0;
    TrackModel track;
    track.mute();
    EXPECT_EQ(track.getVolume(), volumeAfterMute);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
