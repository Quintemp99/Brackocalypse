//
// Created by Stef van Stipdonk on 12/12/2023.
//

#include "PauseHandler.hpp"
#include "EngineManagers/InputManager.hpp"
#include "Helpers/KeyMap.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "Objects/Button.hpp"

void PauseHandler::onStart() {}

void PauseHandler::togglePause() {
    auto gameParent = EntityManager::getInstance().getEntityByName("GameParent");
    auto resumeButton = EntityManager::getInstance().getEntityByName("ResumeButton");
    auto quitButton = EntityManager::getInstance().getEntityByName("QuitButton");
    auto speed2x = EntityManager::getInstance().getEntityByName("Speed2x");
    auto speed1x = EntityManager::getInstance().getEntityByName("Speed1x");
    auto replay = EntityManager::getInstance().getEntityByName("ReplayButton");
    EntityManager::getInstance().setEntityActive(gameParent, !EntityManager::getInstance().isEntityActive(gameParent));
    EntityManager::getInstance().setEntityActive(resumeButton,
                                                 !EntityManager::getInstance().isEntityActive(resumeButton));
    EntityManager::getInstance().setEntityActive(quitButton, !EntityManager::getInstance().isEntityActive(quitButton));
    EntityManager::getInstance().setEntityActive(speed2x, !EntityManager::getInstance().isEntityActive(speed2x));
    EntityManager::getInstance().setEntityActive(speed1x, !EntityManager::getInstance().isEntityActive(speed1x));
    EntityManager::getInstance().setEntityActive(replay, !EntityManager::getInstance().isEntityActive(replay));

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
