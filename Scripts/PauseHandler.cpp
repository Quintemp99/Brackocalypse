//
// Created by Stef van Stipdonk on 12/12/2023.
//

#include "PauseHandler.hpp"
#include "EngineManagers/InputManager.hpp"
#include "Helpers/KeyMap.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "Objects/Button.hpp"
#include "EngineManagers/SceneManager.hpp"

void PauseHandler::onStart() {}

void PauseHandler::togglePause() {

    auto gameParent = getGameObjectByName("GameParent");
    auto pauseMenu = getGameObjectByName("PauseMenu");

    if (gameParent.has_value())
        gameParent.value()->setActive(!gameParent.value()->isActive());

    if (pauseMenu.has_value())
        pauseMenu.value()->setActive(!pauseMenu.value()->isActive());

//    auto resumeButton = getGameObjectByName("ResumeButton");
//    auto quitButton = getGameObjectByName("QuitButton");
//    auto speed2x = getGameObjectByName("Speed2x");
//    auto speed1x = getGameObjectByName("Speed1x");
//    auto replay = getGameObjectByName("ReplayButton");
//
//    if (gameParent.has_value())
//        gameParent.value()->setActive(!gameParent.value()->isActive());
//
//    if (resumeButton.has_value())
//        resumeButton.value()->setActive(!resumeButton.value()->isActive());
//
//    if (quitButton.has_value())
//        quitButton.value()->setActive(!quitButton.value()->isActive());
//
//    if (speed2x.has_value())
//        speed2x.value()->setActive(!speed2x.value()->isActive());
//
//    if (speed1x.has_value())
//        speed1x.value()->setActive(!speed1x.value()->isActive());
//
//    if (replay.has_value())
//        replay.value()->setActive(!replay.value()->isActive());

    bool isCurrentlyPaused = ConfigSingleton::GetInstance().deltaTimeMultiplier == 0.0;

    if (isCurrentlyPaused) {
        // Unpause: Restore the saved multiplier
        ConfigSingleton::GetInstance().deltaTimeMultiplier = previousMultiplier;
    } else {
        // Pause: Save the current multiplier and set it to 0
        previousMultiplier = ConfigSingleton::GetInstance().deltaTimeMultiplier;
        ConfigSingleton::GetInstance().deltaTimeMultiplier = 0.0;
    }
}

void PauseHandler::onUpdate(milliseconds deltaTime) {
    if (!InputManager::GetInstance().IsKeyClicked(ESCAPE))
        return;

    togglePause();
}
