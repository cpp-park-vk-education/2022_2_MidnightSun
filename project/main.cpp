#include "MainWindowView.hpp"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("/home/marcussss1/2022_2_MidnightSun/project/impl/icons/player.png"));
    MainView w;
    w.show();
    return a.exec();
}

// #include <thread>

// void a(FileSystemUIModel* m) {
//     m->openFile("/home/marcussss1/Downloads/Filatov_Karas_GAYAZOV_BROTHER_-_Poshla_zhara_72992182.wav");
// } 

// void b(FileSystemUIModel* m) {
//     m->openFile("/home/marcussss1/Downloads/Sultan_Laguchev_-_Lyubov_khuligana_73517967.mp3");
// } 

// void avds(FileSystemUIModel* re,
//           CurrentTrackUIModel* res){
//     qDebug() << "tes";
    // re->openFile("/home/marcussss1/Downloads/Filatov_Karas_GAYAZOV_BROTHER_-_Poshla_zhara_72992182.wav");
    // res->play();
//     }


// #include <QThread>

// class ExampleThreads : public QThread
// {
// public:
//     explicit ExampleThreads(CurrentTrackUIModel* currentTrack, FileSystemUIModel* fileSystem, std::string path)
//         : currentTrack_(currentTrack), fileSystem_(fileSystem), path_(path) {}

//     // Переопределяем метод run(), в котором будет
//     // располагаться выполняемый код
//     void run() {
//         fileSystem_->openFile(path_);
//         currentTrack_->play();
//     }
// private:
//     CurrentTrackUIModel* currentTrack_;   // Имя потока
//     FileSystemUIModel* fileSystem_;
//     std::string path_;
// };

// #include <unistd.h>

// int main(int argc, char** argv) {

//     QApplication a(argc, argv);
//     TrackPlaylistModel* mediator = new TrackPlaylistModel;;

//     CurrentTrackUIModel* currentTrack = new CurrentTrackUIModel;
//     FileSystemUIModel* fileSystem = new FileSystemUIModel;
//     CurrentPlaylistUIModel* currentPlaylist = new CurrentPlaylistUIModel;

//     // currentTrackView_.setCurrentTrackMediator(mediator_);
//     // currentPlaylistView_.setCurrentPlaylistMediator(mediator_);
//     // fileSystemView_.setFileSystemMediator(mediator_);

//     // int* ss = new int;
    
//     // std::thread B(&b, fileSystem);

//     currentTrack->setCurrentTrackMediator(mediator);
//     currentPlaylist->setCurrentPlaylistMediator(mediator);
//     fileSystem->setFileSystemMediator(mediator);

//     mediator->setCurrentTrack(currentTrack);
//     mediator->setPlaylist(currentPlaylist);
//     mediator->setFileSystem(fileSystem);

//     // ExampleThreads threadA(currentTrack, fileSystem, "sfdf");
//     // ExampleThreads threadA(currentTrack, fileSystem, "/home/marcussss1/Downloads/Filatov_Karas_GAYAZOV_BROTHER_-_Poshla_zhara_72992182.wav");
//     // ExampleThreads threadB(currentTrack, fileSystem, "/home/marcussss1/Downloads/Sultan_Laguchev_-_Lyubov_khuligana_73517967.mp3");
//     // threadA.start(); 
//     // threadB.start();

//     // QMediaPlayer* n = new QMediaPlayer;
//     // QMediaPlayer* m = new QMediaPlayer;

//     // n->setMedia(QUrl::fromLocalFile("/home/marcussss1/Downloads/Sultan_Laguchev_-_Lyubov_khuligana_73517967.mp3"));
//     // m->setMedia(QUrl::fromLocalFile("/home/marcussss1/Downloads/Filatov_Karas_GAYAZOV_BROTHER_-_Poshla_zhara_72992182.wav"));

//     // n->play();
//     // m->play();
//     // if (fork() == 0) {
//         // fileSystem->openFile("/home/marcussss1/Downloads/Sultan_Laguchev_-_Lyubov_khuligana_73517967.mp3");
//     //     qDebug() << currentTrack;
//     //     currentTrack->play();
//     // } else {
//     //     fileSystem->openFile("/home/marcussss1/Downloads/Filatov_Karas_GAYAZOV_BROTHER_-_Poshla_zhara_72992182.wav");
//     // currentPlaylist->chooseTrack(0);
//     // currentPlaylist->chooseTrack(1);
//     // currentTrack->play(0);
//     // currentTrack->chooseTrack()
//     //     qDebug() << currentTrack;
//     //     currentTrack->play();
//     // }
//     // getpid
//     // qDebug() << 4242;
//     // fileSystem->openFile("/home/marcussss1/Downloads/Sultan_Laguchev_-_Lyubov_khuligana_73517967.mp3");
//     // currentTrack->play();
//     // std::thread A(avds, fileSystem, currentTrack);
//     // A.join();
//     // currentTrack->play();
//     // fileSystem->openFile("/home/marcussss1/Downloads/Filatov_Karas_GAYAZOV_BROTHER_-_Poshla_zhara_72992182.wav");
//     // currentTrack->play();
//     // currentTrack->setDuration(40000);
//     return a.exec();
//     // return 0;
// }
