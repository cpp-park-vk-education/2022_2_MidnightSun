#include "InterfaceButtons.hpp"

IButton::IButton(QWidget* parent) 
    : button_(new QPushButton(parent)) {}

IButton::~IButton() {

}

void IButton::setStyle(int buttonX, int buttonY,
                       int buttonWidth, int buttonHeight,
                       const char* buttonName) {
    button_->setObjectName(buttonName);
    button_->setGeometry(QRect(buttonX, buttonY, 
                               buttonWidth, buttonHeight));
}
