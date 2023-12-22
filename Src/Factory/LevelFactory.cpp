//
// Created by SKIKK on 23/11/2023.
//

#include "LevelFactory.hpp"
#include "../RogueLikeMapTiles/RogueLikeMapTile.hpp"
#include "../RogueLikeMapTiles/WaterMapTile.hpp"
#include "../RogueLikeMapTiles/FireMapTile.hpp"
#include "../RogueLikeMapTiles/PlayerSpawnMapTile.hpp"
#include "../RogueLikeMapTiles/BoxCollisionMapTile.hpp"
#include "../RogueLikeMapTiles/BoatMapTile.hpp"
#include "../Crate.hpp"
#include "../Helpers/RogueLikeSheetIndoorType.hpp"

void LevelFactory::setSize(Vector2 size) {
    size_ = size;
}

std::unique_ptr<GameObject> LevelFactory::createGameObject(char c, Vector2 position, size_t layer, MapType mapType) {
    switch (c) {
        case 'W':
            return std::make_unique<WaterMapTile>(rogueLikeSheetMap.outdoorMap[Water], position, size_, layer);
        case 'd':
            return std::make_unique<PlayerSpawnMapTile>(rogueLikeSheetMap.outdoorMap[Empty], position, size_, layer);
        case 'I':
            return std::make_unique<FireMapTile>(rogueLikeSheetMap.outdoorMap[Campfire], position, Vector2(14, 8),
                                                 size_, layer);
        case 'H':
            return std::make_unique<BoatMapTile>(rogueLikeSheetMap.outdoorMap[BoatLeft], position, size_, layer);
        case 'l':
            return std::make_unique<Crate>(layer, position, size_);
        case 'j':
            return std::make_unique<FireMapTile>(rogueLikeSheetMap.indoorMap[FirePlace], position, Vector2(13, 0),
                                                 size_, layer);
        default:
            return std::make_unique<RogueLikeMapTile>(getSpriteTileOffset(c, mapType), position, size_, layer);
    }
}

Vector2 LevelFactory::getSpriteTileOffset(char c, MapType mapType) {
    if (mapType == MapType::Outdoor)
        return rogueLikeSheetMap.outdoorMap[static_cast<RogueLikeSheetOutdoorType>(c)];
    return rogueLikeSheetMap.indoorMap[static_cast<RogueLikeSheetIndoorType>(c)];
}
