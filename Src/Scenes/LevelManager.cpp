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
#include "SceneType.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "Levels/BossLevel.hpp"
#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"

LevelManager LevelManager::instance;

LevelManager &LevelManager::getInstance() {
    return instance;
}

void LevelManager::goToNextLevel() {
    if (currentSceneType < END_SCENE) {
        currentSceneType = static_cast<SceneType>(currentSceneType + 1);
    } else
        currentSceneType = HOME_SCENE;

    goToLevel();
}

void LevelManager::goToLevel() {
    Scene *level = nullptr;

    ReplayManager::getInstance().stopRecording();

    switch (currentSceneType) {
        case INTRODUCTION_SCENE:
            level = new IntroductionScene();
            break;
        case FIRST_LEVEL:
            level = new FirstLevel();
            break;
        case INTERLUDE_ONE_SCENE:
            level = new InterludeOneScene();
            break;
        case SECOND_LEVEL:
            level = new SecondLevel();
            break;
        case INTERLUDE_THREE_SCENE:
            level = new InterludeThreeScene();
            break;
        case BOSS_LEVEL:
            level = new BossLevel();
            break;
        case END_SCENE:
            level = new EndScene();
            break;
            break;
        default:
            level = new HomeScene();
            break;
    }

    level->build();
    SceneManager::getInstance().goToNewScene(level);
}

void LevelManager::goToSpecificLevel(SceneType type) {
    currentSceneType = type;
    goToLevel();
}

void LevelManager::loadLevel(SceneType type) {
    goToSpecificLevel(type);
    SceneManager::getInstance().setActiveScene();
}

LevelManager::LevelManager() {
    currentSceneType = HOME_SCENE;
}

void LevelManager::startLoop(SceneType type) {
    currentSceneType = type;
    goToLevel();
}
