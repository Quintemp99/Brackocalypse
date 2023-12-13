//
// Created by Olaf van den Berg on 04/12/2023.
//

#ifndef BRACKOCALYPSE_BOXCOLLISIONMAPTILE_HPP
#define BRACKOCALYPSE_BOXCOLLISIONMAPTILE_HPP

#include "RogueLikeMapTile.hpp"
#include "../Helpers/RogueLikeSheetType.hpp"
#include "Components/RigidBodyComponent.hpp"

struct BoxCollisionMapTile : public RogueLikeMapTile {
    BoxCollisionMapTile(Vector2 tileOffset, Vector2 position, Vector2 size, size_t layer)
            : RogueLikeMapTile(tileOffset,
                               position, size,
                               layer) {
        auto colliderComponent = BoxCollisionComponent(spriteSize);
        addComponent(std::make_unique<RigidBodyComponent>(CollisionType::STATIC));
        addComponent(colliderComponent);

    }

    ~BoxCollisionMapTile() = default;
};


#endif //BRACKOCALYPSE_BOXCOLLISIONMAPTILE_HPP
