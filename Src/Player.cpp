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
#include <Components/BoxCollisionComponent.hpp>
#include <Components/CircleCollisionComponent.hpp>
#include "Player.hpp"
#include "../Scripts/UserInputMovement.hpp"
#include "Gun.hpp"
#include "Components/BoxCollisionComponent.hpp"
#include "../Scripts/PlayerProgress.hpp"

#include "Components/RigidBodyComponent.hpp"
#include "Components/HealthComponent.hpp"
#include "../Scripts/UpdateHealth.hpp"

Player::Player(GameObject *spawnLocationMapTile) {
    auto &transformComponent = spawnLocationMapTile->tryGetComponent<TransformComponent>();
    Vector2 location = Vector2(transformComponent.position->getX(), transformComponent.position->getY());
    auto spriteComponent = spawnLocationMapTile->tryGetComponent<SpriteComponent>();
    int layer = spriteComponent.sortingLayer;

    addBehaviourScript(std::make_unique<PlayerProgress>());
    init(layer, location);
}

Player::Player(size_t layer, Vector2 position) : GameObject() {
    init(layer, position);
}

void Player::init(size_t layer, Vector2 position) {
    addComponent(std::make_unique<VelocityComponent>());
    addBehaviourScript(std::make_unique<UserInputMovement>());

    auto sprite = std::make_unique<SpriteComponent>();
    auto &transform = tryGetComponent<TransformComponent>();
    auto walkAnimation = std::make_unique<AnimationComponent>();
    auto health = std::make_unique<HealthComponent>(3);
    sprite->spritePath = "Sprites/character_maleAdventurer_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96, 128);
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
    walkAnimation->imageSize = std::make_unique<Vector2>(864, 640);

    auto collisionComponent = std::make_unique<BoxCollisionComponent>(Vector2(48, 40));
    collisionComponent->offset = std::make_unique<Vector2>(0, 44);
    addComponent(std::move(collisionComponent));
    auto rigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    rigidBody->gravityScale = 0.0f;
    addComponent(std::move(rigidBody));
    addComponent(std::move(sprite));
    addComponent(std::move(walkAnimation));
    addComponent(std::move(health));

    auto playerCollision = std::make_unique<GameObject>();
    auto collision = std::make_unique<BoxCollisionComponent>(Vector2(64, 96));
    collision->offset = std::make_unique<Vector2>(0, 16);
    auto playerRigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    playerRigidBody->gravityScale = 0.0f;
    collision->isTrigger = true;
    playerCollision->addComponent(std::move(playerRigidBody));
    playerCollision->addComponent(std::move(collision));
    playerCollision->setTag("PlayerCollision");
    auto gun = std::make_unique<Gun>(layer);
    addChild(std::move(playerCollision));
    addChild(std::move(gun));
    addBehaviourScript(std::make_unique<UpdateHealth>());
    setTag("Player");
    setName("Player");
}
