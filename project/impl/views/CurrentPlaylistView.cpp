#include "CurrentPlaylistView.hpp"

// #include <QMenu>




// CurrentPlaylistUIModel::CurrentPlaylistUIModel(Mediator* mediator)
    // : Sender(mediator) {}

//////////////////////////////////////// Current Playlist UIModel ////////////////////////////////////////

// void CurrentPlaylistUIModel::setCurrentPlaylistMediator(Mediator* mediator) {
//     mediator_ = mediator;
// }

// // функции, которые триггерятся контроллером

// Status CurrentPlaylistUIModel::addTrack(std::string path) {
//     Track* track = new Track(path);
//     playlist_.addTrack(track);
//     emit addTrackInWidget(QString::fromStdString(path));
//     return Success;
// }

// Status CurrentPlaylistUIModel::deleteTrack(size_t index) {

// }

// Status CurrentPlaylistUIModel::chooseTrack(size_t index) {
//     mediator_->notifyTrackPlaylist(this, ChooseTrack, playlist_[index]);
//     return Success;
// }

// // функции, которые триггерятся Current Track моделью

// #include <QDebug>

// CurrentPlaylistController::CurrentPlaylistController(CurrentPlaylistUIModel* model)
//     : model_(model) {}

// Status CurrentPlaylistUIModel::setShuffle() {

// }

// Status CurrentPlaylistUIModel::choosePreviousTrack() {

// }

// Status CurrentPlaylistUIModel::chooseNextTrack() {

// }

// #include <QDebug>

// Status CurrentPlaylistUIModel::chooseTrack(QString path) {

// }

// //////////////////////////////////////// Current Playlist Controller ////////////////////////////////////////

// void CurrentPlaylistController::addTrack(std::string path) {
//     model_->addTrack(path);
// }

// void CurrentPlaylistController::deleteTrack(Track track) {
//     model_->deleteTrack(track);
// }

// void CurrentPlaylistController::chooseTrack(size_t index) {
//     model_->chooseTrack(index);
// }

//////////////////////////////////////// Current Playlist View ////////////////////////////////////////


// #include <QDebug>
// #include <QtGui/QMouseEvent>

// void CurrentPlaylistView::mousePressEvent(QMouseEvent *event) {
//     qDebug() << 44;
//     if (event->button() == Qt::RightButton)
// {
//     QMenu menu;
//     menu.addAction(addTrack_);
//     menu.addAction(deleteTrack_);
//     menu.popup(event->globalPos(),addTrack_);
// }
// }



CurrentPlaylistView::CurrentPlaylistView(CurrentPlaylistUIModel* model, QWidget* parent)
    : model_(new QCurrentPlaylistUIModel(model)),
      controller_(new QCurrentPlaylistController(model)),
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

    // connect(addTrack_, SIGNAL(triggered()),
            // );


    // connect(model_, SIGNAL(addTrackInWidget(QString)),
    //         this, SLOT(addTrackInWidget(QString)));

    connect(chooseTrack_, SIGNAL(triggered()),
            this, SLOT(chooseTrackInWidget()));

    addTrack_->setText("Добавить трек");
    chooseTrack_->setText("Выбрать трек");
    deleteTrack_->setText("Удалить трек");

    menu_->addAction(addTrack_);
    menu_->addAction(chooseTrack_);
    menu_->addAction(deleteTrack_);
}

// #include <QDebug>
// #include <QHeaderView>
// #include <QPoint>
// #include <QWidget>
// #include <QAplication>

void CurrentPlaylistView::chooseTrackInWidget() {
    QItemSelectionModel *selectModel = currentPlaylistWidget_->selectionModel();
    if (selectModel->hasSelection()) {
        model_->chooseTrack(selectModel->selectedRows().first().row());
        // selectModel->set("CurrentTrackInPlaylist");
        currentPlaylistWidget_->item(selectModel->selectedRows().first().row(), 0)->setTextColor(Qt::red);
    }
}

void CurrentPlaylistView::deleteTrackInWidget() {

}

void CurrentPlaylistView::trackClicked() {
    menu_->popup(currentPlaylistWidget_->viewport()->mapToGlobal(QPoint(250, 250)));
}

void CurrentPlaylistView::addTrackInWidget(QString path) {
    // qDebug() << "ZAHODIM";
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

void CurrentPlaylistView::setCurrentPlaylistMediator(Mediator* mediator) {
    model_->setCurrentPlaylistMediator(mediator);
}

CurrentPlaylistUIModel* CurrentPlaylistView::getModel() {
    return model_->model_;
}
