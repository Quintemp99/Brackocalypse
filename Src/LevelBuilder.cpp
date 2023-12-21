//
// Created by SKIKK on 17/11/2023.
//

#include <Components/SpriteComponent.hpp>
#include <algorithm>
#include <Components/TileMapComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Graph/GraphNode.hpp>
#include <Objects/Graph.hpp>
#include "LevelBuilder.hpp"
#include "Components/BoxCollisionComponent.hpp"
#include "Components/RigidBodyComponent.hpp"
#include "Components/SpawnComponent.hpp"
#include <EngineManagers/CollisionLayerManager.hpp>

void LevelBuilder::buildLevel() {
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
    auto enemySpawnerObject = std::make_unique<GameObject>();
    auto enemySpawnComponent = std::make_unique<SpawnComponent>();
    enemySpawnerObject->setTag("EnemySpawner");

    auto beerSpawnerObject = std::make_unique<GameObject>();
    auto beerSpawnComponent = std::make_unique<SpawnComponent>();
    beerSpawnerObject->setTag("BeerSpawner");

    std::vector<std::vector<GraphNode *>> twoDGraphGrid;
    std::vector<std::unique_ptr<GraphNode>> nodes;

    for (int y = 0; y < collisionMap.size(); ++y) {
        twoDGraphGrid.push_back({});
        for (int x = 0; x < collisionMap[y].size(); ++x) {
            auto location = std::make_unique<Vector2>(x * tileSize.getX() * tileScale.getX() -
                                                      tileMapSize.getX() * tileScale.getX() *
                                                      tileSize.getX() / 2 +
                                                      tileSize.getX() * tileScale.getX() / 2,
                                                      y * tileSize.getY() * tileScale.getY() -
                                                      tileMapSize.getY() * tileScale.getY() *
                                                      tileSize.getY() / 2 +
                                                      tileSize.getY() * tileScale.getY() / 2);

            if (collisionMap[y][x] != '.' && collisionMap[y][x] != 'x' && collisionMap[y][x] != 'X') {
                nodes.push_back(std::make_unique<GraphNode>(*location));
                twoDGraphGrid.back().push_back(nodes.back().get());
            } else {
                twoDGraphGrid.back().push_back(nullptr);
            }

            if (collisionMap[y][x] == 'B') {
                beerSpawnComponent->availableSpawnLocations.emplace_back(std::make_unique<Vector2>(*location));
            }

            if (collisionMap[y][x] == 'E') {
                enemySpawnComponent->availableSpawnLocations.emplace_back(std::make_unique<Vector2>(*location));
            }

            if (collisionMap[y][x] != 'x' && collisionMap[y][x] != 'X') {
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
                if (collisionMap[y][x] == 'x')
                    addCollisionObject(width, height, x, y, "Wall");
                else if (collisionMap[y][x] == 'X')
                    addCollisionObject(width, height, x, y, "SolidWall");
                continue;
            }


            while (y + height < collisionMap.size() && collisionMap[y + height][x] == collisionMap[y][x]) {
                height++;
            }

            for (int i = 0; i < height; ++i)
                collisionMap[y + i][x] = '.';

            if (collisionMap[y][x] == 'x')
                addCollisionObject(width, height, x, y, "Wall");
            else if (collisionMap[y][x] == 'X')
                addCollisionObject(width, height, x, y, "SolidWall");
        }
    }

    for (int y = 0; y < twoDGraphGrid.size(); ++y) {
        for (int x = 0; x < twoDGraphGrid[y].size(); ++x) {
            auto &node = twoDGraphGrid[y][x];
            if (node != nullptr) {
                if (twoDGraphGrid[y - 1][x] != nullptr) {
                    auto edge = std::make_unique<GraphEdge>(twoDGraphGrid[y - 1][x], node, 1);
                    node->addEdge(std::move(edge));
                }

                if (twoDGraphGrid[y][x + 1] != nullptr) {
                    auto edge = std::make_unique<GraphEdge>(twoDGraphGrid[y][x + 1], node, 1);
                    node->addEdge(std::move(edge));
                }

                if (twoDGraphGrid[y + 1][x] != nullptr) {
                    auto edge = std::make_unique<GraphEdge>(twoDGraphGrid[y + 1][x], node, 1);
                    node->addEdge(std::move(edge));
                }

                if (twoDGraphGrid[y][x - 1] != nullptr) {
                    auto edge = std::make_unique<GraphEdge>(twoDGraphGrid[y][x - 1], node, 1);
                    node->addEdge(std::move(edge));
                }
            }
        }
    }

    auto graph = std::make_unique<Graph>(std::move(nodes));
    graph->setName("MainGraph");
    gameObjects.push_back(std::move(graph));

    enemySpawnerObject->addComponent(std::move(enemySpawnComponent));
    gameObjects.push_back(std::move(enemySpawnerObject));

    beerSpawnerObject->addComponent(std::move(beerSpawnComponent));
    gameObjects.push_back(std::move(beerSpawnerObject));

}

void LevelBuilder::addCollisionObject(int width, int height, int x, int y, std::string category) {
    auto collisionObject = std::make_unique<GameObject>();
    collisionObject->setTag("Collision");
    auto boxCollision = std::make_unique<BoxCollisionComponent>(
            tileSize * tileScale * Vector2(width, height));
    collisionObject->addComponent(std::move(boxCollision));
    auto rigidBody = std::make_unique<RigidBodyComponent>(CollisionType::STATIC);
    rigidBody->restitution = 1.0f;
    rigidBody->collisionCategory = CollisionLayerManager::getInstance().getCategory(category);
    rigidBody->collisionMask = CollisionLayerManager::getInstance().getMask(category);
    collisionObject->addComponent(std::move(rigidBody));
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

