//
// Created by jesse on 30/11/2023.
//

#include "GunFollowMouse.hpp"
#include <EngineManagers/InputManager.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>

void GunFollowMouse::onStart() {
}

void GunFollowMouse::onUpdate(float deltaTime) {
    auto position = InputManager::GetInstance().getWorldMousePosition();
    auto &transformComponent = tryGetComponent<TransformComponent>();

    auto &parentTransformComponent = getParent().value().tryGetComponent<TransformComponent>();
    auto &parentPosition = parentTransformComponent.position;

    auto deltaX = position.getX() - parentPosition->getX();
    auto deltaY = position.getY() - parentPosition->getY();

    auto angle = atan2(deltaY, deltaX);

    float degrees = angle * 180 / M_PI;

    auto &spriteComponent = tryGetComponent<SpriteComponent>();
    if (deltaX < 0) {
        spriteComponent.flipX = true;
        degrees += 180;
    } else {
        spriteComponent.flipX = false;
    }
    transformComponent.rotation = degrees;
    auto newXPosition = cos(angle) * distanceFromPlayer;
    auto newYPosition = sin(angle) * distanceFromPlayer;
    transformComponent.position = std::make_unique<Vector2>(newXPosition, newYPosition);
}
