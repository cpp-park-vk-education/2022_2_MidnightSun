#pragma once

#include "QCurrentPlaylistController.hpp"
#include "QCurrentPlaylistUIModel.hpp"

#include <QAction>
#include <QMenu>
#include <QHeaderView>
#include <QTableWidget>

class CurrentPlaylistView : public QTableWidget {
 Q_OBJECT
 public:
    explicit CurrentPlaylistView(CurrentPlaylistUIModel* model, QWidget* parent);
    ~CurrentPlaylistView() = default;

    void setCurrentPlaylistMediator(Mediator* mediator);
    CurrentPlaylistUIModel* getModel();
 private slots:
    void addTrackInWidget(QString path);
    void deleteTrackInWidget();
    void chooseTrackInWidget();

    void trackClicked();

 private:
    QCurrentPlaylistUIModel* model_;
    QCurrentPlaylistController* controller_;
    
    QTableWidget* currentPlaylistWidget_;
    QMenu* menu_;
    QAction* addTrack_;
    QAction* deleteTrack_;
    QAction* chooseTrack_;
};
