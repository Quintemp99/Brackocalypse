//
// Created by SKIKK on 19/12/2023.
//

#include "InterludeTwoScene.hpp"
#include "InterludeThreeScene.hpp"

InterludeTwoScene::InterludeTwoScene() : StoryScene(
        {
                "Days blend seamlessly into one another as I trudge",
                "through the uncharted territory, the familiar smell of",
                "a beer providing a fleeting sense of normalcy.",
                "The cool breeze carries echoes of a world ",
                "now lost, yet the untouched beauty of nature",
                "acts as a soothing balm to the wounds of the",
                "past. The beer, once a simple pleasure, now",
                "symbolizes a connection to a simpler",
                "time amid the chaos.",
                " ",
                "Press enter to continue..."
        }) {}

void InterludeTwoScene::build() {
    StoryScene::build();
}