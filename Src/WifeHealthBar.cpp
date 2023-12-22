//
// Created by qtemp on 21-12-2023.
//

#include "WifeHealthBar.hpp"
#include "Components/TransformComponent.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"

WifeHealthBar::WifeHealthBar(int size) : GameObject() {
    this->setName("WifeHealthBar");
    auto &transform = this->tryGetComponent<TransformComponent>();
    auto windowSize = ConfigSingleton::getInstance().getInitialWindowSize();
    transform.position = std::make_unique<Vector2>(windowSize.getX() / 2 - size / 2, 60);
}