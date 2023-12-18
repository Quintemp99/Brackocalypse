//
// Created by jesse on 15/12/2023.
//

#include <Components/SoundEffectComponent.hpp>
#include "TakeDamage.hpp"
#include "../Src/Components/HealthComponent.hpp"
#include "../Src/Components/HitSoundComponent.hpp"

void TakeDamage::onStart() {}

void TakeDamage::onUpdate(milliseconds deltaTime) {
    auto &health = tryGetComponent<HealthComponent>();
    if (health.health <= 0) {
        setActive(false);
    }
}

void TakeDamage::doDamage(int damage) {
    auto &health = tryGetComponent<HealthComponent>();
    auto &hitSound = tryGetComponent<HitSoundComponent>();
    hitSound.startPlaying = true;
    health.health -= damage;
}
