#ifndef BRACKOCALYPSE_SAVELOADGAME_HPP
#define BRACKOCALYPSE_SAVELOADGAME_HPP

#include "BrackEngine.hpp"
#include "Enemy.hpp"

class SaveLoadGame {
public:
    ~SaveLoadGame() = default;
    SaveLoadGame(const SaveLoadGame &) = delete;
    SaveLoadGame &operator=(const SaveLoadGame &) = delete;
    SaveLoadGame(SaveLoadGame &&) = delete;
    SaveLoadGame &operator=(SaveLoadGame &&) = delete;

    static SaveLoadGame &getInstance() {
        return instance;
    }

    bool save() const;
    bool load() const;
    bool save(const std::string& filePath) const;
    bool load(const std::string& filePath) const;

    bool canLoad() const;
private:
    SaveLoadGame() = default;
    static SaveLoadGame instance;
    static const std::string defaultPath;

    //Generic help functions
    std::vector<std::string> splitString(const std::string& input, char delimiter) const;
    std::map<std::string, std::string> getLoadData(std::string filePath) const;
    std::vector<std::vector<int>> convertArray(std::string contentData) const;

    //Specefic help functions
    std::string stringifyEnemy(Enemy& enemy) const;
};


#endif //BRACKOCALYPSE_SAVELOADGAME_HPP
