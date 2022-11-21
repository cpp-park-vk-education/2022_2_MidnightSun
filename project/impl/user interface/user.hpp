

#include "userView.hpp"
#include "MediaPlayer.hpp"


class Mute : public MuteView, public QAbstractButton {
 private Q_SIGNALS:
        void muteButtonClicked();
 private:
    QPushButton* m_muteButton(nullptr);
    MediaPlayerModel* m_mplayer(nullptr);
};


// TODO
class DurationBar : public DurationBarView /* , ... */ {
};

// TODO
class VolumeSlider : public VolumeSliderView /* , ... */ {
}; 




class Stop : public StopView, public QAbstractButton {
 public:
    Q_SIGNALS:
        void stopButtonClicked();
 private:
    QPushButton* m_stopButton(nullptr);
    MediaPlayerModel* m_mplayerModel(nullptr);
};

class Play : public PlayView, public QAbstractButton {
 public:
    Q_SIGNALS:
        void playButtonClicked();
 private:
    QPushButton* m_playButton(nullptr);
    MediaPlayerModel* m_mplayerModel(nullptr);
};

class Pause : public PauseView, public QAbstractButton {
 public:
    Q_SIGNALS:
        void pauseButtonClicked();
 private:
    QPushButton* m_pauseButton(nullptr);
    MediaPlayerModel* m_mplayerModel(nullptr);
};



class PreviousTrack : public PreviousTrackView, public QAbstractButton {
 public:
    Q_SIGNALS:
        void previousTrackButtonClicked();
 private:
    QPushButton* m_previousTrackButton(nullptr);
    MediaPlayerModel* m_mplayerModel(nullptr);
};


class NextTrack : public nextTrackView, public QAbstractButton {
 public:
    Q_SIGNALS:
        void nextTrackButtonClicked();
 private:
    QPushButton* m_nextTrackButton(nullptr);
    MediaPlayerModel* m_mplayerModel(nullptr);
};

class Repeat : public RepeatView, public QAbstractButton {
 public:
    Q_SIGNALS:
        void repeatButtonClicked();
 private:
    QPushButton* m_repeatButton(nullptr);
    MediaPlayerModel* m_mplayerModel(nullptr);
};

class Shuffle : public shuffleView, public QAbstractButton {
 public:
    Q_SIGNALS:
        void shuffleButtonClicked();
 private:
    QPushButton* m_shuffleButton(nullptr);
    MediaPlayerModel* m_mplayerModel(nullptr);
};


// class VolumeTrackEditor : public VolumeTrackEditorView {
//  public:
//     Q_SIGNALS:

//  private:
//     Play* m_playButton(nullptr);
//     Stop* m_stopButton(nullptr);
//     Pause* m_pauseButton(nullptr);
//     PreviousTrack* m_previousTrackButton(nullptr);
//     NextTrack* m_nextTrackButton(nullptr);
//     Repeat* m_repeatButton(nullptr);
//     Shuffle* m_shuffleButton(nullptr);
//     Mute* m_muteButton(nullptr);
//     // TODO volume slider // duration bar//
// };

class StatusTrackEditor : public StatusTrackEditorView {
 public:
    Q_SIGNALS:

 private:
    Play* m_playButton(nullptr);
    Stop* m_stopButton(nullptr);
    Pause* m_pauseButton(nullptr);
    PreviousTrack* m_previousTrackButton(nullptr);
    NextTrack* m_nextTrackButton(nullptr);
    Repeat* m_repeatButton(nullptr);
    Shuffle* m_shuffleButton(nullptr);
};

class VolumeTrackEditor : public VolumeTrackEditorView {
 public:
    Q_SIGNALS:

 private:
    Mute* m_muteButton(nullptr);
    VolumeSlider* m_volumeSliderButton(nullptr);
    DurationBar* m_durationBarButton(nullptr);    
};



class CurrentTrack : public CurrentTrackView {
 private:
    StatusTrackEditor* m_statusTrackEditor(nullptr);
    VolumeTrackEditor* m_volumeTrackEditor(nullptr);
};

class Playlist : public QTableView {
 public:
    Q_SIGNALS:
 private:
    QTableWidget* playlist(nullptr);
};

class MediaPlayer : public MediaPlayerView {
 public:
    Q_SINGALS:
 private:
    CurrentTrack* m_currentTrack(nullptr);
    Playlist* m_playlist(nullptr);
};

class MainWindow : public QMainWindow {
 public:
    Q_SIGNALS:
 private:
    QMainWindow* m_window(nullptr);
    MediaPlayer* m_mediaPlayer(nullptr);
};

class MediaPlayerView {

};




class MainWindowView {

};
