//
// Created by SKIKK on 16/11/2023.
//

#ifndef BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP
#define BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP

#include <Helpers/Vector2.hpp>
#include <map>
#include "Helpers/RogueLikeSheetType.hpp"

struct RogueLikeSheetMap {
    std::map<RogueLikeSheetType, Vector2> map {};
    RogueLikeSheetMap() {
        map[Water] = Vector2(3,1);
        map[Grass] = Vector2(5,0);
        map[Ground] = Vector2(6,0);
        map[Stone] = Vector2(7,0);
        map[Sand] = Vector2(8,0);
        map[WaterTopGrass] = Vector2(3,0);
        map[WaterLeftGrass] = Vector2(2,1);
        map[WaterRightGrass] = Vector2(4,1);
        map[WaterBottomGrass] = Vector2(3,2);
        map[WaterLeftTopGrassLarge] = Vector2(2,0);
        map[WaterRightTopGrassLarge] = Vector2(4,0);
        map[WaterLeftBottomGrassLarge] = Vector2(2,2);
        map[WaterRightBottomGrassLarge] = Vector2(4,2);
        map[WaterLeftTopGrassSmall] = Vector2(1,2);
        map[WaterRightTopGrassSmall] = Vector2(0,2);
        map[WaterLeftBottomGrassSmall] = Vector2(1,1);
        map[WaterRightBottomGrassSmall] = Vector2(0,1);
    }
};

#endif //BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP
