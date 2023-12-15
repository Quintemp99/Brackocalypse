//
// Created by jesse on 15/12/2023.
//

#include <Components/BoxCollisionComponent.hpp>
#include "BulletHitEnemy.hpp"
#include "BulletActions.hpp"
#include <algorithm>

void BulletHitEnemy::onStart() {}

void BulletHitEnemy::onUpdate(milliseconds deltaTime) {
    auto &boxCollision = tryGetComponent<BoxCollisionComponent>();
    auto &bulletActions = tryGetBehaviourScript<BulletActions>();
    auto enemies = getGameObjectsByTag("EnemyCollision");

    for (auto &id: boxCollision.collidedWith) {
        auto it = std::find_if(enemies.begin(), enemies.end(), [id](GameObject *e) {
            return e->getEntityId() == id;
        });
        if (it != enemies.end()) {
            auto enemy = (*it)->getParent();
            if (enemy.has_value()) {
                boxCollision.collidedWith.clear();
                enemy.value().setActive(false);
            }
            bulletActions.setInactive();
            return;
        }
    }
}
