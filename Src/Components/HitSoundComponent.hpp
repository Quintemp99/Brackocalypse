//
// Created by SKIKK on 18/12/2023.
//

#ifndef BRACKOCALYPSE_HITSOUNDCOMPONENT_HPP
#define BRACKOCALYPSE_HITSOUNDCOMPONENT_HPP

#include <Components/SoundEffectComponent.hpp>
#include <utility>

struct HitSoundComponent : public SoundEffectComponent{
    explicit HitSoundComponent(std::string path) : SoundEffectComponent(std::move(path)) {
    }

    ~HitSoundComponent() override = default;

    virtual std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<HitSoundComponent>(*this);
    }

    HitSoundComponent(const HitSoundComponent &other) : SoundEffectComponent(other) {
    }

};
#endif //BRACKOCALYPSE_HITSOUNDCOMPONENT_HPP
