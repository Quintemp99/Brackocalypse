//
// Created by SKIKK on 23/11/2023.
//

#include <Components/TransformComponent.hpp>
#include "FollowGameObject.hpp"
#include "Components/TransformComponent.hpp"

void FollowGameObject::onStart() {
}

void FollowGameObject::onUpdate(milliseconds deltaTime) {
    auto playerGameObject = getGameObjectByTag(followGameObjectTag);
    if (!playerGameObject.has_value()) return;
    auto &playerTransform = playerGameObject.value().tryGetComponent<TransformComponent>();

    auto &cameraTransformComponent = tryGetComponent<TransformComponent>();

    auto yDistance = playerTransform.position->getY() - cameraTransformComponent.position->getY();
    auto xDistance = playerTransform.position->getX() - cameraTransformComponent.position->getX();

    if (yDistance > moveCameraMargin) {
        cameraTransformComponent.position->setY(playerTransform.position->getY() - moveCameraMargin);
    } else if (yDistance < -moveCameraMargin) {
        cameraTransformComponent.position->setY(playerTransform.position->getY() + moveCameraMargin);
    }

    if (xDistance > moveCameraMargin) {
        cameraTransformComponent.position->setX(playerTransform.position->getX() - moveCameraMargin);
    } else if (xDistance < -moveCameraMargin) {
        cameraTransformComponent.position->setX(playerTransform.position->getX() + moveCameraMargin);
    }
}