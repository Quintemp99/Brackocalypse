//
// Created by SKIKK on 04/12/2023.
//

#ifndef BRACKOCALYPSE_CAMPFIREMAPTILE_HPP
#define BRACKOCALYPSE_CAMPFIREMAPTILE_HPP

#include <Components/AnimationComponent.hpp>
#include "RogueLikeMapTile.hpp"

struct CampfireMapTile : public RogueLikeMapTile {
    CampfireMapTile(Vector2 tileOffset, Vector2 position, Vector2 size, size_t layer) : RogueLikeMapTile(tileOffset, position, size, layer){
        auto spriteAnimationComponent = AnimationComponent();
        spriteAnimationComponent.startPosition = std::make_unique<Vector2>(14,8);
        spriteAnimationComponent.frameCount = 2;
        spriteAnimationComponent.fps = 4;
        addComponent(spriteAnimationComponent);
    }
    ~CampfireMapTile() = default;
};


#endif //BRACKOCALYPSE_CAMPFIREMAPTILE_HPP
