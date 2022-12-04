#pragma once

#include "CurrentTrack.hpp"
#include "CurrentPlaylist.hpp"
#include "Mediator.hpp"

class TrackPlaylistModel : public Mediator {
 public:
    virtual void setCurrentTrack(CurrentTrackUIModel* model);
    virtual void setPlaylist(PlaylistUIModel* model);

    virtual void notify(Sender* sender, Function function) override;
 protected:
    CurrentTrackUIModel* currentTrack_;
    PlaylistUIModel* playlist_;
};
