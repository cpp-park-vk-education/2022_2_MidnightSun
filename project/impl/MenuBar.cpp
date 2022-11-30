#include "MenuBar.hpp"

// MenuBarView::MenuBarView(QWidget* parent)
//     : menuBarWidget_(new QTableWidget(parent)) {
//     // menuBarWidget_->setGeometry(QRect(200, 25, 600, 475));
// }

#include <QFileDialog>
#include <QDebug>

MenuBarView::MenuBarView(QWidget* parent) 
    : menuBarWidget_(new QMenuBar(parent)) {
    menuBarWidget_->setGeometry(QRect(0, 0, 200, 25));
    menuAddFile_ = menuBarWidget_->addMenu("Файл");
    actionAddFile_ = menuAddFile_->addAction("Открыть файл");
    connect(actionAddFile_, SIGNAL(triggered()), this, SLOT(openFile()));
}

void MenuBarView::openFile() {
    QStringList list  = QFileDialog::getOpenFileNames(menuBarWidget_,
                                                      ("Select Files"), "Z:\\Music",
                                                      ("MP3 Files (*.mp3)"));
    qDebug() << list;
}

MenuBarView::~MenuBarView() {
    delete menuBarWidget_;
}
