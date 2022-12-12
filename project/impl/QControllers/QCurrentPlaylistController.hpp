#pragma once

#include "CurrentPlaylistController.hpp"
#include <QObject>

class QCurrentPlaylistController : public QObject {
 Q_OBJECT
 public:
    explicit QCurrentPlaylistController(CurrentPlaylistUIModel* model);
 private slots:

    void addTrack(std::string path);
    void deleteTrack(size_t index);
    void chooseTrack(size_t index);
 
 private:
    CurrentPlaylistController* controller_;
};
