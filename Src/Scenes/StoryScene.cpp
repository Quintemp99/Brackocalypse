//
// Created by SKIKK on 19/12/2023.
//

#include <Objects/Text.hpp>
#include <Components/TextComponent.hpp>
#include <sstream>
#include <Components/SoundEffectComponent.hpp>
#include "StoryScene.hpp"
#include "../Scripts/WriteTextAnimation.hpp"


StoryScene::StoryScene(std::vector<std::string> lines) : Scene(), lines_(lines) {
}

void StoryScene::build() {
    Scene::build();
    auto camera = getAllCameras()[0];
    camera->SetBackgroundColor(Color(0, 0, 0, 255));
    camera->addBehaviourScript(WriteTextAnimation(lines_));
    auto soundComponent = std::make_unique<SoundEffectComponent>("Sounds/type-sound1.mp3");
    soundComponent->volume = 0.1;
    camera->addComponent(std::move(soundComponent));

    Vector2 startText = Vector2(50, 50);

    int lineNumber = 0;
    for (auto &line: lines_) {
        std::stringstream tag;
        tag << "Line" << lineNumber;

        auto text = std::make_unique<Text>(" ");
        text->SetFontSize(16);
        text->SetColor(Color(255, 255, 255, 255));
        text->setTag(tag.str());
        text->tryGetComponent<TransformComponent>().position = std::make_unique<Vector2>(startText);
        text->tryGetComponent<TextComponent>().sortingLayer = 0;
        startText.setY(startText.getY() + 35);
        addGameObject(std::move(text));
        lineNumber++;
    }
}
