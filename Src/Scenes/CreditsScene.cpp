//
// Created by stijn on 21-12-2023.
//

#include "CreditsScene.hpp"
#include "../../../Brack-Engine/src/ConfigSingleton.hpp"
#include "Components/SoundTrackComponent.hpp"

std::unique_ptr<GameObject> CreditsScene::createText(std::string text) {
    auto textObj = std::make_unique<GameObject>();
    auto textComp = std::make_unique<TextComponent>();
    textComp->text = text;
    textComp->fontSize = 40;
    textObj->addComponent(std::move(textComp));

    auto& transform = textObj->tryGetComponent<TransformComponent>();
    auto bottomY = (ConfigSingleton::getInstance().getWindowSize().getY() / 2) + 20;
    transform.position->setY(bottomY);

    return std::move(textObj);
}

void CreditsScene::add(std::unique_ptr<GameObject> component) {
    component->setTag("Credit");
    component->setActive(false);

    addGameObject(std::move(component));
}

void CreditsScene::build() {
    Scene::build();
    auto camera = getAllCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(0, 255, 0, 255));
    camera->addBehaviourScript(CreditsScroll());
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/atje.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));

    add(createText("Brackopolypse"));
    add(createText("Made by:"));
    add(createText("Olaf"));
    add(createText("Quin"));
    add(createText("Stef"));
    add(createText("Jesse"));
    add(createText("Stijn"));
}
