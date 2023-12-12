//
// Created by Stef van Stipdonk on 12/12/2023.
//

#include "PauseHandler.hpp"
#include "EngineManagers/InputManager.hpp"
#include "Helpers/KeyMap.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "Objects/Button.hpp"

void PauseHandler::onStart() {}

void PauseHandler::onUpdate(milliseconds deltaTime) {
    if (!InputManager::GetInstance().IsKeyClicked(ESCAPE))
        return;


    if (isPaused) {
        ConfigSingleton::GetInstance().deltaTimeMultiplier = previousMultiplier;
        isPaused = false;
        EntityManager::getInstance().setEntityActive(EntityManager::getInstance().getEntityByName("GameParent"), true);
        EntityManager::getInstance().setEntityActive(EntityManager::getInstance().getEntityByName("PauseMenu"), false);

        return;
    }

    EntityManager::getInstance().setEntityActive(EntityManager::getInstance().getEntityByName("GameParent"), false);
    EntityManager::getInstance().setEntityActive(EntityManager::getInstance().getEntityByName("PauseMenu"), true);
    EntityManager::getInstance().setEntityActive(EntityManager::getInstance().getEntityByName("ResumeButton"), true);
    previousMultiplier = ConfigSingleton::GetInstance().deltaTimeMultiplier;
    ConfigSingleton::GetInstance().deltaTimeMultiplier = 0;
    isPaused = true;
}
