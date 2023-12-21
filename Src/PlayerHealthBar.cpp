//
// Created by Olaf van den Berg on 18/12/2023.
//

#include "PlayerHealthBar.hpp"
#include "Components/TransformComponent.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"

PlayerHealthBar::PlayerHealthBar() : GameObject() {
    this->setName("PlayerHealthBar");

    //Position
    auto &transform = this->tryGetComponent<TransformComponent>();
    auto windowSize = ConfigSingleton::getInstance().getInitialWindowSize();
    transform.position = std::make_unique<Vector2>(0, windowSize.getY() - 32);


}

