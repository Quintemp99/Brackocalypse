//
// Created by SKIKK on 17/11/2023.
//

#include <Components/BehaviourScript.hpp>
#include <Components/VelocityComponent.hpp>
#include <Components/TextComponent.hpp>
#include <Helpers/KeyMap.hpp>
#include "EngineManagers/InputManager.hpp"

class UserInput : public BehaviourScript {
public:
    UserInput() : BehaviourScript() {}

    ~UserInput() override = default;

    void OnStart() override {
    }

    void OnUpdate(float deltaTime) override {
        auto& velocityComponent = ComponentStore::GetInstance().tryGetComponent<VelocityComponent>(entityID);

        if (InputManager::GetInstance().IsKeyPressed(KeyMap::w) || InputManager::GetInstance().IsKeyPressed(KeyMap::UP)) {
            velocityComponent.velocity.setY(-100);
        } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::s) || InputManager::GetInstance().IsKeyPressed(KeyMap::DOWN)) {
            velocityComponent.velocity.setY(100);
        } else {
            velocityComponent.velocity.setY(0);
        }
        if (InputManager::GetInstance().IsKeyPressed(KeyMap::a) || InputManager::GetInstance().IsKeyPressed(KeyMap::LEFT)) {
            velocityComponent.velocity.setX(-100);
        } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::d) || InputManager::GetInstance().IsKeyPressed(KeyMap::RIGHT)) {
            velocityComponent.velocity.setX(100);
        } else {
            velocityComponent.velocity.setX(0);
        }
    }

    std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<UserInput>(*this);
    }

    void Accept(ComponentVisitor &visitor) override {
        visitor.visit(*this);
        OnStart();
    }

    UserInput(const BehaviourScript& other) : BehaviourScript(other) {}
};