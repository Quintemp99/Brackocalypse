//
// Created by SKIKK on 19/12/2023.
//

#include "IntroductionScene.hpp"
#include "Levels/FirstLevel.hpp"

IntroductionScene::IntroductionScene() : StoryScene(
        {
            "Amidst the comforting confines of my home, nestled in",
            "the post-brackocalyptic landscape reclaimed by nature,",
            "I, Bob the Brouwer, explore the familiar remnants of a",
            "world that once thrived with human activity. The tranquility",
            "of my domestic surroundings sharply contrasts with the",
            "distant sounds of the undead, their eerie moans echoing",
            "through the hallways. With a beer in hand, my trusted",
            "companion in this homely retreat I find solace within",
            "the welcoming embrace of familiar walls, beside the",
            "crackling warmth of an fireplace in my cozy home.",
            " ",
            "Press enter to continue..."
        }) {}

void IntroductionScene::build() {
    StoryScene::build();
}
