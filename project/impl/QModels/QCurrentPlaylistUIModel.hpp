#pragma once

#include "CurrentPlaylistUIModel.hpp"

class QCurrentPlaylistUIModel : public QObject {
 Q_OBJECT
 public:
    explicit QCurrentPlaylistUIModel(CurrentPlaylistUIModel* model);
 
    void setCurrentPlaylistMediator(Mediator* mediator);

    void addTrack(std::string path);
    void deleteTrack(size_t index);
    void chooseTrack(size_t index);

 signals:
    void addTrack();
    void deleteTrack();
    void chooseTrack();

//  private:
 public:
    CurrentPlaylistUIModel* model_;
};
