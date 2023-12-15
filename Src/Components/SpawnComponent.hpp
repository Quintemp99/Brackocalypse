//
// Created by Olaf van den Berg on 14/12/2023.
//

#ifndef BRACKOCALYPSE_SPAWNCOMPONENT_HPP
#define BRACKOCALYPSE_SPAWNCOMPONENT_HPP

#include <Helpers/Vector2.hpp>
#include <memory>
#include <vector>
#include "Components/IComponent.hpp"

struct SpawnComponent : public IComponent {
    explicit SpawnComponent() : IComponent() {}

    ~SpawnComponent() override = default;

    std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<SpawnComponent>(*this);
    }

    SpawnComponent(const SpawnComponent &other) {
        if (!other.spawnLocations.empty())
            for (const auto &ptr: other.spawnLocations) {
                if (ptr != nullptr) {
                    spawnLocations.push_back(std::make_unique<Vector2>(*ptr));
                } else {
                    spawnLocations.push_back(nullptr);
                }
            }
    }

    std::vector<std::unique_ptr<Vector2>> spawnLocations;

};

#endif //BRACKOCALYPSE_SPAWNCOMPONENT_HPP
