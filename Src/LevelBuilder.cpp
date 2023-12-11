//
// Created by SKIKK on 17/11/2023.
//

#include <Components/SpriteComponent.hpp>
#include <algorithm>
#include <Components/TileMapComponent.hpp>
#include <Components/TransformComponent.hpp>
#include "LevelBuilder.hpp"
#include "Components/BoxCollisionComponent.hpp"
#include "Components/RigidBodyComponent.hpp"

void LevelBuilder::buildLevel() {
    auto tileSize = Vector2(16, 16);
    auto tileScale = Vector2(4, 4);
    size_t sortingLayer = tileMap.size();
    for (const auto &layer: tileMap) {
        auto tileMapObject = std::make_unique<GameObject>();
        tileMapObject->tryGetComponent<TransformComponent>().scale = std::make_unique<Vector2>(tileScale);
        auto tileMapComponent = std::make_unique<TileMapComponent>();
        tileMapComponent->tileMapPath = "Sprites/roguelikeSheet_transparent_1.bmp";
        tileMapComponent->tileSize = std::make_unique<Vector2>(tileSize);
        tileMapComponent->sortingLayer = sortingLayer;
        tileMapComponent->orderInLayer = 0;
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

    sortingLayer = objectMap.size();

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

    for (int y = 0; y < collisionMap.size(); ++y) {
        for (int x = 0; x < collisionMap[y].size(); ++x) {
            if (collisionMap[y][x] != 'x') {
                continue;
            }

            int width = 1;
            int height = 1;
            while (x + width < collisionMap[y].size() && collisionMap[y][x + width] == collisionMap[y][x]) {
                width++;
            }

            if (width > 1) {
                for (int i = 0; i < width; ++i)
                    collisionMap[y][x + i] = '.';

                auto collisionObject = std::make_unique<GameObject>();
                auto boxCollision = std::make_unique<BoxCollisionComponent>(
                        tileSize * tileScale * Vector2(width, height));
                collisionObject->addComponent(std::move(boxCollision));
                collisionObject->addComponent(std::make_unique<RigidBodyComponent>(CollisionType::STATIC));
                auto &transform = collisionObject->tryGetComponent<TransformComponent>();
                float posX = x * tileSize.getX() * tileScale.getX() -
                             tileMapSize.getX() * tileScale.getX() * tileSize.getX() / 2 +
                             tileSize.getX() * tileScale.getX() * width / 2;
                float posY = y * tileSize.getY() * tileScale.getY() -
                             tileMapSize.getY() * tileScale.getY() * tileSize.getY() / 2 +
                             tileSize.getY() * tileScale.getY() * height / 2;
                transform.position = std::make_unique<Vector2>(posX, posY);
                gameObjects.push_back(std::move(collisionObject));
                continue;
            }


            while (y + height < collisionMap.size() && collisionMap[y + height][x] == collisionMap[y][x]) {
                height++;
            }

            for (int i = 0; i < height; ++i)
                collisionMap[y + i][x] = '.';

            auto collisionObject = std::make_unique<GameObject>();
            auto boxCollision = std::make_unique<BoxCollisionComponent>(
                    tileSize * tileScale * Vector2(width, height));
            collisionObject->addComponent(std::move(boxCollision));
            collisionObject->addComponent(std::make_unique<RigidBodyComponent>(CollisionType::STATIC));
            auto &transform = collisionObject->tryGetComponent<TransformComponent>();
            float posX = x * tileSize.getX() * tileScale.getX() -
                         tileMapSize.getX() * tileScale.getX() * tileSize.getX() / 2 +
                         tileSize.getX() * tileScale.getX() * width / 2;
            float posY = y * tileSize.getY() * tileScale.getY() -
                         tileMapSize.getY() * tileScale.getY() * tileSize.getY() / 2 +
                         tileSize.getY() * tileScale.getY() * height / 2;
            transform.position = std::make_unique<Vector2>(posX, posY);
            gameObjects.push_back(std::move(collisionObject));
        }
    }
}