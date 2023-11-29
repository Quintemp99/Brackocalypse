#ifndef BRACKOCALYPSE_STARTBUTTON_HPP
#define BRACKOCALYPSE_STARTBUTTON_HPP
#include <Objects/Button.hpp>
#include <Helpers/Vector2.hpp>

class StartButton : public Button {
public:
    StartButton() : Button(Vector2(50,50), "Start game") {
        SetFontSize(24);
        SetClickEvent([this](){

        });
    }
};

#endif