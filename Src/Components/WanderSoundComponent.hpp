//
// Created by SKIKK on 18/12/2023.
//

#ifndef BRACKOCALYPSE_WANDERSOUNDCOMPONENT_HPP
#define BRACKOCALYPSE_WANDERSOUNDCOMPONENT_HPP

#include <Components/SoundEffectComponent.hpp>
#include <utility>

struct WanderSoundComponent : public SoundEffectComponent{
    explicit WanderSoundComponent(std::string path) : SoundEffectComponent(std::move(path)) {
    }

    ~WanderSoundComponent() override = default;

    virtual std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<WanderSoundComponent>(*this);
    }

};

#endif //BRACKOCALYPSE_WANDERSOUNDCOMPONENT_HPP
