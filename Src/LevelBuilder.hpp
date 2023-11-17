//
// Created by SKIKK on 17/11/2023.
//

#ifndef BRACKOCALYPSE_LEVELBUILDER_HPP
#define BRACKOCALYPSE_LEVELBUILDER_HPP


#include <vector>
#include <Objects/GameObject.hpp>

class LevelBuilder {
public:
    LevelBuilder() = default;
    ~LevelBuilder() = default;
    void buildLevel(std::vector<std::vector<std::string>>);
private:
    std::vector<GameObject> gameObjects;
};


#endif //BRACKOCALYPSE_LEVELBUILDER_HPP
