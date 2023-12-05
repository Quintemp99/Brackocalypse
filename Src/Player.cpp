//
// Created by SKIKK on 17/11/2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Helpers/Vector2.hpp>
#include <Components/SoundEffectComponent.hpp>
#include <Components/CircleCollisionComponent.hpp>
#include "Player.hpp"
#include "../Scripts/UserInputMovement.hpp"
#include "../Scripts/WalkingSound.hpp"
#include "../Scripts/BlockPlayer.hpp"
#include "Components/BoxCollisionComponent.hpp"

Player::Player(size_t layer) : GameObject() {
    addComponent(std::make_unique<VelocityComponent>());
    addComponent(std::make_unique<UserInputMovement>());
    addComponent(std::make_unique<BlockPlayer>());

    auto sprite = std::make_unique<SpriteComponent>();
    auto &transform = tryGetComponent<TransformComponent>();
    auto collision = std::make_unique<BoxCollisionComponent>(Vector2(16, 16));

    sprite->spritePath = "Sprites/FullSpritesheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(16, 16);
    sprite->margin = 4;
    sprite->sortingLayer = layer;

    auto audioComponent = std::make_unique<SoundEffectComponent>("Sounds/footsteps.mp3");
    audioComponent->volume = 0.05;
    addComponent(std::move(audioComponent));
    addComponent(std::make_unique<WalkingSound>());


    transform.scale = std::make_unique<Vector2>(4, 4);
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);
    collision->collisionType = CollisionType::DYNAMIC;
    addComponent(std::move(sprite));
    addComponent(std::move(collision));
    setTag("Player");
}
