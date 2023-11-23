//
// Created by SKIKK on 17/11/2023.
//

#ifndef BRACKOCALYPSE_LEVELBUILDER_HPP
#define BRACKOCALYPSE_LEVELBUILDER_HPP


#include <vector>
#include <Objects/GameObject.hpp>

class LevelBuilder {
public:
    LevelBuilder(std::vector<std::vector<std::string>> map) : map(map) {}
    ~LevelBuilder() = default;
    void buildLevel();
private:
    std::vector<std::vector<std::string>> map;
    std::vector<GameObject> gameObjects;
};


#endif //BRACKOCALYPSE_LEVELBUILDER_HPP
