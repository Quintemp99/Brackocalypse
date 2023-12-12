//
// Created by jesse on 04/12/2023.
//

#include "BulletActions.hpp"

void BulletActions::onStart() {
}

void BulletActions::onUpdate(milliseconds deltaTime) {
    timer += deltaTime;
    if (timer >= lifeTime) {
        timer = 0.0f;
        setActive(false);
    }
}
