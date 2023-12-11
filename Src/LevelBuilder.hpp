//
// Created by SKIKK on 17/11/2023.
//

#ifndef BRACKOCALYPSE_LEVELBUILDER_HPP
#define BRACKOCALYPSE_LEVELBUILDER_HPP


#include <vector>
#include <Objects/GameObject.hpp>
#include <Helpers/Vector2.hpp>
#include "Helpers/RogueLikeSheetMap.hpp"
#include "Factory/LevelFactory.hpp"

class LevelBuilder {
public:
    LevelBuilder(std::vector<std::vector<std::string>> objectMap, std::vector<std::vector<std::string>> tileMap,
                 std::vector<std::string> collisionMap)
            : objectMap(objectMap), tileMap(tileMap), collisionMap(collisionMap) {
        auto bottomLayer = objectMap[0];
        auto firstRow = bottomLayer[0];
        auto size = Vector2(firstRow.size(), bottomLayer.size());
        size_ = size;
        tileMapSize = Vector2(tileMap[0][0].size(), tileMap[0].size());
        levelFactory_.setSize(size_);
    }

    ~LevelBuilder() = default;

    void buildLevel();

    std::vector<std::unique_ptr<GameObject>> gameObjects;
private:
    Vector2 size_ = Vector2(0, 0);
    Vector2 tileMapSize = Vector2(0, 0);
    std::vector<std::vector<std::string>> objectMap;
    std::vector<std::vector<std::string>> tileMap;
    std::vector<std::string> collisionMap;
    LevelFactory levelFactory_ = LevelFactory();
};


#endif //BRACKOCALYPSE_LEVELBUILDER_HPP
