//
// Created by Olaf van den Berg on 13-12-2023.
//

#include "EnemyPool.hpp"
#include "Enemy.hpp"

EnemyPool::EnemyPool(size_t layer, size_t poolSize) {
    setTag("EnemyPool");
    setName("EnemyPool");
    for (size_t i = 0; i < poolSize; i++) {
        auto bullet = std::make_unique<Enemy>(layer);
        bullet->setActive(false);
        addChild(std::move(bullet));
    }
}