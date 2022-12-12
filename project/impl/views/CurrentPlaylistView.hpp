#pragma once

#include <QCurrentPlaylistController.hpp>

#include <QAction>
#include <QMenu>
#include <QHeaderView>
#include <QTableWidget>

class CurrentPlaylistView : public QTableWidget {
 Q_OBJECT
 public:
    explicit CurrentPlaylistView(QWidget* parent);
    ~CurrentPlaylistView() = default;

    void setCurrentPlaylistMediator(Mediator* mediator);
    CurrentPlaylistUIModel* getModel();
 private slots:
    void addTrackInWidget(QString path);
    void deleteTrackInWidget();
    void chooseTrackInWidget();

    void trackClicked();

 private:
    CurrentPlaylistUIModel* model_;
    QCurrentPlaylistController* controller_;
    
    QTableWidget* currentPlaylistWidget_;
    QMenu* menu_;
    QAction* addTrack_;
    QAction* deleteTrack_;
    QAction* chooseTrack_;
};
