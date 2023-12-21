//
// Created by qtemp on 21-12-2023.
//

#include "Wife.hpp"

#include <EngineManagers/CollisionLayerManager.hpp>

#include "Components/AIComponent.hpp"
#include "Components/AnimationComponent.hpp"
#include "Components/BoxCollisionComponent.hpp"
#include "Components/CircleCollisionComponent.hpp"
#include "Components/HealthComponent.hpp"
#include "Components/HitSoundComponent.hpp"
#include "Components/RigidBodyComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/VelocityComponent.hpp"
#include "Components/WanderSoundComponent.hpp"
#include "../Scripts/TakeDamage.hpp"
#include "../Scripts/EnemyFollowPlayer.hpp"
#include "../Scripts/MovementAnimation.hpp"
#include "../Scripts/WifeComplaints.hpp"

Wife::Wife(size_t layer, int health)
{
    auto &transform = tryGetComponent<TransformComponent>();
    auto sprite = std::make_unique<SpriteComponent>();
    auto animation = std::make_unique<AnimationComponent>();
    auto collision = std::make_unique<CircleCollisionComponent>(25);
    auto healthComponent = std::make_unique<HealthComponent>(health);

    collision->offset = std::make_unique<Vector2>(0, 70);

    auto wifeHitSound = std::make_unique<HitSoundComponent>("Sounds/hit-sound-wife.mp3");
    auto wifeWanderSound = std::make_unique<WanderSoundComponent>("Sounds/wife-complaint1.mp3");

    auto rigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    auto aiComponent = std::make_unique<AIComponent>();
    auto enemyCollisionObject = std::make_unique<GameObject>();
    auto enemyCollision = std::make_unique<BoxCollisionComponent>(Vector2(60, 100));
    auto enemyRigidbody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);

    wifeHitSound->volume = 0.06;

    wifeWanderSound->volume = 0.08;

    rigidBody->gravityScale = 0.0f;
    rigidBody->collisionCategory = CollisionLayerManager::getInstance().getCategory("Enemy");
    rigidBody->collisionMask = CollisionLayerManager::getInstance().getMask("Enemy");

    collision->offset = std::make_unique<Vector2>(0, 66);

    sprite->spritePath = "Sprites/character_femaleAdventurer_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96, 128);
    sprite->sortingLayer = layer;
    sprite->orderInLayer = 1;
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);

    transform.scale = std::make_unique<Vector2>(1.3, 1.3);

    animation->isLooping = true;
    animation->isPlaying = false;
    animation->startPosition = std::make_unique<Vector2>(0, 4);
    animation->frameCount = 8;
    animation->fps = 15;
    animation->imageSize = std::make_unique<Vector2>(864, 640);

    aiComponent->speed = 20;

    enemyCollision->offset = std::make_unique<Vector2>(0, 22);

    enemyRigidbody->gravityScale = 0.0f;
    enemyRigidbody->collisionCategory = CollisionLayerManager::getInstance().getCategory("EnemyHitbox");
    enemyRigidbody->collisionMask = CollisionLayerManager::getInstance().getMask("EnemyHitbox");
    enemyCollision->isTrigger = false;

    enemyRigidbody->gravityScale = 0.0f;

    enemyCollisionObject->addComponent(std::move(enemyRigidbody));
    enemyCollisionObject->addComponent(std::move(enemyCollision));
    enemyCollisionObject->setTag("EnemyCollision");

    addChild(std::move(enemyCollisionObject));

    addComponent(std::make_unique<VelocityComponent>());
    addComponent(std::move(animation));
    addComponent(std::move(sprite));
    addComponent(std::move(collision));
    addComponent(std::move(rigidBody));
    addComponent(std::move(healthComponent));
    addComponent(std::move(wifeHitSound));
    addComponent(std::move(aiComponent));
    addComponent(std::move(wifeWanderSound));

    addBehaviourScript(std::make_unique<TakeDamage>());
    addBehaviourScript(std::make_unique<EnemyFollowPlayer>("MainGraph"));
    addBehaviourScript(std::make_unique<MovementAnimation>());
    addBehaviourScript(std::make_unique<WifeComplaints>());

    setTag("Enemy");
}

