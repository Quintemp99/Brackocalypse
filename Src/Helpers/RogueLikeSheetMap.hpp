//
// Created by SKIKK on 16/11/2023.
//

#ifndef BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP
#define BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP

#include <Helpers/Vector2.hpp>
#include <map>
#include "RogueLikeSheetOutdoorType.hpp"
#include "RogueLikeSheetIndoorType.hpp"

struct RogueLikeSheetMap {
    std::map<RogueLikeSheetOutdoorType, Vector2> outdoorMap{};
    std::map<RogueLikeSheetIndoorType, Vector2> indoorMap{};

    RogueLikeSheetMap() {
        outdoorMap[Water] = Vector2(3, 1);
        outdoorMap[Grass] = Vector2(5, 0);
        outdoorMap[Ground] = Vector2(6, 0);
        outdoorMap[Stone] = Vector2(7, 0);
        outdoorMap[Sand] = Vector2(8, 0);
        outdoorMap[WaterTopGrass] = Vector2(3, 0);
        outdoorMap[WaterLeftGrass] = Vector2(2, 1);
        outdoorMap[WaterRightGrass] = Vector2(4, 1);
        outdoorMap[WaterBottomGrass] = Vector2(3, 2);
        outdoorMap[WaterLeftTopGrassLarge] = Vector2(2, 0);
        outdoorMap[WaterRightTopGrassLarge] = Vector2(4, 0);
        outdoorMap[WaterLeftBottomGrassLarge] = Vector2(2, 2);
        outdoorMap[WaterRightBottomGrassLarge] = Vector2(4, 2);
        outdoorMap[WaterLeftTopGrassSmall] = Vector2(1, 2);
        outdoorMap[WaterRightTopGrassSmall] = Vector2(0, 2);
        outdoorMap[WaterLeftBottomGrassSmall] = Vector2(1, 1);
        outdoorMap[WaterRightBottomGrassSmall] = Vector2(0, 1);
        outdoorMap[TreeTop] = Vector2(13, 10);
        outdoorMap[TreeBottom] = Vector2(13, 11);
        outdoorMap[Campfire] = Vector2(14, 8);
        outdoorMap[WoodPile] = Vector2(53, 22);
        outdoorMap[Empty] = Vector2(0, 5);
        outdoorMap[BoatRight] = Vector2(53, 15);
        outdoorMap[BoatLeft] = Vector2(53, 18);
        outdoorMap[PeerLeft] = Vector2(53, 12);
        outdoorMap[PeerMiddle] = Vector2(53, 13);
        outdoorMap[PeerRight] = Vector2(53, 14);
        outdoorMap[RockInWaterBig] = Vector2(54, 23);
        outdoorMap[RockInWaterSmall] = Vector2(55, 23);
        outdoorMap[TreeStumpWithAxe] = Vector2(53, 21);
        outdoorMap[MooringPostLeft] = Vector2(53, 16);
        outdoorMap[MooringPostRight] = Vector2(53, 17);
        outdoorMap[TentLeftTop] = Vector2(46, 10);
        outdoorMap[TentRightTop] = Vector2(47, 10);
        outdoorMap[TentLeftBottom] = Vector2(46, 11);
        outdoorMap[TentRightBottom] = Vector2(47, 11);
        outdoorMap[TreeStump] = Vector2(53, 20);
        indoorMap[WallTopLeft] = Vector2(23, 12);
        indoorMap[WallTopMiddle] = Vector2(21, 12);
        indoorMap[WallTopRight] = Vector2(24, 12);
        indoorMap[WallLeftRight] = Vector2(22, 13);
        indoorMap[WallBottomLeft] = Vector2(23, 13);
        indoorMap[WallBottomRight] = Vector2(24, 13);
        indoorMap[WallTopExitTop] = Vector2(26, 12);
        indoorMap[FloorTopLeft] = Vector2(0, 25);
        indoorMap[FloorTopMiddle] = Vector2(1, 25);
        indoorMap[FloorTopRight] = Vector2(2, 25);
        indoorMap[FloorLeft] = Vector2(0, 26);
        indoorMap[Floor] = Vector2(1, 26);
        indoorMap[FloorRight] = Vector2(2, 26);
        indoorMap[FloorBottomLeft] = Vector2(0, 27);
        indoorMap[FloorBottomMiddle] = Vector2(1, 27);
        indoorMap[FloorBottomRight] = Vector2(2, 27);
        indoorMap[Door] = Vector2(33, 3);
        indoorMap[BooksLeft] = Vector2(45, 12);
        indoorMap[BooksMiddle] = Vector2(47, 12);
        indoorMap[BooksRight] = Vector2(50, 12);
        indoorMap[ChairTop] = Vector2(19, 2);
        indoorMap[ChairBottom] = Vector2(20, 2);
        indoorMap[TableLeft] = Vector2(26, 3);
        indoorMap[TableRight] = Vector2(27, 5);
        indoorMap[TableMiddle] = Vector2(27, 3);
        indoorMap[Drinks] = Vector2(54, 11);
        indoorMap[MoneyBig] = Vector2(43, 11);
        indoorMap[MoneyMedium] = Vector2(45, 11);
        indoorMap[Gold] = Vector2(43, 10);
        indoorMap[KitchenSink] = Vector2(28, 0);
        indoorMap[KitchenCabinet] = Vector2(29, 0);
        indoorMap[KitchenCabinetBottles] = Vector2(31, 0);
        indoorMap[Pans] = Vector2(31, 3);
        indoorMap[Bed] = Vector2(15, 2);
        indoorMap[Mirror] = Vector2(24, 7);
        indoorMap[Table] = Vector2(25, 4);
        indoorMap[Candle] = Vector2(22, 8);
        indoorMap[OrangeFloor] = Vector2(13, 26);
        indoorMap[OrangeFloorTopLeft] = Vector2(12, 25);
        indoorMap[OrangeFloorTopMiddle] = Vector2(13, 25);
        indoorMap[OrangeFloorTopRight] = Vector2(14, 25);
        indoorMap[OrangeFloorLeft] = Vector2(12, 26);
        indoorMap[OrangeFloorRight] = Vector2(14, 26);
        indoorMap[OrangeFloorBottomLeft] = Vector2(12, 27);
        indoorMap[OrangeFloorBottomMiddle] = Vector2(13, 27);
        indoorMap[OrangeFloorBottomRight] = Vector2(14, 27);
        indoorMap[BlueFloor] = Vector2(16, 26);
        indoorMap[BlueFloorTopLeft] = Vector2(15, 25);
        indoorMap[BlueFloorTopMiddle] = Vector2(16, 25);
        indoorMap[BlueFloorTopRight] = Vector2(17, 25);
        indoorMap[BlueFloorLeft] = Vector2(15, 26);
        indoorMap[BlueFloorRight] = Vector2(17, 26);
        indoorMap[BlueFloorBottomLeft] = Vector2(15, 27);
        indoorMap[BlueFloorBottomMiddle] = Vector2(16, 27);
        indoorMap[BlueFloorBottomRight] = Vector2(17, 27);
        indoorMap[PillarBottom] = Vector2(14, 20);
        indoorMap[PillaarTop] = Vector2(13, 20);


    }
};

#endif //BRACKOCALYPSE_ROGUELIKESHEETMAP_HPP
