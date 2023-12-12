//
// Created by Stef van Stipdonk on 12/12/2023.
//

#include "PauseMenu.hpp"
#include "../Scripts/PauseHandler.hpp"
#include "Helpers/Vector2.hpp"
#include <Objects/Button.hpp>

PauseMenu::PauseMenu() : GameObject() {
    setTag("PauseMenu");
    setName("PauseMenu");
    setActive(false);

    addBehaviourScript(std::make_unique<PauseHandler>());

    auto startButton = std::make_unique<Button>(Vector2(210, 70), "Resume game");
    startButton->setFontSize(40);
    startButton->setTag("ResumeButton");
    startButton->setName("ResumeButton");
    addChild(std::move(startButton));
}