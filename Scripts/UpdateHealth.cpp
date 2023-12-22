//
// Created by Olaf van den Berg on 18/12/2023.
//

#include "UpdateHealth.hpp"
#include <Components/RectangleComponent.hpp>
#include "../Src/Components/HealthComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "EngineManagers/SceneManager.hpp"
#include "Components/SpriteComponent.hpp"

void UpdateHealth::onStart() {
    auto healtBar = getGameObjectByName("PlayerHealthBar");
    if (!healtBar.has_value())
        return;
    auto player = SceneManager::getInstance().getGameObjectByName("Player");
    if (player.has_value()) {
        auto playerHealth = player.value()->tryGetComponent<HealthComponent>();
        for (auto i = 0; i < playerHealth.maxHealth; i++) {
            auto health = std::make_unique<GameObject>();
            health->setTag("Health");
            auto &healthTransform = health->tryGetComponent<TransformComponent>();
            healthTransform.position = std::make_unique<Vector2>(i * 38, 0);
            auto sprite = std::make_unique<SpriteComponent>();
            sprite->spritePath = "Sprites/heart_full.png";
            sprite->spriteSize = std::make_unique<Vector2>(36, 32);
            sprite->tileOffset = std::make_unique<Vector2>(0, 0);
            sprite->sortingLayer = 0;
            health->addComponent(std::move(sprite));
            healtBar.value()->addChild(std::move(health));
        }
    }

    auto wifeHealtBar = getGameObjectByName("WifeHealthBar");
    if (!wifeHealtBar.has_value())
        return;
    auto wife = SceneManager::getInstance().getGameObjectByName("Wife");
    if (wife.has_value()) {
        auto wifeHealth = wife.value()->tryGetComponent<HealthComponent>();
        for (auto i = 0; i < wifeHealth.maxHealth; i++) {
            auto health = std::make_unique<GameObject>();
            health->setTag("Health");
            auto &healthTransform = health->tryGetComponent<TransformComponent>();
            healthTransform.position = std::make_unique<Vector2>(i * 38, 0);
            auto sprite = std::make_unique<SpriteComponent>();
            sprite->spritePath = "Sprites/heart_full.png";
            sprite->spriteSize = std::make_unique<Vector2>(36, 32);
            sprite->tileOffset = std::make_unique<Vector2>(0, 0);
            sprite->sortingLayer = 0;
            health->addComponent(std::move(sprite));
            wifeHealtBar.value()->addChild(std::move(health));
        }
    }
}

void UpdateHealth::onUpdate(milliseconds deltaTime) {
    auto healtBar = getGameObjectByName("PlayerHealthBar");

    auto player = getGameObjectByName("Player");
    if (player.has_value()) {
        auto playerHealth = player.value()->tryGetComponent<HealthComponent>().health;
        auto healthObjs = healtBar.value()->getChildren();

        for (int i = 0; i < healthObjs.size(); i++) {
            auto &sprite = healthObjs[i]->tryGetComponent<SpriteComponent>();
            if (i <= playerHealth - 1) {
                continue;
            }
            sprite.spritePath = "Sprites/heart_empty.png";
        }
    }

    auto wifeHealtBar = getGameObjectByName("WifeHealthBar");

    auto wife = getGameObjectByName("Wife");
    if (wife.has_value()) {
        auto wifeHealth = wife.value()->tryGetComponent<HealthComponent>().health;
        auto healthObjs = wifeHealtBar.value()->getChildren();

        for (int i = 0; i < healthObjs.size(); i++) {
            auto &sprite = healthObjs[i]->tryGetComponent<SpriteComponent>();
            if (i <= wifeHealth - 1) {
                continue;
            }
            sprite.spritePath = "Sprites/heart_empty.png";

        }
    }

    auto enemies = getGameObjectsByTag("EnemyHealth");
    for (auto enemie: enemies) {
        enemie->getParent()->tryGetComponent<HealthComponent>();
        auto healthObjs = enemie->getChildren();
        for (int i = 0; i < healthObjs.size(); i++) {
            auto &sprite = healthObjs[i]->tryGetComponent<SpriteComponent>();
            if (i <= enemie->getParent()->tryGetComponent<HealthComponent>().health - 1) {
                continue;
            }
            sprite.spritePath = "Sprites/heart_empty.png";
        }
    }
}





