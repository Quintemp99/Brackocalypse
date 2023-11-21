//
// Created by SKIKK on 17/11/2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Helpers/Vector2.hpp>
#include "Player.hpp"
#include "../Scripts/CameraFocussedUserInput.hpp"

Player::Player() : GameObject() {
    AddComponent(std::make_unique<VelocityComponent>());
    auto sprite = std::make_unique<SpriteComponent>();
    auto& transform = TryGetComponent<TransformComponent>();
    sprite->spritePath = "Sprites/character_maleAdventurer_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96,128);
    sprite->margin = 5;
    sprite->sortingLayer = 1;
    transform.scale =std::make_unique<Vector2>(1,1);
    sprite->tileOffset = std::make_unique<Vector2>(0,0);
    AddComponent(std::move(sprite));
}
