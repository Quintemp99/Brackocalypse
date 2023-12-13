//
// Created by SKIKK on 04/12/2023.
//

#ifndef BRACKOCALYPSE_CAMPFIREMAPTILE_HPP
#define BRACKOCALYPSE_CAMPFIREMAPTILE_HPP

#include <Components/AnimationComponent.hpp>
#include <Components/ParticleEmitterComponent.hpp>
#include "RogueLikeMapTile.hpp"

struct CampfireMapTile : public RogueLikeMapTile {
    CampfireMapTile(Vector2 tileOffset, Vector2 position, Vector2 size, size_t layer) : RogueLikeMapTile(tileOffset,
                                                                                                         position, size,
                                                                                                         layer) {
        auto spriteAnimationComponent = AnimationComponent();
        spriteAnimationComponent.startPosition = std::make_unique<Vector2>(14, 8);
        spriteAnimationComponent.frameCount = 2;
        spriteAnimationComponent.fps = 4;
        spriteAnimationComponent.imageSize = std::make_unique<Vector2>(968, 526);
        addComponent(spriteAnimationComponent);

        auto particleEmitterComponent = ParticleEmitterComponent(20);
        particleEmitterComponent.sortingLayer = layer;
        particleEmitterComponent.speed = 0.07;
        particleEmitterComponent.lifeTime = 700;
        particleEmitterComponent.color = std::make_unique<Color>(220, 150, 150, 255);
        particleEmitterComponent.emitInterval = 200;
        particleEmitterComponent.particleSize = Vector2(3, 3);
        addComponent(particleEmitterComponent);
    }

    ~CampfireMapTile() = default;
};


#endif //BRACKOCALYPSE_CAMPFIREMAPTILE_HPP
