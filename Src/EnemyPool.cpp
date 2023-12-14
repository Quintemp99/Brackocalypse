//
// Created by Olaf van den Berg on 13-12-2023.
//

#include "EnemyPool.hpp"
#include "Enemy.hpp"
#include "Components/HealthComponent.hpp"

EnemyPool::EnemyPool(size_t layer, size_t poolSize) {
    setTag("EnemyPool");
    setName("EnemyPool");
    for (size_t i = 0; i < poolSize; i++) {
        auto enemy = std::make_unique<Enemy>(layer);
        enemy->setActive(false);
        addChild(std::move(enemy));
    }
}