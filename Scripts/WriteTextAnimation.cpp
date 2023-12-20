//
// Created by SKIKK on 19/12/2023.
//

#include "WriteTextAnimation.hpp"
#include <sstream>
#include <Components/TextComponent.hpp>
#include <Components/SoundEffectComponent.hpp>
#include <RandomGenerator.hpp>
#include <EngineManagers/InputManager.hpp>
#include <Helpers/KeyMap.hpp>

void WriteTextAnimation::onUpdate(milliseconds deltaTime) {
    if (InputManager::GetInstance().IsKeyClicked(KeyMap::RETURN)) {
        nextScene->build();
        SceneManager::getInstance().goToNewScene(nextScene);
    }

    if (charPos == lines[linePos].length()) {
        charPos = 0;
        linePos++;
    }
    if (linePos == lines.size()) {
        return;
    };

    if (lastWrite <= 0) {
        if (lastSound <= 0) {
            int randomIndexSound = RandomGenerator::randomInt(0, 3);
            auto &soundComponent = tryGetComponent<SoundEffectComponent>();
            soundComponent.startPlaying = true;
            soundComponent.audioPath = soundPaths[randomIndexSound];
            lastSound = soundInterval;
        } else
            lastSound -= deltaTime;
        lastWrite = writeInterval;
        std::stringstream tag;
        tag << "Line" << linePos;
        auto textObject = getGameObjectByTag(tag.str());
        auto &textComponent = textObject->tryGetComponent<TextComponent>();
        textComponent.text += lines[linePos][charPos];
        charPos++;
    } else {
        lastWrite -= deltaTime;
    }
}

WriteTextAnimation::~WriteTextAnimation() {
}

void WriteTextAnimation::onStart() {
}
