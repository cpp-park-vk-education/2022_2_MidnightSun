#include "FileSystemView.hpp"

const int MENU_BAR_WIDTH = 200;
const int MENU_BAR_HEIGHT = 25;

FileSystemView::FileSystemView(QWidget* parent) 
    : menuBarWidget_(new QMenuBar(parent)),
      model_(new FileSystemUIModel),
      controller_(new FileSystemController(model_)) {
    menuBarWidget_->setGeometry(QRect(0, 0, 200, 25));
    menuAddFile_ = menuBarWidget_->addMenu("Файл");
    actionAddFile_ = menuAddFile_->addAction("Открыть файл");
    connect(actionAddFile_, SIGNAL(triggered()), this, SLOT(openFile()));
}

void FileSystemView::openFile() {
    auto path  = QFileDialog::getOpenFileNames(menuBarWidget_,
                                               "Select Files", 
                                               "/home/marcussss1/Downloads/Sultan_Laguchev_-_Lyubov_khuligana_73517967.mp3",
                                               "WAV Files (*.wav)");
    if (!path.empty()) {
        controller_->openFile(path.join("").toStdString());
        emit openFile(path.join(""));
    }
}

void FileSystemView::setFileSystemMediator(Mediator* mediator) {
    model_->setFileSystemMediator(mediator);
}

FileSystemUIModel* FileSystemView::getModel() {
    return model_;
}

FileSystemView::~FileSystemView() {
    delete menuBarWidget_;
}
