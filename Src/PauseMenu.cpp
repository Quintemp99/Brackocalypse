//
// Created by Stef van Stipdonk on 12/12/2023.
//

#include "PauseMenu.hpp"
#include "../Scripts/PauseHandler.hpp"
#include "Helpers/Vector2.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "Components/TransformComponent.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "EngineManagers/SceneManager.hpp"
#include "SaveLoadGame.hpp"
#include <Objects/Button.hpp>

#include "Scenes/LevelManager.hpp"

PauseMenu::PauseMenu() : GameObject() {
    setTag("PauseMenu");
    setName("PauseMenu");
    setActive(false);

    auto centerY = ConfigSingleton::getInstance().getInitialWindowSize().getY() / 2;
    auto centerX = ConfigSingleton::getInstance().getInitialWindowSize().getX() / 2;
    auto buttonSize = Vector2(210, 70);

    auto startButton = std::make_unique<Button>(buttonSize, "Resume");
    startButton->setFontSize(20);
    startButton->setTag("ResumeButton");
    startButton->setName("ResumeButton");
    startButton->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
            obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();
    });

    auto &transformStartButton = startButton->tryGetComponent<TransformComponent>();
    transformStartButton.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                              centerY - (buttonSize.getY() / 2) - 160);

    auto backToMenu = std::make_unique<Button>(buttonSize, "To Main Menu");
    backToMenu->setFontSize(20);
    backToMenu->setTag("ToMainMenu");
    backToMenu->setName("ToMainMenu");
    backToMenu->setClickEvent([]() {
        ConfigSingleton::getInstance().deltaTimeMultiplier = 1.0;
        LevelManager::getInstance().goToSpecificLevel(HOME_SCENE);
    });

    auto &backToMenuTransform = backToMenu->tryGetComponent<TransformComponent>();
    backToMenuTransform.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                             centerY - (buttonSize.getY() / 2) - 80);


    auto speed1x = std::make_unique<Button>(buttonSize, "Speed 1x");
    speed1x->setFontSize(20);
    speed1x->setTag("Speed1x");
    speed1x->setName("Speed1x");
    speed1x->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
            obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();
        ConfigSingleton::getInstance().deltaTimeMultiplier = 1.0;
    });

    auto &transformSpeed2x = speed1x->tryGetComponent<TransformComponent>();
    transformSpeed2x.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                          centerY - (buttonSize.getY() / 2));

    auto speed2x = std::make_unique<Button>(buttonSize, "Speed 2x");
    speed2x->setFontSize(20);
    speed2x->setTag("Speed2x");
    speed2x->setName("Speed2x");
    speed2x->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
            obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();
        ConfigSingleton::getInstance().deltaTimeMultiplier = 2.0;
    });

    auto &transformSpeed1x = speed2x->tryGetComponent<TransformComponent>();
    transformSpeed1x.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                          centerY - (buttonSize.getY() / 2) + 80);

    auto replayButton = std::make_unique<Button>(buttonSize, "Replay");
    replayButton->setFontSize(20);
    replayButton->setTag("ReplayButton");
    replayButton->setName("ReplayButton");
    replayButton->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
            obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();
        ReplayManager::getInstance().toggleReplay();
        ConfigSingleton::getInstance().deltaTimeMultiplier = 1.0;
    });

    auto &transformReplay = replayButton->tryGetComponent<TransformComponent>();
    transformReplay.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                         centerY - (buttonSize.getY() / 2) + 160);

    auto quitButton = std::make_unique<Button>(buttonSize, "Quit game");
    quitButton->setFontSize(20);
    quitButton->setTag("QuitButton");
    quitButton->setName("QuitButton");
    quitButton->setClickEvent([]() {
        ConfigSingleton::getInstance().toggleIsRunning();
    });

    auto &transformQuit = quitButton->tryGetComponent<TransformComponent>();
    transformQuit.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                       centerY - (buttonSize.getY() / 2) + 240);

    auto saveButton = std::make_unique<Button>(buttonSize, "Save game");
    saveButton->setFontSize(20);
    saveButton->setTag("SaveButton");
    saveButton->setName("SaveButton");
    saveButton->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
            obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();

        SaveLoadGame::getInstance().save();
    });

    auto &transformSave = saveButton->tryGetComponent<TransformComponent>();
    transformSave.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                       centerY - (buttonSize.getY() / 2) - 260);

    addChild(std::move(saveButton));
    addChild(std::move(quitButton));
    addChild(std::move(startButton));
    addChild(std::move(speed1x));
    addChild(std::move(backToMenu));
    addChild(std::move(speed2x));
    addChild(std::move(replayButton));
}
