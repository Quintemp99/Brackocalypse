//
// Created by stijn on 18-12-2023.
//

#ifndef BRACKOCALYPSE_LEVELMANAGER_HPP
#define BRACKOCALYPSE_LEVELMANAGER_HPP
#include "SceneType.hpp"


class LevelManager {
public:
    static LevelManager &getInstance();

    ~LevelManager() = default;

    LevelManager(const LevelManager &) = delete;

    LevelManager &operator=(const LevelManager &) = delete;

    LevelManager(LevelManager &&) = delete;

    LevelManager &operator=(LevelManager &&) = delete;

    SceneType currentSceneType;

    void goToLevel();

    void goToSpecificLevel(SceneType type);

    void loadLevel(SceneType type);

    LevelManager();

    void startLoop(SceneType type);

    void goToNextLevel();

private:
    static LevelManager instance;
    static const int MAX_LEVELS = 6;
};


#endif //BRACKOCALYPSE_LEVELMANAGER_HPP
