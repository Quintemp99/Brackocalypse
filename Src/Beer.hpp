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
#include "../Scripts/CollectBeers.hpp"

class Beer : public GameObject {
public:
    Beer() : GameObject() {
        setTag("Beer");

        auto spriteComponent = std::make_unique<SpriteComponent>();
        spriteComponent->spritePath = "Sprites/beer.png";
        spriteComponent->spriteSize = std::make_unique<Vector2>(512, 512);
        spriteComponent->tileOffset = std::make_unique<Vector2>(0, 0);
        spriteComponent->orderInLayer = 0;

        auto collisionComponent = std::make_unique<BoxCollisionComponent>(Vector2(512, 512));
        addComponent(std::move(collisionComponent));

        auto rigidBody = std::make_unique<RigidBodyComponent>(CollisionType::STATIC);
        addComponent(std::move(rigidBody));

        auto& transform = tryGetComponent<TransformComponent>();
        transform.scale->setX(0.12);
        transform.scale->setY(0.12);

        this->addBehaviourScript(std::make_unique<CollectBeers>());
        this->addComponent(std::move(spriteComponent));
    }
};


#endif //BRACKOCALYPSE_BEER_HPP
