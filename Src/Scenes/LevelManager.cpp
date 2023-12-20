//
// Created by stijn on 18-12-2023.
//

#include "LevelManager.hpp"
#include <EngineManagers/SceneManager.hpp>
#include "./Levels/FirstLevel.hpp"
#include "EndScreen.hpp"

LevelManager LevelManager::instance;

LevelManager &LevelManager::getInstance() {
    return instance;
}

void LevelManager::goToNextLevel() {
    ++currentLevel;
    goToLevel();
}

void LevelManager::goToLevel() {
    switch(currentLevel) {
        case 1:
            SceneManager::getInstance().goToNewScene(new FirstLevel());
            break;
        default:
            SceneManager::getInstance().goToNewScene(new EndScreen());
            break;
    }
}

void LevelManager::goToSpecificLevel(int level) {
    currentLevel = level;
    goToLevel();
}
