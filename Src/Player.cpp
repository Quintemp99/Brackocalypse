//
// Created by SKIKK on 17/11/2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Helpers/Vector2.hpp>
#include <Components/SoundEffectComponent.hpp>
#include "Player.hpp"
#include "../Scripts/UserInputMovement.hpp"
#include "../Scripts/WalkingSound.hpp"

Player::Player(size_t layer) : GameObject() {
    addComponent(std::make_unique<VelocityComponent>());
    addComponent(std::make_unique<UserInputMovement>());
    auto sprite = std::make_unique<SpriteComponent>();
    auto &transform = tryGetComponent<TransformComponent>();
    sprite->spritePath = "Sprites/character_maleAdventurer_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96, 128);
    sprite->margin = 5;
    sprite->sortingLayer = layer;
    transform.scale =std::make_unique<Vector2>(1,1);
    sprite->tileOffset = std::make_unique<Vector2>(0,0);

    auto audioComponent = std::make_unique<SoundEffectComponent>("Sounds/footsteps.mp3");
    audioComponent->volume = 0.05;
    addComponent(std::move(audioComponent));
    addComponent(std::make_unique<WalkingSound>());

    addComponent(std::move(sprite));
    setTag("Player");
}
