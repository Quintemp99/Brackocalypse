//
// Created by SKIKK on 04/12/2023.
//

#ifndef BRACKOCALYPSE_PLAYERSPAWNMAPTILE_HPP
#define BRACKOCALYPSE_PLAYERSPAWNMAPTILE_HPP

#include "RogueLikeMapTile.hpp"

struct PlayerSpawnMapTile : public RogueLikeMapTile {
    PlayerSpawnMapTile(Vector2 tileOffset, Vector2 position, Vector2 size, size_t layer) : RogueLikeMapTile(tileOffset, position, size, layer){
        setName("PlayerSpawn");
    }
    ~PlayerSpawnMapTile() = default;
};

#endif //BRACKOCALYPSE_PLAYERSPAWNMAPTILE_HPP
