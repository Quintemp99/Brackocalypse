#include "SaveLoadGame.hpp"
#include "../Scripts/PlayerProgress.hpp"
#include "Scenes/LevelManager.hpp"
#include "Components/HealthComponent.hpp"
#include <SaveLoad.hpp>
#include <sstream>

const std::string SaveLoadGame::defaultPath{"./save_data.dat"};

SaveLoadGame SaveLoadGame::instance;

bool SaveLoadGame::save() const {
    return save(defaultPath);
}

bool SaveLoadGame::load() const {
    return load(defaultPath);
}

std::string SaveLoadGame::stringifyEnemy(Enemy& enemy) const {
    std::string content;

    auto& transformComp = enemy.tryGetComponent<TransformComponent>();
    auto& position = transformComp.position;
    auto& healthComp = enemy.tryGetComponent<HealthComponent>();

    content += "[";
    content += std::to_string(position->getX()) + ",";
    content += std::to_string(position->getY()) + ",";
    content += std::to_string(enemy.isActive() ? 1 : 0) + ",";
    content += std::to_string(healthComp.health);
    content += "]";

    return content;
}

bool SaveLoadGame::save(const std::string &filePath) const {
    std::string content;

    auto player = SceneManager::getGameObjectByName("Player");
    auto& transformComp = player.value()->tryGetComponent<TransformComponent>();
    auto& position = transformComp.position;
    PlayerProgress& script = player.value()->tryGetBehaviourScript<PlayerProgress>();
    auto& healthComp = player.value()->tryGetComponent<HealthComponent>();

    content += "xPosition: " + std::to_string(position->getX()) + "\n";
    content += "yPosition: " + std::to_string(position->getY()) + "\n";
    content += "beers: " + std::to_string(script.getBeersCollected()) + "\n";
    content += "level: " + std::to_string(LevelManager::getInstance().currentLevel) + "\n";
    content += "health: " + std::to_string(healthComp.health) + "\n";

    auto enemies = SceneManager::getGameObjectsByTag("Enemy");
    content += "enemies: ";
    for(auto& enemy : enemies) {
        auto enemyCast = static_cast<Enemy *>(enemy);
        content += stringifyEnemy(*enemyCast);
    }
    content += "\n";

    try {
        SaveLoad::getInstance().save(filePath, content);
        return true;
    } catch(std::exception exception) {
        Logger::Error("Unable to save file");
        return false;
    }
}
std::vector<std::string> SaveLoadGame::splitString(const std::string& input, char delimiter) const {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(input);
    std::string token;
    while (std::getline(tokenStream, token, delimiter)) {
        // Remove whitespace from each token
        token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
        tokens.push_back(token);
    }
    return tokens;
}

bool SaveLoadGame::load(const std::string &filePath) const {
    try {
        std::map<std::string, std::string> keyValueMap = getLoadData(filePath);

        //Set level
        int level = std::stof(keyValueMap["level"]);
        LevelManager::getInstance().loadLevel(level);

        auto player = GameObjectConverter::getGameObjectByName("Player");

        //Set player position
        auto& transformComp = player.value()->tryGetComponent<TransformComponent>();
        transformComp.position->setX(std::stof(keyValueMap["xPosition"]));
        transformComp.position->setY(std::stof(keyValueMap["yPosition"]));

        //Set player health
        auto& healthComp = player.value()->tryGetComponent<HealthComponent>();
        healthComp.health = std::stoi(keyValueMap["health"]);

        //Set beer progress
        PlayerProgress &script = player.value()->tryGetBehaviourScript<PlayerProgress>();
        script.setBeersCollected(std::stof(keyValueMap["beers"]));

        //Set the zombies
        auto inputEnemy = keyValueMap["enemies"];
        std::vector<std::vector<int>> enemies = convertEnemyData(inputEnemy);

        auto enemyPool = GameObjectConverter::getGameObjectsByTag("Enemy");
        for(int i = 0; i < enemyPool.size(); ++i) {
            auto& enemy = enemyPool[i];

            if(enemies.size() <= i) {
                enemy->setActive(false);
                continue;
            }

            auto enemyItems = enemies[i];

            //Set zombie position
            auto& transformCompEnemy = enemy->tryGetComponent<TransformComponent>();
            transformCompEnemy.position->setX(enemyItems[0]);
            transformCompEnemy.position->setY(enemyItems[1]);
            enemy->setActive(enemyItems[2]);

            //Set zombie health
            auto& zombieHealthComp = enemy->tryGetComponent<HealthComponent>();
            zombieHealthComp.health = enemyItems[3];
        }

        return true;
    } catch(std::exception exception) {
        Logger::Error("Something went wrong trying to load in the data.");
        return false;
    }
}

bool SaveLoadGame::canLoad() const {
    std::ifstream file(defaultPath.c_str());
    return file.good();
}

std::map<std::string, std::string> SaveLoadGame::getLoadData(std::string filePath) const {
    const auto& content = SaveLoad::getInstance().load(filePath);

    std::map<std::string, std::string> keyValueMap;
    std::istringstream lineStream(content);
    std::string line;
    while (std::getline(lineStream, line, '\n')) {
        // Split each line based on colon character and remove whitespace
        std::vector<std::string> tokens = splitString(line, ':');

        // Insert key-value pair into the map
        if (tokens.size() == 2) {
            keyValueMap[tokens[0]] = tokens[1];
        }
    }
    return keyValueMap;
}

std::vector<std::vector<int>> SaveLoadGame::convertEnemyData(std::string enemyData) const {
    enemyData.erase(std::remove(enemyData.begin(), enemyData.end(), '['), enemyData.end());

    std::vector<std::vector<int>> enemies;
    std::istringstream ss(enemyData);
    std::string arrayString;

    // Split the string by "][" and store each array string in the vector
    while (std::getline(ss, arrayString, ']')) {
        if (!arrayString.empty()) {
            //Toke
            std::istringstream ss(arrayString);
            std::string arrayItemString;
            std::vector<int> array;

            while (std::getline(ss, arrayItemString, ',')) {
                if (!arrayItemString.empty()) {
                    array.push_back(std::stoi(arrayItemString));
                }
            }
            enemies.push_back(array);
        }
    }

    return enemies;
}
