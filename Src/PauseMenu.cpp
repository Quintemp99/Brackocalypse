//
// Created by Stef van Stipdonk on 12/12/2023.
//

#include "PauseMenu.hpp"
#include "../Scripts/PauseHandler.hpp"
#include "Helpers/Vector2.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "Components/TransformComponent.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include <Objects/Button.hpp>

PauseMenu::PauseMenu() : GameObject() {
    setTag("PauseMenu");
    setName("PauseMenu");
    setActive(false);

    auto pauseHandler = std::make_unique<PauseHandler>();
    PauseHandler *pauseHandlerPtr = pauseHandler.get();
    addBehaviourScript(std::move(pauseHandler));

    auto centerY = ConfigSingleton::GetInstance().GetWindowSize().getY() / 2;
    auto centerX = ConfigSingleton::GetInstance().GetWindowSize().getX() / 2;
    auto buttonSize = Vector2(210, 70);

    auto startButton = std::make_unique<Button>(buttonSize, "Resume game");
    startButton->setFontSize(40);
    startButton->setTag("ResumeButton");
    startButton->setName("ResumeButton");
    startButton->setClickEvent([pauseHandlerPtr]() {
        pauseHandlerPtr->togglePause();
    });

    auto &transformStartButton = startButton->tryGetComponent<TransformComponent>();
    transformStartButton.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                              centerY - (buttonSize.getY() / 2) - 80);


    auto speed1x = std::make_unique<Button>(buttonSize, "Speed 1x");
    speed1x->setFontSize(40);
    speed1x->setTag("Speed1x");
    speed1x->setName("Speed1x");
    speed1x->setClickEvent([pauseHandlerPtr]() {
        pauseHandlerPtr->togglePause();
        ConfigSingleton::GetInstance().deltaTimeMultiplier = 1.0;
    });

    auto &transformSpeed2x = speed1x->tryGetComponent<TransformComponent>();
    transformSpeed2x.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                          centerY - (buttonSize.getY() / 2));

    auto speed2x = std::make_unique<Button>(buttonSize, "Speed 2x");
    speed2x->setFontSize(40);
    speed2x->setTag("Speed2x");
    speed2x->setName("Speed2x");
    speed2x->setClickEvent([pauseHandlerPtr]() {
        pauseHandlerPtr->togglePause();
        ConfigSingleton::GetInstance().deltaTimeMultiplier = 2.0;
    });

    auto &transformSpeed1x = speed2x->tryGetComponent<TransformComponent>();
    transformSpeed1x.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                          centerY - (buttonSize.getY() / 2) + 80);

    auto replayButton = std::make_unique<Button>(buttonSize, "Replay");
    replayButton->setFontSize(40);
    replayButton->setTag("ReplayButton");
    replayButton->setName("ReplayButton");
    replayButton->setClickEvent([pauseHandlerPtr]() {
        pauseHandlerPtr->togglePause();
        ReplayManager::getInstance().toggleReplay();
        ConfigSingleton::GetInstance().deltaTimeMultiplier = 1.0;
    });

    auto &transformReplay = replayButton->tryGetComponent<TransformComponent>();
    transformReplay.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                         centerY - (buttonSize.getY() / 2) + 160);

    auto quitButton = std::make_unique<Button>(buttonSize, "Quit game");
    quitButton->setFontSize(40);
    quitButton->setTag("QuitButton");
    quitButton->setName("QuitButton");
    quitButton->setClickEvent([]() {
        ConfigSingleton::GetInstance().ToggleIsRunning();
    });

    auto &transformQuit = quitButton->tryGetComponent<TransformComponent>();
    transformQuit.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                       centerY - (buttonSize.getY() / 2) + 240);

    addChild(std::move(quitButton));
    addChild(std::move(startButton));
    addChild(std::move(speed1x));
    addChild(std::move(speed2x));
    addChild(std::move(replayButton));
}