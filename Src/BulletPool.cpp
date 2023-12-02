//
// Created by jesse on 02/12/2023.
//

#include "BulletPool.hpp"

BulletPool::BulletPool(size_t layer, size_t poolSize) {
    setTag("BulletPool");
    setName("BulletPool");
    for (size_t i = 0; i < poolSize; i++) {
        auto bullet = std::make_unique<Bullet>(layer);
        bullet->setActive(false);
        addChild(*bullet);
    }
}
