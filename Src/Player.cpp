//
// Created by SKIKK on 17/11/2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Helpers/Vector2.hpp>
#include <Components/CircleCollisionComponent.hpp>
#include "Player.hpp"
#include "../Scripts/UserInputMovement.hpp"
#include "../Scripts/BlockPlayer.hpp"
#include "Components/BoxCollisionComponent.hpp"

Player::Player(size_t layer) : GameObject() {
    AddComponent(std::make_unique<VelocityComponent>());
    AddComponent(std::make_unique<UserInputMovement>());
    AddComponent(std::make_unique<BlockPlayer>());
    auto sprite = std::make_unique<SpriteComponent>();
    auto collision = std::make_unique<BoxCollisionComponent>(Vector2(16, 16));
    auto &transform = tryGetComponent<TransformComponent>();
    sprite->spritePath = "Sprites/FullSpritesheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(16, 16);
    sprite->margin = 4;
    sprite->sortingLayer = layer;
    transform.scale = std::make_unique<Vector2>(5, 5);
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);
    collision->collisionType = CollisionType::DYNAMIC;
    AddComponent(std::move(sprite));
    AddComponent(std::move(collision));
    SetTag("Player");
}
