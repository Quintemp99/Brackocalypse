//
// Created by SKIKK on 19/12/2023.
//

#include "InterludeOneScene.hpp"
#include "HomeScene.hpp"
#include "InterludeTwoScene.hpp"

InterludeOneScene::InterludeOneScene() : StoryScene(
        {
                "In the heart of this untamed wilderness, I discover",
                "a secluded spot, a haven where the rustling leaves",
                "whisper stories of what once was. The crackling",
                "campfire, fueled by scavenged wood, paints dancing",
                "shadows on the untouched foliage. As I take a sip",
                "from my beer, the bitter taste mingles with the",
                "sweet nostalgia of a world overtaken by zombies.",
                " ",
                "Press enter to continue..."
        }, new InterludeTwoScene()) {}

void InterludeOneScene::build() {
    StoryScene::build();
}