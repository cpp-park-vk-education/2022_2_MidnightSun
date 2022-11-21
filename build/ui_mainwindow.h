/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_files;
    QAction *actionAbout_Me;
    QAction *actionRemove_File;
    QAction *actionAdd_to_Queue;
    QAction *actionPlay_Selected;
    QAction *actionCopy_to_Clipboard;
    QAction *actionClear_all;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *TablePlayList;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblTimeElsp;
    QSlider *SeekSlider;
    QLabel *lblTimeRemaining;
    QSplitter *splitter;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnShuffel;
    QPushButton *btnPrev;
    QPushButton *btnPlay;
    QPushButton *btnStop;
    QPushButton *btnPause;
    QPushButton *btnNext;
    QPushButton *btnRepeat;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QSlider *VolumeSlider;
    QPushButton *btnMute;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(679, 419);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/icons/Audio Wave-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAdd_files = new QAction(MainWindow);
        actionAdd_files->setObjectName(QString::fromUtf8("actionAdd_files"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/icons/Plus Math-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_files->setIcon(icon1);
        actionAbout_Me = new QAction(MainWindow);
        actionAbout_Me->setObjectName(QString::fromUtf8("actionAbout_Me"));
        actionRemove_File = new QAction(MainWindow);
        actionRemove_File->setObjectName(QString::fromUtf8("actionRemove_File"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/icons/Minus-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_File->setIcon(icon2);
        actionAdd_to_Queue = new QAction(MainWindow);
        actionAdd_to_Queue->setObjectName(QString::fromUtf8("actionAdd_to_Queue"));
        actionPlay_Selected = new QAction(MainWindow);
        actionPlay_Selected->setObjectName(QString::fromUtf8("actionPlay_Selected"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/icons/Play-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay_Selected->setIcon(icon3);
        actionCopy_to_Clipboard = new QAction(MainWindow);
        actionCopy_to_Clipboard->setObjectName(QString::fromUtf8("actionCopy_to_Clipboard"));
        actionClear_all = new QAction(MainWindow);
        actionClear_all->setObjectName(QString::fromUtf8("actionClear_all"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/icons/Delete-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_all->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        TablePlayList = new QTableWidget(groupBox);
        if (TablePlayList->columnCount() < 2)
            TablePlayList->setColumnCount(2);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        TablePlayList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TablePlayList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        TablePlayList->setObjectName(QString::fromUtf8("TablePlayList"));
        QFont font1;
        font1.setPointSize(8);
        TablePlayList->setFont(font1);
        TablePlayList->setContextMenuPolicy(Qt::ActionsContextMenu);
        TablePlayList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        TablePlayList->setDragDropMode(QAbstractItemView::DragDrop);
        TablePlayList->setAlternatingRowColors(true);
        TablePlayList->setSelectionMode(QAbstractItemView::SingleSelection);
        TablePlayList->setSelectionBehavior(QAbstractItemView::SelectRows);
        TablePlayList->setGridStyle(Qt::SolidLine);
        TablePlayList->setSortingEnabled(true);
        TablePlayList->setWordWrap(true);
        TablePlayList->setCornerButtonEnabled(false);
        TablePlayList->setRowCount(0);
        TablePlayList->setColumnCount(2);
        TablePlayList->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(TablePlayList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lblTimeElsp = new QLabel(groupBox);
        lblTimeElsp->setObjectName(QString::fromUtf8("lblTimeElsp"));

        horizontalLayout_3->addWidget(lblTimeElsp);

        SeekSlider = new QSlider(groupBox);
        SeekSlider->setObjectName(QString::fromUtf8("SeekSlider"));
        SeekSlider->setMaximum(100);
        SeekSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(SeekSlider);

        lblTimeRemaining = new QLabel(groupBox);
        lblTimeRemaining->setObjectName(QString::fromUtf8("lblTimeRemaining"));

        horizontalLayout_3->addWidget(lblTimeRemaining);


        verticalLayout_2->addLayout(horizontalLayout_3);

        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnShuffel = new QPushButton(groupBox_3);
        btnShuffel->setObjectName(QString::fromUtf8("btnShuffel"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/icons/Shuffle-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnShuffel->setIcon(icon5);
        btnShuffel->setIconSize(QSize(18, 18));
        btnShuffel->setCheckable(true);

        horizontalLayout_2->addWidget(btnShuffel);

        btnPrev = new QPushButton(groupBox_3);
        btnPrev->setObjectName(QString::fromUtf8("btnPrev"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/icons/Fast Backward-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrev->setIcon(icon6);
        btnPrev->setIconSize(QSize(18, 18));

        horizontalLayout_2->addWidget(btnPrev);

        btnPlay = new QPushButton(groupBox_3);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icons/icons/Play-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon7);
        btnPlay->setIconSize(QSize(18, 18));

        horizontalLayout_2->addWidget(btnPlay);

        btnStop = new QPushButton(groupBox_3);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Icons/icons/Stop-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon8);
        btnStop->setIconSize(QSize(18, 18));

        horizontalLayout_2->addWidget(btnStop);

        btnPause = new QPushButton(groupBox_3);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Icons/icons/Pause-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon9);
        btnPause->setIconSize(QSize(18, 18));
        btnPause->setCheckable(true);

        horizontalLayout_2->addWidget(btnPause);

        btnNext = new QPushButton(groupBox_3);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Icons/icons/Fast Forward-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon10);
        btnNext->setIconSize(QSize(18, 18));

        horizontalLayout_2->addWidget(btnNext);

        btnRepeat = new QPushButton(groupBox_3);
        btnRepeat->setObjectName(QString::fromUtf8("btnRepeat"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Icons/icons/Repeat-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRepeat->setIcon(icon11);
        btnRepeat->setIconSize(QSize(18, 18));
        btnRepeat->setCheckable(true);
        btnRepeat->setChecked(true);

        horizontalLayout_2->addWidget(btnRepeat);

        splitter->addWidget(groupBox_3);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        VolumeSlider = new QSlider(groupBox_2);
        VolumeSlider->setObjectName(QString::fromUtf8("VolumeSlider"));
        VolumeSlider->setMaximum(100);
        VolumeSlider->setValue(75);
        VolumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(VolumeSlider);

        btnMute = new QPushButton(groupBox_2);
        btnMute->setObjectName(QString::fromUtf8("btnMute"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Icons/icons/Mute-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMute->setIcon(icon12);
        btnMute->setIconSize(QSize(16, 16));
        btnMute->setCheckable(true);
        btnMute->setAutoRepeat(false);
        btnMute->setFlat(false);

        horizontalLayout->addWidget(btnMute);

        splitter->addWidget(groupBox_2);

        verticalLayout_2->addWidget(splitter);


        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 679, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionAdd_files);
        menuFile->addSeparator();
        menuHelp->addAction(actionAbout_Me);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MP3 Player - by SaEeD  V0.1", nullptr));
        actionAdd_files->setText(QApplication::translate("MainWindow", "Add New Files", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAdd_files->setToolTip(QApplication::translate("MainWindow", "Add new files to playlist", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAdd_files->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout_Me->setText(QApplication::translate("MainWindow", "About Me", nullptr));
        actionRemove_File->setText(QApplication::translate("MainWindow", "Remove File", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRemove_File->setToolTip(QApplication::translate("MainWindow", "Remove File from List", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRemove_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionAdd_to_Queue->setText(QApplication::translate("MainWindow", "Add to Queue", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAdd_to_Queue->setToolTip(QApplication::translate("MainWindow", "Add to Queue to play next", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAdd_to_Queue->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionPlay_Selected->setText(QApplication::translate("MainWindow", "Play Selected", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPlay_Selected->setToolTip(QApplication::translate("MainWindow", "Play Selected file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionPlay_Selected->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy_to_Clipboard->setText(QApplication::translate("MainWindow", "Copy to Clipboard", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCopy_to_Clipboard->setToolTip(QApplication::translate("MainWindow", "Copy contents to Clipboard", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCopy_to_Clipboard->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionClear_all->setText(QApplication::translate("MainWindow", "Clear all", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClear_all->setToolTip(QApplication::translate("MainWindow", "Clear the playlist", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionClear_all->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox->setTitle(QApplication::translate("MainWindow", "MP3  PLAYER", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TablePlayList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Tag", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TablePlayList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Title", nullptr));
        lblTimeElsp->setText(QApplication::translate("MainWindow", "00:00", nullptr));
        lblTimeRemaining->setText(QApplication::translate("MainWindow", "00:00", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Controller:", nullptr));
        btnShuffel->setText(QString());
        btnPrev->setText(QString());
        btnPlay->setText(QString());
        btnStop->setText(QString());
        btnPause->setText(QString());
        btnNext->setText(QString());
        btnRepeat->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Volume:", nullptr));
        btnMute->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
