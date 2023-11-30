//
// Created by SKIKK on 23/11/2023.
//

#ifndef BRACKOCALYPSE_ROGUELIKEMAPTILE_HPP
#define BRACKOCALYPSE_ROGUELIKEMAPTILE_HPP

#include <Objects/GameObject.hpp>
#include <Helpers/Vector2.hpp>
#include <Components/SpriteComponent.hpp>

struct RogueLikeMapTile : public GameObject {
    RogueLikeMapTile(Vector2 tileOffset, Vector2 position, Vector2 size, size_t layer) : GameObject() {
        auto spriteComponent = SpriteComponent();
        spriteComponent.spritePath = spritePath;
        spriteComponent.spriteSize = std::make_unique<Vector2>(spriteSize);
        spriteComponent.margin = spriteMargin;
        spriteComponent.tileOffset = std::make_unique<Vector2>(tileOffset);
        spriteComponent.sortingLayer = layer;
        addComponent(spriteComponent);
        auto &transform = tryGetComponent<TransformComponent>();
        transform.scale = std::make_unique<Vector2>(spriteScale);
        float posX = ((position.getX() * (spriteSize.getX() * spriteScale.getX())) +
                      ((spriteSize.getX() * spriteScale.getX()) / 2)) -
                     (size.getX() * (spriteScale.getX() * spriteSize.getX()) / 2);
        float posY = ((position.getY() * (spriteSize.getY() * spriteScale.getY())) +
                      ((spriteSize.getY() * spriteScale.getY()) / 2)) -
                     (size.getY() * (spriteSize.getY() * spriteScale.getY()) / 2);
        transform.position = std::make_unique<Vector2>(posX, posY);
    }

    ~RogueLikeMapTile() = default;

    int spriteMargin = 1;
    Vector2 spriteScale = Vector2(4, 4);
    Vector2 spriteSize = Vector2(16, 16);
    std::string spritePath = "Sprites/roguelikeSheet_transparent_1.bmp";
};

#endif //BRACKOCALYPSE_ROGUELIKEMAPTILE_HPP
