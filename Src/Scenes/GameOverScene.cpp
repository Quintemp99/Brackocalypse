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

    auto center = ConfigSingleton::getInstance().getInitialWindowSize() / 2;

    auto bgImage = std::make_unique<GameObject>();
    auto bgImageSprite = std::make_unique<SpriteComponent>();
    bgImageSprite->spritePath = "Sprites/beer_background.png";
    bgImageSprite->spriteSize = std::make_unique<Vector2>(1048, 698);
    bgImageSprite->tileOffset = std::make_unique<Vector2>(0, 0);
    bgImageSprite->orderInLayer = 2;
    bgImageSprite->sortingLayer = 0;
    auto &transformBgImage = bgImage->tryGetComponent<TransformComponent>();
    transformBgImage.scale = std::make_unique<Vector2>(1.25, 1.25);
    transformBgImage.position = std::make_unique<Vector2>(
            center - *bgImageSprite->spriteSize * *transformBgImage.scale / 2);
    bgImage->addComponent(std::move(bgImageSprite));
    addGameObject(std::move(bgImage));

    auto player = std::make_unique<GameObject>();

    auto sprite = std::make_unique<SpriteComponent>();
    sprite->spritePath = "Sprites/character_maleAdventurer_sheet.png";
    sprite->spriteSize = std::make_unique<Vector2>(96, 128);
    sprite->orderInLayer = 1;
    sprite->sortingLayer = 0;
    sprite->tileOffset = std::make_unique<Vector2>(8, 4);

    auto &transformBg = player->tryGetComponent<TransformComponent>();
    transformBg.scale = std::make_unique<Vector2>(1.25, 1.25);
    transformBg.position = std::make_unique<Vector2>(
            center + Vector2(0, -150) - *sprite->spriteSize * *transformBg.scale / 2);
    player->addComponent(std::move(sprite));
    addGameObject(std::move(player));

    auto gameOverText = std::make_unique<GameObject>();
    auto textComp = std::make_unique<TextComponent>();
    textComp->text = "Game Over";
    textComp->alignment = Alignment::CENTERCENTER;
    textComp->orderInLayer = 1;
    textComp->sortingLayer = 0;
    textComp->fontSize = 40;
    textComp->color->a = 255;
    textComp->color->r = 255;
    textComp->color->g = 255;
    textComp->color->b = 255;

    auto &transformText = gameOverText->tryGetComponent<TransformComponent>();
    transformText.position = std::make_unique<Vector2>(center + Vector2(0, -20));
    transformText.scale = std::make_unique<Vector2>(1, 1);
    gameOverText->addComponent(std::move(textComp));
    addGameObject(std::move(gameOverText));

    //Back to home button
    auto homeButton = std::make_unique<Button>(Vector2(250, 70), "Back to Home");
    homeButton->setFontSize(20);
    homeButton->setClickEvent([]() {
        LevelManager::getInstance().goToSpecificLevel(0);
    });

    auto &transformStartButton = homeButton->tryGetComponent<TransformComponent>();
    transformStartButton.position = std::make_unique<Vector2>(center + Vector2(-125, 80));
    addGameObject(std::move(homeButton));
}
