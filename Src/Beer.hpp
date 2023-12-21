//
// Created by stijn on 6-12-2023.
//

#ifndef BRACKOCALYPSE_BEER_HPP
#define BRACKOCALYPSE_BEER_HPP

#include <Objects/GameObject.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include <Components/RigidBodyComponent.hpp>
#include <EngineManagers/CollisionLayerManager.hpp>
#include "../Scripts/CollectBeers.hpp"
#include "Components/SoundEffectComponent.hpp"
#include "../Scripts/BopAnimation.hpp"

class Beer : public GameObject {
public:
    Beer(entity entity1) : GameObject(entity1) {}

    Beer(size_t layer) : GameObject() {
        setTag("Beer");

        auto spriteComponent = std::make_unique<SpriteComponent>();
        spriteComponent->spritePath = "Sprites/beer.png";
        spriteComponent->spriteSize = std::make_unique<Vector2>(512, 512);
        spriteComponent->tileOffset = std::make_unique<Vector2>(0, 0);
        spriteComponent->orderInLayer = 0;
        spriteComponent->sortingLayer = layer;

        auto collisionComponent = std::make_unique<BoxCollisionComponent>(Vector2(512, 512));
        collisionComponent->isTrigger = false;
        addComponent(std::move(collisionComponent));

        auto rigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
        rigidBody->gravityScale = 0.0f;
        rigidBody->collisionCategory = CollisionLayerManager::getInstance().getCategory("Collectable");
        rigidBody->collisionMask = CollisionLayerManager::getInstance().getMask("Collectable");
        addComponent(std::move(rigidBody));

        auto collectBeerSound = std::make_unique<SoundEffectComponent>("Sounds/drink-sound.mp3");
        collectBeerSound->volume = 0.01;

        addComponent(std::move(collectBeerSound));

        auto &transform = tryGetComponent<TransformComponent>();
        transform.scale->setX(0.12);
        transform.scale->setY(0.12);

        this->addBehaviourScript(std::make_unique<CollectBeers>());
        addBehaviourScript(std::make_unique<BopAnimation>(30, 3000));
        this->addComponent(std::move(spriteComponent));
    }

    bool isCollected = false;
};


#endif //BRACKOCALYPSE_BEER_HPP
