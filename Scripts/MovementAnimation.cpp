//
// Created by Olaf van den Berg on 18-12-2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include "MovementAnimation.hpp"

void MovementAnimation::onStart() {

}

void MovementAnimation::onUpdate(milliseconds deltaTime) {
    auto &velocity = tryGetComponent<VelocityComponent>();
    auto &animation = tryGetComponent<AnimationComponent>();
    auto &sprite = tryGetComponent<SpriteComponent>();

    if (velocity.velocity.getX() != 0 || velocity.velocity.getY() != 0) {
        if (velocity.velocity.getX() > 0) {
            sprite.flipX = false;
        } else if (velocity.velocity.getX() < 0) {
            sprite.flipX = true;
        }
        animation.isPlaying = true;
    } else {
//        animation.isPlaying = false;
        sprite.tileOffset = std::make_unique<Vector2>(0, 0);

    }


}


