//
// Created by stijn on 21-12-2023.
//

#include "CreditsScene.hpp"
#include <ConfigSingleton.hpp>
#include "Components/SoundTrackComponent.hpp"
#include "Components/SpriteComponent.hpp"

std::unique_ptr<GameObject> CreditsScene::createText(std::string text) {
    auto textObj = std::make_unique<GameObject>();
    auto textComp = std::make_unique<TextComponent>();
    textComp->text = text;
    textComp->fontSize = 40;
    textComp->color = std::make_unique<Color>(255, 255, 255, 255);
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
    camera->SetBackgroundColor(Color(0, 0, 0, 255));
    camera->addBehaviourScript(CreditsScroll());
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/atje.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));

    add(createText("Brackopolypse"));
    add(createText("Made by:"));
    add(createText("Olaf"));
    add(createImage("Sprites/Credits/credit_olaf.png", Vector2(508, 662)));
    add(createText("Quin"));
    add(createImage("Sprites/Credits/credit_quin.png", Vector2(606, 580)));
    add(createText("Stef"));
    add(createImage("Sprites/Credits/credit_stef.png", Vector2(394, 713)));
    add(createText("Jesse"));
    add(createImage("Sprites/Credits/credit_jesse.png", Vector2(290, 565)));
    add(createText("Stijn"));
    add(createImage("Sprites/Credits/credit_stijn.png", Vector2(321, 530)));

    //Extra pictures
    add(createText("And other beautifully moments"));
    add(createImage("Sprites/Credits/credit_1.png", Vector2(628, 484)));
    add(createImage("Sprites/Credits/credit_2.png", Vector2(619, 473)));
    add(createImage("Sprites/Credits/credit_3.png", Vector2(529, 941)));
}

std::unique_ptr<GameObject> CreditsScene::createImage(std::string filePath, Vector2 size) {
    auto spriteObj = std::make_unique<GameObject>();
    auto spriteComp = std::make_unique<SpriteComponent>();
    spriteComp->spritePath = filePath;
    spriteComp->spriteSize = std::make_unique<Vector2>(size);
    spriteComp->tileOffset = std::make_unique<Vector2>(0, 0);

    spriteObj->addComponent(std::move(spriteComp));

    auto& transform = spriteObj->tryGetComponent<TransformComponent>();
    auto bottomY = (ConfigSingleton::getInstance().getWindowSize().getY() / 2) + (size.getY() / 2);
    transform.position->setY(bottomY);

    return std::move(spriteObj);
}
