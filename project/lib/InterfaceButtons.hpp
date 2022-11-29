#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

class IButton : public QMainWindow {

 Q_OBJECT
 public:   
    friend class CurrentTrackView;
    explicit IButton(QWidget* parent = nullptr);
    ~IButton();

    void setStyle(int button_x, int button_y,
                  int button_width, int button_height,
                  const char* path);
 private:
    QPushButton* button_;
};
