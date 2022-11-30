#include "CurrentPlaylist.hpp"

CurrentPlaylistView::CurrentPlaylistView(QWidget* parent)
    : currentPlaylistWidget_(new QTableWidget(parent)) {
    currentPlaylistWidget_->setGeometry(QRect(200, 25, 600, 475));
}

CurrentPlaylistView::~CurrentPlaylistView() {
    delete currentPlaylistWidget_;
}
