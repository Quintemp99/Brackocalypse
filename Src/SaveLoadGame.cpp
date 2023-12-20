#include "SaveLoadGame.hpp"
#include "../Scripts/PlayerProgress.hpp"
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

    content += "[";
    content += std::to_string(position->getX()) + ",";
    content += std::to_string(position->getY());
    content += "]";

    return content;
}

bool SaveLoadGame::save(const std::string &filePath) const {
    std::string content;

    auto player = SceneManager::getGameObjectByName("Player");
    auto& transformComp = player.value()->tryGetComponent<TransformComponent>();
    auto& position = transformComp.position;
    PlayerProgress& script = player.value()->tryGetBehaviourScript<PlayerProgress>();

    content += "xPosition: " + std::to_string(position->getX()) + "\n";
    content += "yPosition: " + std::to_string(position->getY()) + "\n";
    content += "beers: " + std::to_string(script.getBeersCollected()) + "\n";

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

        auto player = GameObjectConverter::getGameObjectByName("Player");
        auto& transformComp = player.value()->tryGetComponent<TransformComponent>();
        transformComp.position->setX(std::stof(keyValueMap["xPosition"]));
        transformComp.position->setY(std::stof(keyValueMap["yPosition"]));

        PlayerProgress& script = player.value()->tryGetBehaviourScript<PlayerProgress>();
        script.setBeersCollected(std::stof(keyValueMap["beers"]));

        auto enemieContent = keyValueMap["enemies"];

        return true;
    } catch(std::exception exception) {
        Logger::Error("Unable to load file");
        return false;
    }
}
