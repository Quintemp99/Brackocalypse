//
// Created by stijn on 18-12-2023.
//

#ifndef BRACKOCALYPSE_LEVELMANAGER_HPP
#define BRACKOCALYPSE_LEVELMANAGER_HPP


class LevelManager {
public:
    static LevelManager &getInstance();
    ~LevelManager() = default;
    LevelManager(const LevelManager &) = delete;
    LevelManager &operator=(const LevelManager &) = delete;
    LevelManager(LevelManager &&) = delete;
    LevelManager &operator=(LevelManager &&) = delete;

    int currentScene = 0;
    void goToLevel();
    void goToNextLevel();
    void goToSpecificLevel(int level);
    void loadLevel(int level);
    void startLoop();
private:
    LevelManager();
    static LevelManager instance;
    static const int MAX_LEVELS = 6;
};


#endif //BRACKOCALYPSE_LEVELMANAGER_HPP
