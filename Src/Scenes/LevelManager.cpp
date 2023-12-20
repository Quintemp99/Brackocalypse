//
// Created by stijn on 18-12-2023.
//

#include "LevelManager.hpp"
#include <EngineManagers/SceneManager.hpp>
#include "./Levels/FirstLevel.hpp"
#include "EndScene.hpp"

LevelManager LevelManager::instance;

LevelManager &LevelManager::getInstance() {
    return instance;
}

void LevelManager::goToNextLevel() {
    ++currentLevel;
    goToLevel();
}

void LevelManager::goToLevel(bool goDirectly) {
    switch(currentLevel) {
        case 1:
            SceneManager::getInstance().goToNewScene(new FirstLevel(), goDirectly);
            break;
        default:
            SceneManager::getInstance().goToNewScene(new EndScene(), goDirectly);
            break;
    }
}

void LevelManager::goToSpecificLevel(int level, bool goDirectly) {
    currentLevel = level;
    goToLevel(goDirectly);
}
