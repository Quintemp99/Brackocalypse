//
// Created by jesse on 21/12/2023.
//

#include "PlayerProgress.hpp"
#include "../Scripts/PlayerProgressScript.hpp"
#include "Components/PersistenceTag.hpp"

PlayerProgress::PlayerProgress() {
    setTag("PlayerProgress");
    setName("PlayerProgress");
    addBehaviourScript(std::make_unique<PlayerProgressScript>(10, 3));
    addComponent(std::make_unique<PersistenceTag>());
}