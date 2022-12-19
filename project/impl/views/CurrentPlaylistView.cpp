#include "CurrentPlaylistView.hpp"

CurrentPlaylistView::CurrentPlaylistView(CurrentPlaylistUIModel* model, QWidget* parent)
    : model_(model),
      controller_(new CurrentPlaylistController(model)),
      currentPlaylistWidget_(new QTableWidget(parent)),
      menu_(new QMenu(parent)),
      addTrack_(new QAction(currentPlaylistWidget_)),
      deleteTrack_(new QAction(currentPlaylistWidget_)),
      chooseTrack_(new QAction(currentPlaylistWidget_)) {

    currentPlaylistWidget_->setGeometry(QRect(200, 25, 600, 450));
    // currentPlaylistWidget_->setMouseTracking(true);
    // currentPlaylistWidget_->show();
    // currentPlaylistWidget_->setCentra

    connect(currentPlaylistWidget_, &QTableWidget::clicked,
            this, &CurrentPlaylistView::trackClicked);

    connect(addTrack_, SIGNAL(triggered()),
            this, SLOT(addTrackInWidget())); // .. моя вьюшка триггерит ... а не main view

    connect(deleteTrack_, SIGNAL(triggered()),
            this, SLOT(deleteTrackInWidget()));

    connect(chooseTrack_, SIGNAL(triggered()),
            this, SLOT(chooseTrackInWidget()));

    addTrack_->setText("Добавить трек");
    chooseTrack_->setText("Выбрать трек");
    deleteTrack_->setText("Удалить текущий трек");

    menu_->addAction(addTrack_);
    menu_->addAction(chooseTrack_);
    menu_->addAction(deleteTrack_);
}

void CurrentPlaylistView::addTrackInWidget(QString path) { // триггерится другой вьюшкой
    auto size = currentPlaylistWidget_->rowCount();

    currentPlaylistWidget_->setRowCount(size + 1);
    currentPlaylistWidget_->setColumnCount(1);

    currentPlaylistWidget_->verticalHeader()->setVisible(false);
    currentPlaylistWidget_->horizontalHeader()->setVisible(false);

    currentPlaylistWidget_->setItem(size, size, new QTableWidgetItem);
    currentPlaylistWidget_->setColumnWidth(size, 600); 
    currentPlaylistWidget_->setRowHeight(size, 50);   

    currentPlaylistWidget_->setItem(size, 0, new QTableWidgetItem(path));
    currentPlaylistWidget_->item(size, 0)->setTextColor(Qt::white);
}


void CurrentPlaylistView::chooseTrackInWidget() {
    QItemSelectionModel *selectModel = currentPlaylistWidget_->selectionModel();
    if (selectModel->hasSelection()) {
        emit currentTrackChanged();
        // emit currentTrackChanged(selectModel->selectedRows().first().row());
        controller_->chooseTrack(selectModel->selectedRows().first().row());
        currentPlaylistWidget_->item(selectModel->selectedRows().first().row(), 0)->setTextColor(Qt::red);
    }
}

// void CurrentPlaylistView::deleteCurrentTrack() {
//     QItemSelectionModel *selectModel = currentPlaylistWidget_->selectionModel();
//     if (selectModel->hasSelection()) {
//         emit deleteCurrentTrack(selectModel->selectedRows().first().row());
//         // controller_->deleteTrack(selectModel->selectedRows().first().row());
//         // emit currentTrackChanged();
//         // emit currentTrackChanged(selectModel->selectedRows().first().row());
//         // controller_->chooseTrack(selectModel->selectedRows().first().row());
//         // currentPlaylistWidget_->item(selectModel->selectedRows().first().row(), 0)->setTextColor(Qt::red);
//     }
// }

void CurrentPlaylistView::trackClicked() {
    menu_->popup(currentPlaylistWidget_->viewport()->mapToGlobal(QPoint(250, 250)));
}

void CurrentPlaylistView::setCurrentPlaylistMediator(Mediator* mediator) {
    model_->setCurrentPlaylistMediator(mediator);
}

CurrentPlaylistUIModel* CurrentPlaylistView::getModel() {
    return model_;
}
