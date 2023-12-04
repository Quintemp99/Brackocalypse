//
// Created by SKIKK on 17/11/2023.
//

#include <Components/SpriteComponent.hpp>
#include <algorithm>
#include "LevelBuilder.hpp"

void LevelBuilder::buildLevel() {
    size_t sortingLayer = map.size();
    for (const auto& layer: map) {
        int y = 0;
        for (const std::string& row : layer) {
            int x = 0;
            for (char c : row) {
                if(c == '.') { x++; continue;}
                std::unique_ptr<GameObject> object = levelFactory_.createGameObject(c,Vector2(x,y), sortingLayer);
                gameObjects.push_back(std::move(object));
                x++;
            }
            y++;
        }
        sortingLayer--;
    }
}