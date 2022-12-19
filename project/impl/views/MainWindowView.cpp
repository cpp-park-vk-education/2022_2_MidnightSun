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

MainView::MainView()
    : mediator_(new TrackPlaylistModel),
      mainWindowWidget_(nullptr),
      titleBarButtonsWidget_(&mainWindowWidget_),
      firstCurrentTrackView_(new CurrentTrackUIModel, &mainWindowWidget_, 0),
      secondCurrentTrackView_(new CurrentTrackUIModel, &mainWindowWidget_, 150),
      thirdCurrentTrackView_(new CurrentTrackUIModel, &mainWindowWidget_, 300),
      currentPlaylistView_(new CurrentPlaylistUIModel, &mainWindowWidget_),
      leftBoardView_(&mainWindowWidget_),
      fileSystemView_(&mainWindowWidget_) {


    // thirdCurrentTrackView_ = firstCurrentTrackView_;

    // secondCurrentTrackView_.initializeView();

    connect(&currentPlaylistView_, SIGNAL(currentTrackChanged()),
            &firstCurrentTrackView_, SLOT(currentTrackChanged()));

    // connect(&currentPlaylistView_, SIGNAL(currentTrackChanged(int)),
    //         &firstCurrentTrackView_, SLOT(currentTrackChanged(int)));

    connect(&fileSystemView_, SIGNAL(openFile(QString)),
            &currentPlaylistView_, SLOT(addTrackInWidget(QString)));

    firstCurrentTrackView_.setCurrentTrackMediator(mediator_);
    currentPlaylistView_.setCurrentPlaylistMediator(mediator_);
    fileSystemView_.setFileSystemMediator(mediator_);

    mediator_->setCurrentTrack(firstCurrentTrackView_.getModel());
    mediator_->setPlaylist(currentPlaylistView_.getModel());
    mediator_->setFileSystem(fileSystemView_.getModel());
}

void MainView::show() {
    mainWindowWidget_.show();
}

void MainView::close() {
    mainWindowWidget_.close();
}
