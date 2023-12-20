//
// Created by SKIKK on 19/12/2023.
//

#include "EndScene.hpp"
#include "HomeScene.hpp"

EndScene::EndScene() : StoryScene(
        {
                "As I stand in the ancient grove, the air",
                "crackles with a newfound energy. The harmony",
                "between nature and the undead, once an enigma,",
                "now unfolds before my eyes. The beer, my",
                "ever-faithful companion, has become a",
                "conduit between worlds, a bridge between the living",
                " and the undead. In the fading light of the setting",
                "sun, I take a final sip from the enchanted beer.",
                "The bitterness of survival and the sweetness of",
                "nostalgia blend into a taste that transcends",
                "time. With a sense of accomplishment and a",
                "heart filled with gratitude, I embark on a",
                "new journey, no longer just a survivor, but",
                "a guardian of the delicate balance between",
                "life, death, and the enduring spirit of the wild.",
                " ",
                "Press enter to continue..."
        }, new HomeScene()) {}

void EndScene::build() {
    StoryScene::build();
}