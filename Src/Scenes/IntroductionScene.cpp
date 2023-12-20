//
// Created by SKIKK on 19/12/2023.
//

#include "IntroductionScene.hpp"
#include "DemoLevel.hpp"

IntroductionScene::IntroductionScene() : StoryScene(
        {
            "Amidst the vast expanse of nature reclaimed",
            "by the post-apocalyptic wilderness, I, Bob de Brouwer,",
            "navigate through the overgrown remnants of",
            "a world that once belonged to mankind. The serenity of",
            "untouched landscapes now contrasts sharply",
            "with the groans of the undead that echo through the",
            "rustling leaves. Clutching a beer, my companion",
            "in this wild solitude, I find solace",
            "beneath the towering trees and open skies.",
            " ",
            "Press enter to continue..."
        }, new DemoLevel()) {}

void IntroductionScene::build() {
    StoryScene::build();
}
