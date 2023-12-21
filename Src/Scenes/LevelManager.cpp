//
// Created by stijn on 18-12-2023.
//

#include "LevelManager.hpp"
#include <EngineManagers/SceneManager.hpp>
#include "EndScene.hpp"
#include "InterludeOneScene.hpp"
#include "IntroductionScene.hpp"
#include "InterludeTwoScene.hpp"
#include "InterludeThreeScene.hpp"
#include "HomeScene.hpp"
#include "Levels/BossLevel.hpp"
#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"

LevelManager LevelManager::instance;

LevelManager &LevelManager::getInstance() {
    return instance;
}

void LevelManager::goToNextLevel() {
    if (currentScene >= MAX_LEVELS)
        currentScene = 0;
    else
        ++currentScene;

    goToLevel();
}

void LevelManager::goToLevel() {
    Scene *level = nullptr;

    switch (currentScene) {
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
            level = new SecondLevel();
            break;
        case 5:
            level = new InterludeTwoScene();
            break;
        case 6:
            level = new InterludeThreeScene();
            break;
        case 7:
            level = new BossLevel();
            break;
        case 8:
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
    currentScene = level;
    goToLevel();
}

void LevelManager::loadLevel(int level) {
    goToSpecificLevel(level);
    SceneManager::getInstance().setActiveScene();
}

LevelManager::LevelManager() {
    currentScene = 0;
}

void LevelManager::startLoop() {
    currentScene = 0;
    goToLevel();
}
