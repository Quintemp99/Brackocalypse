//
// Created by jesse on 30/11/2023.
//

#include <Components/SpriteComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Components/SoundEffectComponent.hpp>
#include <Components/TransformComponent.hpp>
#include "Gun.hpp"
#include "../Scripts/GunFollowMouse.hpp"
#include "../Scripts/GunShooting.hpp"

Gun::Gun(size_t layer) : GameObject() {
    auto sprite = std::make_unique<SpriteComponent>();
    auto &transform = tryGetComponent<TransformComponent>();
//    auto boxCollider = std::make_unique<BoxCollisionComponent>(Vector2(80, 28));
    auto animation = std::make_unique<AnimationComponent>();
    sprite->spritePath = "Sprites/Guns/Pistol_Shooting.png";
    sprite->spriteSize = std::make_unique<Vector2>(80, 28);
    sprite->sortingLayer = layer;
    transform.scale = std::make_unique<Vector2>(2, 2);
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);
    animation->isLooping = false;
    animation->isPlaying = false;
    animation->frameCount = 11;
    animation->fps = 45;
    animation->imageSize = std::make_unique<Vector2>(880, 48);
    animation->startPosition = std::make_unique<Vector2>(0, 0);
    addComponent(std::move(sprite));
    addComponent(std::move(animation));
    auto audioComponent = std::make_unique<SoundEffectComponent>("Sounds/single-shot-gun-sound.mp3");
    audioComponent->volume = 0.05;
    addComponent(std::move(audioComponent));
    addBehaviourScript(std::make_unique<GunFollowMouse>());
    addBehaviourScript(std::make_unique<GunShooting>());
    setTag("Gun");
    setName("Gun");
}
