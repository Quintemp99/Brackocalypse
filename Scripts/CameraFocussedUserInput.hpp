//
// Created by SKIKK on 21/11/2023.
//
#include <Components/BehaviourScript.hpp>
#include <Components/VelocityComponent.hpp>
#include <Helpers/KeyMap.hpp>
#include <Objects/Camera.hpp>
#include "EngineManagers/InputManager.hpp"
#include "../Src/Level.hpp"


#ifndef BRACKOCALYPSE_USERINPUT_HPP
#define BRACKOCALYPSE_USERINPUT_HPP

class CameraFocussedUserInput : public BehaviourScript {
public:
    CameraFocussedUserInput() : BehaviourScript() {}

    ~CameraFocussedUserInput() override = default;

    virtual void onStart() override;

    virtual void onUpdate(float deltaTime) override;

    std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<CameraFocussedUserInput>(*this);
    }

    void Accept(ComponentVisitor &visitor) override {
        visitor.visit(*this);
        onStart();
    }

    CameraFocussedUserInput(const CameraFocussedUserInput& other) : BehaviourScript(other) {}
private:
    float velocity = 250.0;
};

#endif //BRACKOCALYPSE_USERINPUT_HPP
