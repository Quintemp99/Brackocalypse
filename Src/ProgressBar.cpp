#include "ProgressBar.hpp"

#include <Components/RectangleComponent.hpp>
#include <Components/TransformComponent.hpp>

ProgressBar::ProgressBar() : GameObject() {
    this->setTag("ProgressBar");

    //Position
    auto& transformBgImage = this->tryGetComponent<TransformComponent>();
    transformBgImage.position = std::make_unique<Vector2>(0, 40);

    //Background
    auto backRecObj = std::make_unique<GameObject>();
    Vector2 size = Vector2(totalWidth, 50);
    auto backRec = std::make_unique<RectangleComponent>(size);
    backRec->fill = std::make_unique<Color>(168, 168, 168, 1);
    backRec->sortingLayer = 0;
    backRecObj->addComponent(std::move(backRec));

    //Progress
    Vector2 sizeProgress = Vector2(0, 50);
    auto frontRec = std::make_unique<RectangleComponent>(sizeProgress);
    frontRec->fill = std::make_unique<Color>(254, 218, 44, 1);
    frontRec->sortingLayer = 0;
    
    this->addComponent(std::move(frontRec));
    this->addChild(std::move(backRecObj));
}