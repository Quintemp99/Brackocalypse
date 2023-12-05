//
// Created by SKIKK on 23/11/2023.
//

#ifndef BRACKOCALYPSE_WATERMAPTILE_HPP
#define BRACKOCALYPSE_WATERMAPTILE_HPP

#include "RogueLikeMapTile.hpp"

struct WaterMapTile : public RogueLikeMapTile {
    WaterMapTile(Vector2 tileOffset, Vector2 position, Vector2 size, size_t layer)
            : RogueLikeMapTile(tileOffset,
                               position, size,
                               layer) {
        // Example of where tile specific stuff goed
    }

    ~WaterMapTile() = default;
};

#endif //BRACKOCALYPSE_WATERMAPTILE_HPP
