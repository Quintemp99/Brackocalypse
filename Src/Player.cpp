//
// Created by SKIKK on 17/11/2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Helpers/Vector2.hpp>
#include <Components/AnimationComponent.hpp>
#include <Components/SoundEffectComponent.hpp>
#include <EngineManagers/SceneManager.hpp>
#include <Components/RectangleComponent.hpp>
#include "Player.hpp"
#include "../Scripts/UserInputMovement.hpp"
#include "Gun.hpp"

Player::Player(std::unique_ptr<GameObject> &spawnLocationMapTile) {
    auto &transformComponent = spawnLocationMapTile->tryGetComponent<TransformComponent>();
    Vector2 location = Vector2(transformComponent.position->getX(), transformComponent.position->getY());
    auto spriteComponent = spawnLocationMapTile->tryGetComponent<SpriteComponent>();
    int layer = spriteComponent.sortingLayer;

    init(layer, location);
}

Player::Player(size_t layer, Vector2 position) : GameObject() {
    init(layer, position);
}

void Player::init(size_t layer, Vector2 position) {
    addComponent(std::make_unique<VelocityComponent>());
    addComponent(std::make_unique<UserInputMovement>());
    auto sprite = std::make_unique<SpriteComponent>();
    auto &transform = tryGetComponent<TransformComponent>();
    auto walkAnimation = std::make_unique<AnimationComponent>();
    sprite->spritePath = "Sprites/character_maleAdventurer_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96, 128);
    sprite->imageSize = std::make_unique<Vector2>(864, 640);
    sprite->sortingLayer = layer;
    sprite->orderInLayer = 1;
    transform.scale = std::make_unique<Vector2>(1, 1);
    transform.position = std::make_unique<Vector2>(position);
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);
    walkAnimation->fps = 15;
    walkAnimation->isLooping = true;
    walkAnimation->isPlaying = false;
    walkAnimation->startPosition = std::make_unique<Vector2>(0, 4);
    walkAnimation->frameCount = 8;
    transform.scale = std::make_unique<Vector2>(1, 1);
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);

//    auto audioComponent = std::make_unique<SoundEffectComponent>("Sounds/footsteps2.mp3");
//    audioComponent->volume = 0.05;
//    addComponent(std::move(audioComponent));

    addComponent(std::move(sprite));
    addComponent(std::move(walkAnimation));
    auto gun = std::make_unique<Gun>(layer);
    addChild(std::move(gun));
    setTag("Player");
    setName("Player");
}
