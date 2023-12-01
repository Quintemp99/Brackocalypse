//
// Created by SKIKK on 17/11/2023.
//

#ifndef BRACKOCALYPSE_LEVELBUILDER_HPP
#define BRACKOCALYPSE_LEVELBUILDER_HPP


#include <vector>
#include <Objects/GameObject.hpp>
#include <Helpers/Vector2.hpp>
#include "RogueLikeSheetMap.hpp"
#include "Factory/LevelFactory.hpp"

class LevelBuilder {
public:
    LevelBuilder(std::vector<std::vector<std::string>> map) : map(map) {
        auto bottomLayer = map[0];
        auto firstRow = bottomLayer[0];
        auto size = Vector2(firstRow.size(),bottomLayer.size());
        size_ = size;
        levelFactory_.setSize(size_);
    }
    ~LevelBuilder() = default;
    void buildLevel();
    std::vector<std::unique_ptr<GameObject>> gameObjects;
private:
    Vector2 size_;
    std::vector<std::vector<std::string>> map;
    LevelFactory levelFactory_ = LevelFactory();
};


#endif //BRACKOCALYPSE_LEVELBUILDER_HPP
