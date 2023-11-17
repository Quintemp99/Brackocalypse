//
// Created by SKIKK on 17/11/2023.
//

#include <Components/IComponent.hpp>

#ifndef BRACKOCALYPSE_PLAYERCOMPONENT_HPP
#define BRACKOCALYPSE_PLAYERCOMPONENT_HPP

struct PlayerComponent : public IComponent{
public:
    PlayerComponent() : IComponent() {}

    PlayerComponent(const PlayerComponent& other) : IComponent(other) {}

    virtual std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<PlayerComponent>(*this);
    }

    void Accept(ComponentVisitor &visitor) override {
        visitor.visit<PlayerComponent>(*this);
    }
};
#endif //BRACKOCALYPSE_PLAYERCOMPONENT_HPP
