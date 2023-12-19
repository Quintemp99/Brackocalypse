//
// Created by jesse on 18/12/2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include <Components/RigidBodyComponent.hpp>
#include <Components/SoundEffectComponent.hpp>
#include <EngineManagers/CollisionLayerManager.hpp>
#include "Crate.hpp"
#include "../Scripts/PlayBoxMovingSound.hpp"

Crate::Crate(size_t layer, Vector2 localPosition, Vector2 size) : GameObject() {
    addComponent(std::make_unique<VelocityComponent>());
    auto sprite = std::make_unique<SpriteComponent>();
    sprite->spritePath = "Sprites/Crate.png";
    sprite->spriteSize = std::make_unique<Vector2>(250, 250);
    sprite->sortingLayer = layer;
    sprite->orderInLayer = 2;
    auto &transform = tryGetComponent<TransformComponent>();
    transform.scale = std::make_unique<Vector2>(0.256, 0.256);
    float posX = ((localPosition.getX() * (sprite->spriteSize->getX() * transform.scale->getX())) +
                  ((sprite->spriteSize->getX() * transform.scale->getX()) / 2)) -
                 (size.getX() * (transform.scale->getX() * sprite->spriteSize->getX()) / 2);
    float posY = ((localPosition.getY() * (sprite->spriteSize->getY() * transform.scale->getY())) +
                  ((sprite->spriteSize->getY() * transform.scale->getY()) / 2)) -
                 (size.getY() * (sprite->spriteSize->getY() * transform.scale->getY()) / 2);
    transform.position = std::make_unique<Vector2>(posX, posY);
    addComponent(std::move(sprite));

    auto cratePushSound = std::make_unique<SoundEffectComponent>("Sounds/box-push-sound.mp3");
    cratePushSound->volume = 0.01;
    addComponent(std::move(cratePushSound));

    auto collisionComponent = std::make_unique<BoxCollisionComponent>(Vector2(250, 250));
    collisionComponent->offset = std::make_unique<Vector2>(0, 0);
    addComponent(std::move(collisionComponent));

    auto rigidBodyComponent = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    rigidBodyComponent->mass = 1;
    rigidBodyComponent->friction = 0;
    rigidBodyComponent->restitution = 0;
    rigidBodyComponent->gravityScale = 0;
    rigidBodyComponent->collisionCategory = CollisionLayerManager::getInstance().getCategory("Crate");
    rigidBodyComponent->collisionMask = CollisionLayerManager::getInstance().getMask("Crate");
    addComponent(std::move(rigidBodyComponent));

    addBehaviourScript(std::make_unique<PlayBoxMovingSound>());

    setTag("Crate");
}
