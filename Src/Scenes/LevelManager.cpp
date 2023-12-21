//
// Created by stijn on 18-12-2023.
//

#include "LevelManager.hpp"
#include <EngineManagers/SceneManager.hpp>
#include "./Levels/FirstLevel.hpp"
#include "EndScene.hpp"
#include "InterludeOneScene.hpp"
#include "IntroductionScene.hpp"
#include "InterludeTwoScene.hpp"
#include "InterludeThreeScene.hpp"
#include "HomeScene.hpp"

LevelManager LevelManager::instance;

LevelManager &LevelManager::getInstance() {
    return instance;
}

void LevelManager::goToNextLevel() {
    if(currentLevel >= MAX_LEVELS)
        currentLevel = 0;
    else
        ++currentLevel;

    goToLevel();
}

void LevelManager::goToLevel() {
    Scene* level = nullptr;

    switch(currentLevel) {
        case 1:
            level = new IntroductionScene();
            break;
        case 2:
            level = new FirstLevel();
            break;
        case 3:
            level = new InterludeOneScene();
            break;
        case 4:
            level = new InterludeTwoScene();
            break;
        case 5:
            level = new InterludeThreeScene();
            break;
        case 6:
            level = new EndScene();
            break;
        default:
            level = new HomeScene();
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

LevelManager::LevelManager() {
    currentLevel = 0;
}

void LevelManager::startLoop() {
    currentLevel = 0;
    goToLevel();
}
