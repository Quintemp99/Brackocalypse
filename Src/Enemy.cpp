//
// Created by Olaf van den Berg on 11-12-2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Helpers/CollisionType.hpp>
#include <Components/RigidBodyComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include <Components/AIComponent.hpp>
#include <Components/SoundEffectComponent.hpp>
#include "Enemy.hpp"
#include "Components/HealthComponent.hpp"
#include "../Scripts/EnemyFollowPlayer.hpp"
#include "../Scripts/TakeDamage.hpp"

Enemy::Enemy(size_t layer) {
    addComponent(std::make_unique<VelocityComponent>());
    auto &transform = tryGetComponent<TransformComponent>();
    auto sprite = std::make_unique<SpriteComponent>();
    auto animation = std::make_unique<AnimationComponent>();
    auto collision = std::make_unique<BoxCollisionComponent>(Vector2(48, 40));
    auto health = std::make_unique<HealthComponent>(3);
    collision->offset = std::make_unique<Vector2>(0, 44);

    auto zombieHitSound = std::make_unique<SoundEffectComponent>("Sounds/zombie-death-sound.mp3");
    zombieHitSound->volume = 0.05;

    auto rigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    rigidBody->gravityScale = 0.0f;

    sprite->spritePath = "Sprites/character_zombie_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96, 128);
    sprite->sortingLayer = layer;
    sprite->orderInLayer = 1;
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);

    transform.scale = std::make_unique<Vector2>(1, 1);

    animation->isLooping = true;
    animation->isPlaying = false;
    animation->startPosition = std::make_unique<Vector2>(0, 4);
    animation->frameCount = 8;
    animation->imageSize = std::make_unique<Vector2>(864, 640);

    auto aiComponent = std::make_unique<AIComponent>();
    aiComponent->speed = 10;
    aiComponent->target = std::make_unique<Vector2>(-400, 0);

    addBehaviourScript(std::make_unique<EnemyFollowPlayer>("MainGraph"));

    addComponent(std::move(aiComponent));
    auto enemyCollisionObject = std::make_unique<GameObject>();
    auto enemyCollision = std::make_unique<BoxCollisionComponent>(Vector2(64, 96));
    enemyCollision->offset = std::make_unique<Vector2>(0, 16);
    auto playerRigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    playerRigidBody->gravityScale = 0.0f;
    enemyCollision->isTrigger = true;
    enemyCollisionObject->addComponent(std::move(playerRigidBody));
    enemyCollisionObject->addComponent(std::move(enemyCollision));
    enemyCollisionObject->setTag("EnemyCollision");

    int totalWidth = health->maxHealth * 19;
    int offsetX = -totalWidth / 2;

    auto healthBar = std::make_unique<GameObject>();
    healthBar->setTag("EnemyHealth");
    for (auto i = 0; i < health->maxHealth; i++) {
        auto healthObject = std::make_unique<GameObject>();
        auto healthSprite = std::make_unique<SpriteComponent>();
        healthSprite->spritePath = "Sprites/heart_full.png";
        healthSprite->spriteSize = std::make_unique<Vector2>(36, 32);
        healthSprite->tileOffset = std::make_unique<Vector2>(0, 0);

        auto &healthTransform = healthObject->tryGetComponent<TransformComponent>();
        healthTransform.scale = std::make_unique<Vector2>(0.5, 0.5);
        healthTransform.position = std::make_unique<Vector2>(offsetX + (i + 0.5) * 19, -45);
        healthObject->addComponent(std::move(healthSprite));
        healthBar->addChild(std::move(healthObject));
    }


    addChild(std::move(healthBar));
    addChild(std::move(enemyCollisionObject));
    addComponent(std::move(animation));
    addComponent(std::move(sprite));
    addComponent(std::move(collision));
    addComponent(std::move(rigidBody));
    addComponent(std::move(health));
    addComponent(std::move(zombieHitSound));
    addBehaviourScript(std::make_unique<TakeDamage>());
    setTag("Enemy");
}
