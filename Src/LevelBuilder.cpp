//
// Created by SKIKK on 17/11/2023.
//

#include <Components/SpriteComponent.hpp>
#include <algorithm>
#include <Components/TileMapComponent.hpp>
#include <Components/TransformComponent.hpp>
#include "LevelBuilder.hpp"

void LevelBuilder::buildLevel() {
    size_t sortingLayer = objectMap.size() + tileMap.size();
    for (const auto &layer: tileMap) {
        auto tileMapObject = std::make_unique<GameObject>();
        tileMapObject->tryGetComponent<TransformComponent>().scale = std::make_unique<Vector2>(4, 4);
        auto tileMapComponent = std::make_unique<TileMapComponent>();
        tileMapComponent->tileMapPath = "Sprites/roguelikeSheet_transparent_1.bmp";
        tileMapComponent->tileSize = std::make_unique<Vector2>(16, 16);
        tileMapComponent->sortingLayer = sortingLayer;
        tileMapComponent->margin = 1;
        auto map = std::vector<std::vector<std::unique_ptr<Vector2>>>();
        for (const std::string row: layer) {
            auto mapRow = std::vector<std::unique_ptr<Vector2>>();
            for (char tile: row) {
                if (tile == '.') {
                    mapRow.emplace_back(nullptr);
                    continue;
                }
                mapRow.emplace_back(std::make_unique<Vector2>(levelFactory_.getSpriteTileOffset(tile)));
            }
            map.emplace_back(std::move(mapRow));
        }
        tileMapComponent->tileMap = std::move(map);
        tileMapObject->addComponent(std::move(tileMapComponent));
        gameObjects.push_back(std::move(tileMapObject));
        sortingLayer--;
    }

    for (const auto &layer: objectMap) {
        int y = 0;
        for (const std::string &row: layer) {
            int x = 0;
            for (char c: row) {
                if (c == '.') {
                    x++;
                    continue;
                }
                std::unique_ptr<GameObject> object = levelFactory_.createGameObject(c, Vector2(x, y), sortingLayer);
                gameObjects.push_back(std::move(object));
                x++;
            }
            y++;
        }
        sortingLayer--;
    }
}