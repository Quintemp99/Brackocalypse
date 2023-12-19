//
// Created by Olaf van den Berg on 19-12-2023.
//

#include <Components/BoxCollisionComponent.hpp>
#include "EnemyDamage.hpp"
#include "TakeDamage.hpp"

void EnemyDamage::onStart() {
}

void EnemyDamage::onUpdate(milliseconds deltaTime) {
    auto &playerCollision = getGameObjectByTag("Player")->tryGetComponent<BoxCollisionComponent>();
    auto enemies = getGameObjectsByTag("EnemyCollision");

    for (auto &id: playerCollision.collidedWith) {
        auto it = std::find_if(enemies.begin(), enemies.end(), [id](GameObject *e) {
            return e->getParent()->getEntityId() == id;
        });

        if (it != enemies.end()) {
            auto player = getGameObjectByName("Player");
            if (player.has_value()) {
                if (damageTimer >= damageCooldown) {
                    damageTimer -= damageCooldown;
                    auto &takeDamage = player.value()->tryGetBehaviourScript<TakeDamage>();
                    takeDamage.doDamage(damage);
                }
                damageTimer += deltaTime;
            }
        }
    }
}
