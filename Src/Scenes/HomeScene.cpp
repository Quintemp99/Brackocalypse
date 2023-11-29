#include "HomeScene.hpp"
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Button.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "../RogueLikeSheetMap.hpp"
#include "../Player.hpp"
#include "../../Scripts/FollowGameObject.hpp"

HomeScene::HomeScene(BrackEngine& brackEngine) : Scene() {
    auto camera = Camera();
    camera.AddComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    camera.SetTag("mainCamera");
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

    auto startButton = std::make_unique<Button>(Vector2(210, 70), "Start game");
    startButton->SetFontSize(40);
    startButton->SetClickEvent([](){
        std::cout << "CLICKED" << std::endl;
    });

    auto transformStartButton = std::make_unique<TransformComponent>();
    transformStartButton->position = std::make_unique<Vector2>(centerX, 300);
    startButton->AddComponent(std::move(transformStartButton));
    this->AddGameObject(std::move(startButton));
}