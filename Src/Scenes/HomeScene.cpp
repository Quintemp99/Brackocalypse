#include "HomeScene.hpp"
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Button.hpp>
#include "BrackEngine.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "../RogueLikeSheetMap.hpp"
#include "../Player.hpp"
#include "DemoLevel.hpp"

HomeScene::HomeScene() : Scene() {
    auto camera = Camera();
    camera.AddComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    this->AddCamera(std::move(camera));

    auto imageBg = std::make_unique<GameObject>();
    auto spriteBg = std::make_unique<SpriteComponent>();
    spriteBg->spritePath = "Sprites/logo.png";
    spriteBg->spriteSize = std::make_unique<Vector2>(500, 500);
    spriteBg->imageSize = std::make_unique<Vector2>(100,100);
    spriteBg->tileOffset = std::make_unique<Vector2>(0, 0);

    auto transformBg = std::make_unique<TransformComponent>();
    auto windowSize = ConfigSingleton::GetInstance().GetWindowSize();
    auto centerX = windowSize.getX() / 2 - ((500/1*0.4)/2);
    transformBg->position = std::make_unique<Vector2>(centerX, 30);
    transformBg->scale = std::make_unique<Vector2>(0.4, 0.4);
    imageBg->AddComponent(std::move(spriteBg));
    imageBg->AddComponent(std::move(transformBg));
    this->AddGameObject(std::move(imageBg));

    //Start button
    auto startButton = std::make_unique<Button>(Vector2(210, 70), "Start game");
    startButton->SetFontSize(40);
    startButton->SetClickEvent([](){
        auto scene = DemoLevel();
        SceneManager::getInstance().setActiveScene(scene);
    });

    auto transformStartButton = std::make_unique<TransformComponent>();
    transformStartButton->position = std::make_unique<Vector2>(centerX - 150, 300);
    startButton->AddComponent(std::move(transformStartButton));
    this->AddGameObject(std::move(startButton));

    //Quit button
    auto quitButton = std::make_unique<Button>(Vector2(210, 70), "Quit");
    quitButton->SetFontSize(40);
    quitButton->SetClickEvent([](){
        std::exit(0);
    });

    auto transformQuitButton = std::make_unique<TransformComponent>();
    transformQuitButton->position = std::make_unique<Vector2>(centerX + 150, 300);
    quitButton->AddComponent(std::move(transformQuitButton));
    this->AddGameObject(std::move(quitButton));
}