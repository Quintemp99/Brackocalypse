//
// Created by qtemp on 21-12-2023.
//

#include "WifeComplaints.hpp"

#include "RandomGenerator.hpp"
#include "../Src/Components/WanderSoundComponent.hpp"
#include "Components/SoundEffectComponent.hpp"

void WifeComplaints::onStart() {
}

void WifeComplaints::onUpdate(milliseconds deltaTime) {
    if (lastSound <= 0) {
        int randomIndexSound = RandomGenerator::randomInt(0, soundPaths.size() - 1);
        auto &soundComponent = tryGetComponent<WanderSoundComponent>();
        soundComponent.startPlaying = true;
        soundComponent.audioPath = soundPaths[randomIndexSound];
        lastSound = soundInterval;
    } else
    {
        lastSound -= deltaTime;
    }
}