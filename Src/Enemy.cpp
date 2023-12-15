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
#include "Enemy.hpp"
#include "Components/HealthComponent.hpp"
#include "../Scripts/EnemyFollowPlayer.hpp"

Enemy::Enemy(size_t layer) {
    addComponent(std::make_unique<VelocityComponent>());
    auto &transform = tryGetComponent<TransformComponent>();
    auto sprite = std::make_unique<SpriteComponent>();
    auto animation = std::make_unique<AnimationComponent>();
    auto collision = std::make_unique<BoxCollisionComponent>(Vector2(64, 40));
    auto health = std::make_unique<HealthComponent>(3);
    collision->offset = std::make_unique<Vector2>(0, 44);

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
    aiComponent->speed = 0.08;
    aiComponent->target = std::make_unique<Vector2>(-400,0);

    addBehaviourScript(std::make_unique<EnemyFollowPlayer>("MainGraph"));

    addComponent(std::move(aiComponent));
    addComponent(std::move(animation));
    addComponent(std::move(sprite));
    addComponent(std::move(collision));
    addComponent(std::move(rigidBody));
    addComponent(std::move(health));
    setTag("Enemy");
}
