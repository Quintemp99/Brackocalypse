//
// Created by qtemp on 21-12-2023.
//

#include "WifeDeath.hpp"

#include "../Components/HealthComponent.hpp"
#include "../Scenes/LevelManager.hpp"

void WifeDeath::onStart() {
}

void WifeDeath::onUpdate(milliseconds deltaTime) {
    auto &healthComponent = tryGetComponent<HealthComponent>();
    if (healthComponent.health <= 0) {
        LevelManager::getInstance().goToNextLevel();
    }
}

