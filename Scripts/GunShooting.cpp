//
// Created by jesse on 30/11/2023.
//

#include <EngineManagers/InputManager.hpp>
#include <Helpers/MouseMap.hpp>
#include <Components/AnimationComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <EngineManagers/SceneManager.hpp>
#include <Components/SpriteComponent.hpp>
#include "GunShooting.hpp"

void GunShooting::onStart() {

}

void GunShooting::onUpdate(float deltaTime) {
    auto &animationComponent = tryGetComponent<AnimationComponent>();
    if (InputManager::GetInstance().IsMousePressed(LEFT_MOUSE)) {
        if (!animationComponent.isPlaying) {
            shoot();
            animationComponent.currentFrame = 0;
            animationComponent.isPlaying = true;
        } else if (animationComponent.currentFrame == 1) {
            auto cameraId = ComponentStore::GetInstance().getEntitiesWithComponent<CameraComponent>()[0];
            auto &cameraPosition = ComponentStore::GetInstance().tryGetComponent<TransformComponent>(cameraId);
            shaking = true;
            originalCameraPosition = *cameraPosition.position;
        }
    }

    if (shaking) {
        cameraShakeTimer += deltaTime;
        shakeCamera();
    }
}

void GunShooting::shakeCamera() {
    auto cameraId = ComponentStore::GetInstance().getEntitiesWithComponent<CameraComponent>()[0];
    auto &cameraPosition = ComponentStore::GetInstance().tryGetComponent<TransformComponent>(cameraId);
    if (cameraShakeTimer >= cameraShakeDuration) {
        cameraShakeTimer = 0.0f;
        shaking = false;
        cameraPosition.position = std::make_unique<Vector2>(originalCameraPosition);
        return;
    }

    float offsetX = cameraShakeIntensity * distribution(randomGenerator);
    float offsetY = cameraShakeIntensity * distribution(randomGenerator);


    cameraPosition.position = std::make_unique<Vector2>(cameraPosition.position->getX() + offsetX,
                                                        cameraPosition.position->getY() + offsetY);

}

void GunShooting::shoot() {
    for (auto &bullet: getGameObjectsByTag("Bullet")) {
        if (!bullet.isActive()) {
            bullet.setActive(true);
            auto &transform = bullet.tryGetComponent<TransformComponent>();
            auto &gunTransform = tryGetComponent<TransformComponent>();
            auto &spriteComponent = tryGetComponent<SpriteComponent>();
            transform.position = std::make_unique<Vector2>(gunTransform.position->getX(),
                                                           gunTransform.position->getY());
            auto rotation = gunTransform.rotation;
            if (spriteComponent.flipX)
                rotation += 180;
            transform.rotation = rotation;

            return;
        }
    }
}
