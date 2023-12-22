//
// Created by SKIKK on 04/12/2023.
//

#ifndef BRACKOCALYPSE_FIREMAPTILE_HPP
#define BRACKOCALYPSE_FIREMAPTILE_HPP

#include <Components/AnimationComponent.hpp>
#include <Components/ParticleEmitterComponent.hpp>
#include "RogueLikeMapTile.hpp"

struct FireMapTile : public RogueLikeMapTile {
    FireMapTile(Vector2 tileOffset, Vector2 position, Vector2 startPosition, Vector2 size, size_t layer)
            : RogueLikeMapTile(tileOffset,
                               position, size,
                               layer) {
        auto spriteAnimationComponent = AnimationComponent();
        spriteAnimationComponent.startPosition = std::make_unique<Vector2>(startPosition);
        spriteAnimationComponent.frameCount = 2;
        spriteAnimationComponent.fps = 4;
        spriteAnimationComponent.imageSize = std::make_unique<Vector2>(968, 526);
        addComponent(spriteAnimationComponent);

        auto particleEmitterComponent = ParticleEmitterComponent(5);
        particleEmitterComponent.sortingLayer = layer;
        particleEmitterComponent.orderInLayer = 3;
        particleEmitterComponent.speed = 5;
        particleEmitterComponent.lifeTime = 800;
        particleEmitterComponent.spritePath = "Sprites/Smoke.png";
        particleEmitterComponent.spriteSize = Vector2(250,250);
        particleEmitterComponent.colliderSize = Vector2(125,125);
        particleEmitterComponent.spriteTileOffset = Vector2(0,0);
        particleEmitterComponent.spriteMargin = 0;
        particleEmitterComponent.emitInterval = 500;
        particleEmitterComponent.scale = Vector2(0.5,0.5);
        addComponent(particleEmitterComponent);
    }

    ~FireMapTile() = default;
};


#endif //BRACKOCALYPSE_FIREMAPTILE_HPP
