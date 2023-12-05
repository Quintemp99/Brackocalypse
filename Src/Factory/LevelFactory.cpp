//
// Created by SKIKK on 23/11/2023.
//

#include "LevelFactory.hpp"
#include "../RogueLikeMapTiles/RogueLikeMapTile.hpp"
#include "../RogueLikeMapTiles/WaterMapTile.hpp"
#include "../Player.hpp"
#include "../../Scripts/UserInputMovement.hpp"
#include "../RogueLikeMapTiles/BoxCollisionMapTile.hpp"

void LevelFactory::setSize(Vector2 size) {
    size_ = size;
}

std::unique_ptr<GameObject> LevelFactory::createGameObject(char c, Vector2 position, size_t layer) {
    switch (c) {
        case 'W':
            return std::make_unique<WaterMapTile>(rogueLikeSheetMap.map[Water], position, size_, layer);
        case 'J':
            return std::make_unique<Player>(layer);
        case 'Y':
            return std::make_unique<BoxCollisionMapTile>(rogueLikeSheetMap.map[static_cast<RogueLikeSheetType>(c)],
                                                         position, size_, layer);
        case 'U':
            return std::make_unique<BoxCollisionMapTile>(rogueLikeSheetMap.map[static_cast<RogueLikeSheetType>(c)],
                                                         position, size_, layer);
        case 'P':
            return std::make_unique<BoxCollisionMapTile>(rogueLikeSheetMap.map[static_cast<RogueLikeSheetType>(c)],
                                                         position, size_, layer);
        case 'Q':
            return std::make_unique<BoxCollisionMapTile>(rogueLikeSheetMap.map[static_cast<RogueLikeSheetType>(c)],
                                                         position, size_, layer);
        case 'w':
            return std::make_unique<BoxCollisionMapTile>(rogueLikeSheetMap.map[static_cast<RogueLikeSheetType>(c)],
                                                         position, size_, layer);
        default:
            return std::make_unique<RogueLikeMapTile>(rogueLikeSheetMap.map[static_cast<RogueLikeSheetType>(c)],
                                                      position, size_, layer);
    }
}