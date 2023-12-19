//
// Created by jesse on 15/12/2023.
//

#include <Components/SoundEffectComponent.hpp>
#include "TakeDamage.hpp"
#include "../Src/Components/HealthComponent.hpp"

void TakeDamage::onStart() {}

void TakeDamage::onUpdate(milliseconds deltaTime) {
    auto &health = tryGetComponent<HealthComponent>();
    if (health.health <= 0) {
        auto tag = tryGetComponent<ObjectInfoComponent>().tag;
        if (tag == "Enemy") {
            setActive(false);
        }
    }
}

void TakeDamage::doDamage(int damage) {
    auto &health = tryGetComponent<HealthComponent>();
    auto tag = tryGetComponent<ObjectInfoComponent>().tag;
    if (tag == "Enemy") {
        auto &hitSound = tryGetComponent<SoundEffectComponent>();
        hitSound.startPlaying = true;
    }
    health.health -= damage;
}
