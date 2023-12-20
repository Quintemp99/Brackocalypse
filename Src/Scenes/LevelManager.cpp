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

void LevelManager::goToLevel() {
    Scene* level = nullptr;

    switch(currentLevel) {
        case 1:
            level = new FirstLevel();
            break;
        default:
            level = new EndScene();
            break;
    }

    level->build();
    SceneManager::getInstance().goToNewScene(level);
}

void LevelManager::goToSpecificLevel(int level) {
    currentLevel = level;
    goToLevel();
}

void LevelManager::loadLevel(int level) {
    goToSpecificLevel(level);
    SceneManager::getInstance().setActiveScene();
}
