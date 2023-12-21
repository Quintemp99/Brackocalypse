#include "ProgressBar.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "Components/SpriteComponent.hpp"

#include <Components/RectangleComponent.hpp>
#include <Components/TransformComponent.hpp>

ProgressBar::ProgressBar(Vector2 size) : GameObject() {
    this->setTag("ProgressBar");

    //Position
    auto& transformBgImage = this->tryGetComponent<TransformComponent>();
    auto screenSize = ConfigSingleton::getInstance().getInitialWindowSize();
    transformBgImage.position = std::make_unique<Vector2>(screenSize.getX() / 2 - size.getX() / 2, 10);

    //Background
    auto backRecObj = std::make_unique<GameObject>();
    backRecObj->setTag("ProgressBarBackground");
    backRecObj->setName("ProgressBarBackground");
    auto backRec = std::make_unique<RectangleComponent>(size);
    backRec->fill = std::make_unique<Color>(168, 168, 168, 1);
    backRec->sortingLayer = 0;
    backRec->orderInLayer = 2;
    backRecObj->addComponent(std::move(backRec));

    //Progress
    Vector2 sizeProgress = Vector2(0, size.getY());
    auto frontRec = std::make_unique<RectangleComponent>(sizeProgress);
    frontRec->fill = std::make_unique<Color>(254, 218, 44, 1);
    frontRec->sortingLayer = 0;
    frontRec->orderInLayer = 1;
    
    auto beerImage = std::make_unique<GameObject>();
    beerImage->setName("BeerImage");
    beerImage->setTag("BeerImage");
    auto beerImageSprite = std::make_unique<SpriteComponent>();
    beerImageSprite->spritePath = "Sprites/beer.png";
    beerImageSprite->spriteSize = std::make_unique<Vector2>(512, 512);
    beerImageSprite->tileOffset = std::make_unique<Vector2>(0, 0);
    beerImageSprite->orderInLayer = 0;
    beerImageSprite->sortingLayer = 0;
    auto& transformBeerImage = beerImage->tryGetComponent<TransformComponent>();
    transformBeerImage.position = std::make_unique<Vector2>(-20, -10);
    transformBeerImage.scale = std::make_unique<Vector2>(0.1, 0.1);
    
    beerImage->addComponent(std::move(beerImageSprite));
    
    this->addComponent(std::move(frontRec));
    this->addChild(std::move(backRecObj));
    this->addChild(std::move(beerImage));
}