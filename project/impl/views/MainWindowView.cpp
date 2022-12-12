#include "MainWindowView.hpp"

#include <QBoxLayout>
#include <QPushButton>
#include <QStyle>

const int MAIN_WINDOW_WIDTH = 800;
const int MAIN_WINDOW_HEIGHT = 600;

MainWindowWidget::MainWindowWidget(QWidget* parent)
    : QWidget(parent) {
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    QFile styleF;
    styleF.setFileName("/home/marcussss1/2022_2_MidnightSun/project/impl/style/style.css");
    styleF.open(QFile::ReadOnly);
    QString qssStr = styleF.readAll();
    qApp->setStyleSheet(qssStr);
    setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
}

// cppcheck-suppress unusedFunction
void MainWindowWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        oldPos = event->pos();
    }
}

// cppcheck-suppress unusedFunction
void MainWindowWidget::mouseMoveEvent(QMouseEvent *event) {
    QPoint delta = event->pos() - oldPos;
    move(pos() + delta);
}

// #include "TrackPlaylistModel.hpp"

MainView::MainView()
    : mediator_(new TrackPlaylistModel),
      mainWindowWidget_(nullptr),
      titleBarButtonsWidget_(&mainWindowWidget_),
      currentTrackView_(&mainWindowWidget_),
      currentPlaylistView_(&mainWindowWidget_),
      leftBoardView_(&mainWindowWidget_),
      fileSystemView_(&mainWindowWidget_) {

    currentTrackView_.setCurrentTrackMediator(mediator_);
    currentPlaylistView_.setCurrentPlaylistMediator(mediator_);
    fileSystemView_.setFileSystemMediator(mediator_);

    mediator_->setCurrentTrack(currentTrackView_.getModel());
    mediator_->setPlaylist(currentPlaylistView_.getModel());
    mediator_->setFileSystem(fileSystemView_.getModel());
}

void MainView::show() {
    mainWindowWidget_.show();
}

void MainView::close() {
    mainWindowWidget_.close();
}
