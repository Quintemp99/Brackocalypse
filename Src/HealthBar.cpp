//
// Created by Olaf van den Berg on 18/12/2023.
//

#include "HealthBar.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "EngineManagers/SceneManager.hpp"
#include "Components/HealthComponent.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"

HealthBar::HealthBar() : GameObject() {
    this->setName("HealthBar");

    //Position
    auto &transform = this->tryGetComponent<TransformComponent>();
    auto windowSize = ConfigSingleton::getInstance().getWindowSize();
    transform.position = std::make_unique<Vector2>(0, windowSize.getY() - 32);


}

//}