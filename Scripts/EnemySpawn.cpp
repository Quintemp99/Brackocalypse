//
// Created by Olaf van den Berg on 12-12-2023.
//

#include <Components/TransformComponent.hpp>
#include "EnemySpawn.hpp"
#include "../Src/Enemy.hpp"

void EnemySpawn::onStart() {
}

void EnemySpawn::onUpdate(milliseconds deltaTime) {
    if (currentEnemyCount == 0) {
        auto enemies = getGameObjectsByTag("Enemy");
        for (auto &enemy: enemies) {
            enemy->setActive(true);
            auto enemyPtr = dynamic_cast<Enemy *>(enemy);
            if (enemyPtr != nullptr)
                enemyPtr->health = 3;
            auto &transform = enemy->tryGetComponent<TransformComponent>();
            transform.position = std::make_unique<Vector2>(-680, 210);
            break;
        }
        currentEnemyCount = enemies.size();

    }
}
