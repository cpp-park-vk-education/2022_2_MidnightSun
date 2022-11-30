#pragma once

#include <QTableWidget>

class CurrentPlaylistView {
 public:
    explicit CurrentPlaylistView(QWidget* parent);
    ~CurrentPlaylistView();
 private:
    QTableWidget* currentPlaylistWidget_;
};
