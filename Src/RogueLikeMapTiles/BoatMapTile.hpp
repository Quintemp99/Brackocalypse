//
// Created by SKIKK on 19/12/2023.
//

#ifndef BRACKOCALYPSE_BOATMAPTILE_HPP
#define BRACKOCALYPSE_BOATMAPTILE_HPP

#include "RogueLikeMapTile.hpp"
#include "../Scripts/BopAnimation.hpp"

struct BoatMapTile : public RogueLikeMapTile {
    BoatMapTile(Vector2 tileOffset, Vector2 position, Vector2 size, size_t layer) : RogueLikeMapTile(tileOffset,
        position, size,
        layer) {
        addBehaviourScript(std::make_unique<BopAnimation>(5, 1000));
    }

    ~BoatMapTile() = default;
};

#endif //BRACKOCALYPSE_BOATMAPTILE_HPP
