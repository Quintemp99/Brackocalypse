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
