//
// Created by SKIKK on 17/11/2023.
//

#include <EngineManagers/InputManager.hpp>
#include <Helpers/KeyMap.hpp>
#include <Components/SoundEffectComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include "UserInputMovement.hpp"
#include "Components/VelocityComponent.hpp"

void UserInputMovement::onStart() {}

void UserInputMovement::onUpdate(milliseconds deltaTime) {
    auto &playerVelocityComponent = tryGetComponent<VelocityComponent>();
    auto &spriteComponent = tryGetComponent<SpriteComponent>();
    auto &walkAnimation = tryGetComponent<AnimationComponent>();
//    auto &soundEffect = tryGetComponent<SoundEffectComponent>();

    int left = static_cast<int>(InputManager::GetInstance().IsKeyPressed(KeyMap::a) ||
                                InputManager::GetInstance().IsKeyPressed(KeyMap::LEFT));
    int right = static_cast<int>(InputManager::GetInstance().IsKeyPressed(KeyMap::d) ||
                                 InputManager::GetInstance().IsKeyPressed(KeyMap::RIGHT));
    int up = static_cast<int>(InputManager::GetInstance().IsKeyPressed(KeyMap::w) ||
                              InputManager::GetInstance().IsKeyPressed(KeyMap::UP));
    int down = static_cast<int>(InputManager::GetInstance().IsKeyPressed(KeyMap::s) ||
                                InputManager::GetInstance().IsKeyPressed(KeyMap::DOWN));


    auto horizontalMovement = right - left;
    auto verticalMovement = down - up;

    float magnitude = std::sqrt(horizontalMovement * horizontalMovement + verticalMovement * verticalMovement);

    // Normalize the movement vector (make sure its length is 1)
    float normalizedHorizontalMovement = (magnitude > 0) ? horizontalMovement / magnitude : 0;
    float normalizedVerticalMovement = (magnitude > 0) ? verticalMovement / magnitude : 0;

    // Set the player's velocity based on the normalized input and desired speed
    playerVelocityComponent.velocity.setX(normalizedHorizontalMovement * velocity);
    playerVelocityComponent.velocity.setY(normalizedVerticalMovement * velocity);

    if (normalizedHorizontalMovement > 0) {
        spriteComponent.flipX = false;
    } else if (normalizedHorizontalMovement < 0) {
        spriteComponent.flipX = true;
    }

    if (playerVelocityComponent.velocity == Vector2(0, 0)) {
        walkAnimation.isPlaying = false;
        spriteComponent.tileOffset = std::make_unique<Vector2>(0, 0);
    } else {
        walkAnimation.isPlaying = true;
        if (walkAnimation.currentFrame == 0 || walkAnimation.currentFrame == 4) {
//            soundEffect.startPlaying = true;
        }
    }
}