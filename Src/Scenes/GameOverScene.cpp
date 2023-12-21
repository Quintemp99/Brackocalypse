#include "GameOverScene.hpp"
#include "HomeScene.hpp"
#include "LevelManager.hpp"
#include "Components/PersistenceTag.hpp"
#include "../../Scripts/ToggleFPS.hpp"
#include "Components/SoundTrackComponent.hpp"
#include "../../../Brack-Engine/src/ConfigSingleton.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TextComponent.hpp"
#include <Objects/Button.hpp>

GameOverScene::GameOverScene() {

}

void GameOverScene::build() {
    Scene::build();
    auto obj = std::make_unique<GameObject>();
    obj->addComponent(std::make_unique<PersistenceTag>());
    if (obj) {
        obj->addBehaviourScript(std::make_unique<ToggleFPS>());
    }
    addGameObject(std::move(obj));
    auto &camera = getCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(255, 255, 0, 255));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/game_over.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));

    auto bgImage = std::make_unique<GameObject>();
    auto bgImageSprite = std::make_unique<SpriteComponent>();
    bgImageSprite->spritePath = "Sprites/beer_background.png";
    bgImageSprite->spriteSize = std::make_unique<Vector2>(1049, 699);
    bgImageSprite->tileOffset = std::make_unique<Vector2>(0, 0);
    bgImageSprite->orderInLayer = 2;
    auto &transformBgImage = bgImage->tryGetComponent<TransformComponent>();
    transformBgImage.position = std::make_unique<Vector2>(0, 0);
    transformBgImage.scale = std::make_unique<Vector2>(1, 1);
    bgImage->addComponent(std::move(bgImageSprite));
    addGameObject(std::move(bgImage));

    auto player = std::make_unique<GameObject>();

    auto sprite = std::make_unique<SpriteComponent>();
    sprite->spritePath = "Sprites/character_maleAdventurer_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96, 128);
    sprite->orderInLayer = 1;
    sprite->tileOffset = std::make_unique<Vector2>(8, 4);

    auto& transformBg = player->tryGetComponent<TransformComponent>();
    transformBg.position = std::make_unique<Vector2>(0, -150);
    transformBg.scale = std::make_unique<Vector2>(1, 1);
    player->addComponent(std::move(sprite));
    addGameObject(std::move(player));

    auto gameOverText = std::make_unique<GameObject>();
    auto textComp = std::make_unique<TextComponent>();
    textComp->text = "Game Over";
    textComp->fontSize = 40;
    textComp->color->a = 255;
    textComp->color->r = 255;
    textComp->color->g = 255;
    textComp->color->b = 255;

    auto& transformText = gameOverText->tryGetComponent<TransformComponent>();
    transformText.position = std::make_unique<Vector2>(0, -80);
    transformText.scale = std::make_unique<Vector2>(1, 1);
    gameOverText->addComponent(std::move(textComp));
    addGameObject(std::move(gameOverText));

    auto centerY = ConfigSingleton::getInstance().getWindowSize().getY() / 2;
    auto centerX = ConfigSingleton::getInstance().getWindowSize().getX() / 2;

    //Back to home button
    auto homeButton = std::make_unique<Button>(Vector2(250, 70), "Back to Home");
    homeButton->setFontSize(40);
    homeButton->setClickEvent([]() {
        LevelManager::getInstance().goToSpecificLevel(0);
    });

    auto &transformStartButton = homeButton->tryGetComponent<TransformComponent>();
    transformStartButton.position = std::make_unique<Vector2>(centerX - 125, centerY + 80);
    addGameObject(std::move(homeButton));
}
