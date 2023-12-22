//
// Created by SKIKK on 17/11/2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <EngineManagers/SceneManager.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include <EngineManagers/CollisionLayerManager.hpp>
#include "Player.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Gun.hpp"
#include "Components/HealthComponent.hpp"
#include "Scripts/MovementAnimation.hpp"
#include "Scripts/UpdateHealth.hpp"
#include "Scripts/TakeDamage.hpp"
#include "Scripts/EnemyDamage.hpp"
#include "Components/HitSoundComponent.hpp"
#include "Scripts/PlayerProgressScript.hpp"

Player::Player(GameObject *spawnLocationMapTile) {
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
    auto sprite = std::make_unique<SpriteComponent>();
    auto &transform = tryGetComponent<TransformComponent>();
    auto walkAnimation = std::make_unique<AnimationComponent>();

    auto playerProgress = SceneManager::getGameObjectByName("PlayerProgress");
    auto &playerProgressScript = playerProgress.value()->tryGetBehaviourScript<PlayerProgressScript>();

    auto health = std::make_unique<HealthComponent>(playerProgressScript.getNumberOfLives(),
                                                    playerProgressScript.getMaxNumberOfLives());
    auto collisionComponent = std::make_unique<BoxCollisionComponent>(Vector2(48, 40));
    auto rigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    auto playerCollision = std::make_unique<GameObject>();
    auto collision = std::make_unique<BoxCollisionComponent>(Vector2(64, 96));
    auto playerRigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    auto gun = std::make_unique<Gun>(layer);
    auto hitSound = std::make_unique<HitSoundComponent>("Sounds/player-hit-sound.mp3");

    sprite->spritePath = "Sprites/character_maleAdventurer_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96, 128);
    sprite->sortingLayer = layer;
    sprite->orderInLayer = 1;
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);

    transform.scale = std::make_unique<Vector2>(1, 1);
    transform.position = std::make_unique<Vector2>(position);

    walkAnimation->fps = 15;
    walkAnimation->isLooping = true;
    walkAnimation->isPlaying = false;
    walkAnimation->startPosition = std::make_unique<Vector2>(0, 4);
    walkAnimation->frameCount = 8;
    walkAnimation->imageSize = std::make_unique<Vector2>(864, 640);

    collisionComponent->offset = std::make_unique<Vector2>(0, 44);

    rigidBody->gravityScale = 0.0f;
    rigidBody->collisionCategory = CollisionLayerManager::getInstance().getCategory("Player");
    rigidBody->collisionMask = CollisionLayerManager::getInstance().getMask("Player");

    hitSound->volume = 0.01;

    addComponent(std::make_unique<VelocityComponent>());
    addComponent(std::move(collisionComponent));
    addComponent(std::move(rigidBody));
    addComponent(std::move(sprite));
    addComponent(std::move(walkAnimation));
    addComponent(std::move(health));
    addComponent(std::move(hitSound));

    collision->offset = std::make_unique<Vector2>(0, 16);
    collision->isTrigger = false;
    playerRigidBody->gravityScale = 0.0f;
    playerRigidBody->collisionCategory = CollisionLayerManager::getInstance().getCategory("PlayerHitbox");
    playerRigidBody->collisionMask = CollisionLayerManager::getInstance().getMask("PlayerHitbox");
    playerCollision->addComponent(std::move(playerRigidBody));
    playerCollision->addComponent(std::move(collision));
    playerCollision->setTag("PlayerCollision");

    addChild(std::move(playerCollision));
    addChild(std::move(gun));

    addBehaviourScript(std::make_unique<UserInputMovement>());
    addBehaviourScript(std::make_unique<MovementAnimation>());
    addBehaviourScript(std::make_unique<EnemyDamage>());
    addBehaviourScript(std::make_unique<TakeDamage>());
    addBehaviourScript(std::make_unique<UpdateHealth>());

    setTag("Player");
    setName("Player");
}
