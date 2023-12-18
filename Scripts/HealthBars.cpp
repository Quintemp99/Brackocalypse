//
// Created by Olaf van den Berg on 18/12/2023.
//

#include "HealthBars.hpp"
#include <Components/RectangleComponent.hpp>
#include "../Src/Components/HealthComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "EngineManagers/SceneManager.hpp"
#include "Components/SpriteComponent.hpp"

void HealthBars::onStart() {
    auto healtBar = getGameObjectByName("HealthBar");
    if (!healtBar.has_value())
        return;
    auto player = SceneManager::getInstance().getGameObjectByName("Player");
    if (player.has_value()) {
        auto playerHealth = player.value()->tryGetComponent<HealthComponent>();
        for (auto i = 0; i < 3; i++) {
            auto health = std::make_unique<GameObject>();
            auto &healthTransform = health->tryGetComponent<TransformComponent>();
            healthTransform.position = std::make_unique<Vector2>(i * 32, 0);
            auto sprite = std::make_unique<SpriteComponent>();
            sprite->spritePath = "Sprites/health_full.png";
            sprite->spriteSize = std::make_unique<Vector2>(32, 32);
            sprite->tileOffset = std::make_unique<Vector2>(0, 0);
            sprite->sortingLayer = 0;
            health->addComponent(std::move(sprite));
            healtBar.value()->addChild(std::move(health));
        }
    }
}

void HealthBars::onUpdate(milliseconds deltaTime) {
    auto healtBar = getGameObjectByName("HealthBar");

    auto player = getGameObjectByName("Player");
    if (player.has_value()) {
        auto playerHealth = player.value()->tryGetComponent<HealthComponent>().health;

    }

}
