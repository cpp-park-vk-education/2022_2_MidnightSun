#pragma once

enum Function {
// Значения, указывающие какие функции нужно стриггерить у UI моделей
    Shuffle,
    PreviousTrack,
    NextTrack,
    Repeat,
    DurationEnd,
    ChooseTrack
};

enum Status {
    Success,
    Failure
};

class Sender;

struct Mediator {
    virtual void notify(Sender* sender, Function function) = 0;
};

class Sender {
 public:
    explicit Sender(Mediator *mediator);
 protected:
    Mediator* mediator_;
};