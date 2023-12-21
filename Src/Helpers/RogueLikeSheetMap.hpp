//
// Created by SKIKK on 16/11/2023.
//

#ifndef BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP
#define BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP

#include <Helpers/Vector2.hpp>
#include <map>
#include "RogueLikeSheetType.hpp"

struct RogueLikeSheetMap {
    std::map<RogueLikeSheetType, Vector2> map{};

    RogueLikeSheetMap() {
        map[Water] = Vector2(3, 1);
        map[Grass] = Vector2(5, 0);
        map[Ground] = Vector2(6, 0);
        map[Stone] = Vector2(7, 0);
        map[Sand] = Vector2(8, 0);
        map[WaterTopGrass] = Vector2(3, 0);
        map[WaterLeftGrass] = Vector2(2, 1);
        map[WaterRightGrass] = Vector2(4, 1);
        map[WaterBottomGrass] = Vector2(3, 2);
        map[WaterLeftTopGrassLarge] = Vector2(2, 0);
        map[WaterRightTopGrassLarge] = Vector2(4, 0);
        map[WaterLeftBottomGrassLarge] = Vector2(2, 2);
        map[WaterRightBottomGrassLarge] = Vector2(4, 2);
        map[WaterLeftTopGrassSmall] = Vector2(1, 2);
        map[WaterRightTopGrassSmall] = Vector2(0, 2);
        map[WaterLeftBottomGrassSmall] = Vector2(1, 1);
        map[WaterRightBottomGrassSmall] = Vector2(0, 1);
        map[TreeTop] = Vector2(13, 10);
        map[TreeBottom] = Vector2(13, 11);
        map[Campfire] = Vector2(14, 8);
        map[WoodPile] = Vector2(53, 22);
        map[Empty] = Vector2(0, 5);
        map[BoatRight] = Vector2(53, 15);
        map[BoatLeft] = Vector2(53, 18);
        map[PeerLeft] = Vector2(53, 12);
        map[PeerMiddle] = Vector2(53, 13);
        map[PeerRight] = Vector2(53, 14);
        map[RockInWaterBig] = Vector2(54, 23);
        map[RockInWaterSmall] = Vector2(55, 23);
        map[TreeStumpWithAxe] = Vector2(53, 21);
        map[MooringPostLeft] = Vector2(53, 16);
        map[MooringPostRight] = Vector2(53, 17);
        map[TentLeftTop] = Vector2(46, 10);
        map[TentRightTop] = Vector2(47, 10);
        map[TentLeftBottom] = Vector2(46, 11);
        map[TentRightBottom] = Vector2(47, 11);
        map[TreeStump] = Vector2(53, 20);
        map[WallTopLeft] = Vector2(23, 12);
        map[WallTopMiddle] = Vector2(21, 12);
        map[WallTopRight] = Vector2(24, 12);
        map[WallLeftRight] = Vector2(22, 13);
        map[WallBottomLeft] = Vector2(23, 13);
        map[WallBottomRight] = Vector2(24, 13);
        map[WallTopExitTop] = Vector2(26, 12);
        map[FloorTopLeft] = Vector2(0, 25);
        map[FloorTopMiddle] = Vector2(1, 25);
        map[FloorTopRight] = Vector2(2, 25);
        map[FloorLeft] = Vector2(0, 26);
        map[Floor] = Vector2(1, 26);
        map[FloorRight] = Vector2(2, 26);
        map[FloorBottomLeft] = Vector2(0, 27);
        map[FloorBottomMiddle] = Vector2(1, 27);
        map[FloorBottomRight] = Vector2(2, 27);
        map[Door] = Vector2(33, 3);
        map[BooksLeft] = Vector2(45, 12);
        map[BooksMiddle] = Vector2(47, 12);
        map[BooksRight] = Vector2(50, 12);
        map[ChairTop] = Vector2(19, 2);
        map[ChairBottom] = Vector2(20, 2);
        map[TableLeft] = Vector2(26, 3);
        map[TableRight] = Vector2(27, 5);
        map[TableMiddle] = Vector2(27, 3);
        map[Drinks] = Vector2(54, 11);
        map[MoneyBig] = Vector2(43, 11);
        map[MoneyMedium] = Vector2(45, 11);
        map[Gold] = Vector2(43, 10);
        map[KitchenSink] = Vector2(28, 0);
        map[KitchenCabinet] = Vector2(29, 0);
        map[KitchenCabinetBottles] = Vector2(31, 0);
        map[Pans] = Vector2(31, 3);
        map[Bed] = Vector2(15, 2);
        map[Mirror] = Vector2(24, 7);
        map[Table] = Vector2(25, 4);
        map[Candle] = Vector2(20, 7);


    }
};

#endif //BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP
