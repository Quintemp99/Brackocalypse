#include "HomeScene.hpp"
#include <Components/AIComponent.hpp>
#include <Objects/Button.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/SoundTrackComponent.hpp>
#include <ConfigSingleton.hpp>
#include "StoryScene.hpp"
#include "../SaveLoadGame.hpp"
#include "LevelManager.hpp"
#include "Components/PersistenceTag.hpp"
#include "Components/TextComponent.hpp"
#include "../PlayerProgress.hpp"
#include "../Scripts/FullScreenHandler.hpp"
#include "../Scripts/ToggleFPS.hpp"

HomeScene::HomeScene() : Scene() {
}

void HomeScene::build() {
    Scene::build();
    auto obj = std::make_unique<GameObject>();
    obj->addComponent(std::make_unique<PersistenceTag>());
    if (obj) {
        obj->addBehaviourScript(std::make_unique<ToggleFPS>());
    }
    addGameObject(std::move(obj));
    auto &camera = getCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(99, 197, 207, 255));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/atje.mp3");
    backgroundSound->volume = 0.2;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));
    auto windowSize = ConfigSingleton::getInstance().getWindowSize();

    auto bgImage = std::make_unique<GameObject>();
    auto bgImageSprite = std::make_unique<SpriteComponent>();
    bgImageSprite->spritePath = "Sprites/background_homescreen.png";
    bgImageSprite->spriteSize = std::make_unique<Vector2>(1264, 717);
    bgImageSprite->tileOffset = std::make_unique<Vector2>(0, 0);
    bgImageSprite->orderInLayer = 1;
    auto &transformBgImage = bgImage->tryGetComponent<TransformComponent>();
    transformBgImage.position = std::make_unique<Vector2>(0, 0);
    transformBgImage.scale = std::make_unique<Vector2>(1, 1);
    bgImage->addComponent(std::move(bgImageSprite));
    addGameObject(std::move(bgImage));


    auto logo = std::make_unique<GameObject>();

    auto textComponent = std::make_unique<TextComponent>();
    textComponent->text = "Brackocalypse";
    textComponent->fontSize = 40;
    textComponent->alignment = Alignment::CENTERCENTER;

    auto transformBg = std::make_unique<TransformComponent>();
    transformBg->position = std::make_unique<Vector2>(0, -100);
    transformBg->scale = std::make_unique<Vector2>(0.6, 0.6);
    logo->addComponent(std::move(textComponent));
    logo->addComponent(std::move(transformBg));
    addGameObject(std::move(logo));

    auto centerY = ConfigSingleton::getInstance().getInitialWindowSize().getY() / 2;
    auto centerX = ConfigSingleton::getInstance().getInitialWindowSize().getX() / 2;

    if (SaveLoadGame::getInstance().canLoad()) {
        auto loadButton = std::make_unique<Button>(Vector2(210, 70), "Load game");
        loadButton->setFontSize(20);
        loadButton->setClickEvent([]() {
            SaveLoadGame::getInstance().load();
        });

        auto &transformLoadButton = loadButton->tryGetComponent<TransformComponent>();
        transformLoadButton.position = std::make_unique<Vector2>(centerX - 105, centerY + 150);
        addGameObject(std::move(loadButton));
    }

    //Start button
    auto startButton = std::make_unique<Button>(Vector2(210, 70), "Start game");
    startButton->setFontSize(20);
    startButton->setClickEvent([]() {
        LevelManager::getInstance().goToNextLevel();
    });

    auto &transformStartButton = startButton->tryGetComponent<TransformComponent>();
    transformStartButton.position = std::make_unique<Vector2>(-150 + centerX - 105, centerY + 50);
    addGameObject(std::move(startButton));

    //Quit button
    auto quitButton = std::make_unique<Button>(Vector2(210, 70), "Quit");
    quitButton->setFontSize(20);
    quitButton->setClickEvent([]() {
        ConfigSingleton::getInstance().toggleIsRunning();
    });

    auto &transformQuitButton = quitButton->tryGetComponent<TransformComponent>();
    transformQuitButton.position = std::make_unique<Vector2>(150 + centerX - 105, centerY + 50);
    addGameObject(std::move(quitButton));

    auto fullScreenToggle = SceneManager::getGameObjectByName("FullScreenToggle");
    if (!fullScreenToggle.has_value()) {
        auto fullScreenToggleObject = std::make_unique<GameObject>();
        fullScreenToggleObject->setName("FullScreenToggle");
        fullScreenToggleObject->setTag("FullScreenToggle");
        fullScreenToggleObject->addComponent(std::make_unique<PersistenceTag>());
        fullScreenToggleObject->addBehaviourScript(std::make_unique<FullScreenHandler>());
        addGameObject(std::move(fullScreenToggleObject));
    }

    auto playerPorgress = SceneManager::getGameObjectByName("PlayerProgress");
    if (!playerPorgress.has_value()) {
        auto playerProgressObject = std::make_unique<PlayerProgress>();
        addGameObject(std::move(playerProgressObject));
    }

}
