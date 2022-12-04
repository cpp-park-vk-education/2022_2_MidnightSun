#include <string>

const std::string shuffleButton = "shuffle";
const std::string previousTrackButton = "previousTrack";
const std::string playButton = "play";
const std::string nextTrackButton = "nextTrack";
const std::string repeatButton = "repeat";
const std::string muteButton = "mute";
const std::string durationSlider = "durationSlider";
const std::string volumeSlider = "volumeSlider";

enum Status {
    Success,
    Failure
};

enum RepeatFlags {
    None = 0,
    One = 1,
    All = 2
};

class Sender;

struct Mediator {
    virtual void notify(Sender* sender, std::string button = "") = 0;
};

//////////////////////////////////////// Current Track Buttons ////////////////////////////////////////

class Sender {
 public:
    explicit Sender(Mediator *mediator);
 protected:
    Mediator* mediator_;
};

struct DefaultButton : public Sender {
    explicit DefaultButton(Mediator* mediator);
    void click();
};

struct HoverButton : public Sender {
    explicit HoverButton(Mediator* mediator);
    void click();
    bool isClicked();
    void editStatus();
 private:
    bool isClicked_ = false;
};

struct Slider : public Sender {
    explicit Slider(Mediator* mediator);
    void editStatus();
 private:
    size_t position_ = 0;
};

// struct ShuffleButton : public HoverButton {
//     explicit ShuffleButton(Mediator* mediator);
//     void editStatus();
// };

// struct PreviousTrackButton : public DefaultButton {
//     explicit PreviousTrackButton(Mediator* mediator);
//     void editStatus();
// };

// struct PlayButton : public DefaultButton {
//     explicit PlayButton(Mediator* mediator);
//     void editStatus();
// };

// struct NextTrackButton : public DefaultButton {
//     explicit NextTrackButton(Mediator* mediator);
//     void editStatus();
// };

// struct RepeatButton : public HoverButton {
//     explicit RepeatButton(Mediator* mediator);
//     void editStatus();
//  private:
//     RepeatFlags repeatFlags_;
// };

// struct MuteButton : public HoverButton {
//     explicit MuteButton(Mediator* mediator);
//     void editStatus();
// };



// struct DurationSlider : public Slider {
//     explicit DurationSlider(Mediator* mediator);
//     void editStatus();
// };

// struct VolumeSlider : public Slider {
//     explicit VolumeSlider(Mediator* mediator);
//     void editStatus();
// };


//////////////////////////////////////// Current Track UIModel ////////////////////////////////////////

class CurrentTrackUIModel : public Sender {
 public:
    explicit CurrentTrackUIModel(Mediator* mediator);

    Status shuffle();
    Status previousTrack();
    Status play();
    Status nextTrack();
    Status repeat();
    Status mute();
    Status moveDuration();
    Status moveVolume();
 private:
    Mediator* mediator_;
};

//////////////////////////////////////// Current Track Controller ////////////////////////////////////////

class CurrentTrackController : public Sender {
 public:
    explicit CurrentTrackController(Mediator* mediator);

    Status shuffleClicked();
    Status previousTrackClicked();
    Status playClicked();
    Status nextTrackClicked();
    Status repeatClicked();
    Status muteClicked();
    Status durationSliderMoved();
    Status volumeSliderMoved();
 private:
    Mediator* mediator_;
};

//////////////////////////////////////// Current Track View ////////////////////////////////////////

class CurrentTrackView : public Mediator {
 public:
    void notify(Sender* sender, std::string button = "") override;
    void initializeView(CurrentTrackView* view);
 private:
    HoverButton* shuffle_;
    DefaultButton* previousTrack_;
    DefaultButton* play_;
    DefaultButton* nextTrack_;
    HoverButton* repeat_;
    HoverButton* mute_;
    Slider* durationSlider_;
    Slider* volumeSlider_;

    CurrentTrackUIModel* model_;
    CurrentTrackController* controller_;
};
