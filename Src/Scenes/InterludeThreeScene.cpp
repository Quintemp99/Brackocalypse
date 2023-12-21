//
// Created by SKIKK on 19/12/2023.
//

#include "InterludeThreeScene.hpp"
#include "EndScene.hpp"

InterludeThreeScene::InterludeThreeScene() : StoryScene(
        {
                "In a clearing surrounded by towering trees, I stumble",
                "upon an ancient grove where your wife and the undead",
                "meet in an unexpected harmony. It's here, in the heart",
                "of the wild, that I uncover a hidden truth. The",
                "orchestrated brackocalypse isn't just a human tragedy",
                "but a disruption of the delicate balance between the",
                "living and the undead. The beer, my constant ",
                "companion, holds a key to this unholy alliance.",
                "As I delve deeper into the secrets of the",
                "past, my quest for survival transforms into",
                "a battle against forces that threaten not",
                "just the remnants of civilization but the very",
                "thing I stand for... Beer.",
                " ",
                "Press enter to continue..."
        }) {}

void InterludeThreeScene::build() {
    StoryScene::build();
}