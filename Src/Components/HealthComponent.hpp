//
// Created by Olaf van den Berg on 13/12/2023.
//

#ifndef BRACKOCALYPSE_HEALTHCOMPONENT_HPP
#define BRACKOCALYPSE_HEALTHCOMPONENT_HPP

#include "../../../Brack-Engine/outfacingInterfaces/Components/IComponent.hpp"

struct HealthComponent : public IComponent {
    explicit HealthComponent(int health) : IComponent(), health(health) {
    }

    ~HealthComponent() override = default;

    virtual std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<HealthComponent>(*this);
    }

    HealthComponent(const HealthComponent &other) : IComponent(other) {
        health = other.health;
    }

    int health;
};

#endif //BRACKOCALYPSE_HEALTHCOMPONENT_HPP
