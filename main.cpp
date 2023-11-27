#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Player.hpp"
#include "Scripts/FollowGameObject.hpp"
#include "Src/LevelBuilder.hpp"

void homescreen (BrackEngine brackEngine) {
    auto camera = Camera();
    camera.AddComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    camera.SetTag("mainCamera");
    camera.AddComponent(FollowGameObject("Player"));
    auto scene = Scene(std::move(camera));

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
    scene.AddGameObject(std::move(imageBg));

    SceneManager::getInstance().setActiveScene(scene);
}

void game(BrackEngine brackEngine) {
    auto camera = Camera();
    camera.AddComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    camera.SetTag("mainCamera");
    camera.AddComponent(FollowGameObject("Player"));
    auto scene = Scene(std::move(camera));

    std::vector<std::vector<std::string>> map{};
    map.emplace_back();
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWLQQQQQQQQQQNWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWVYYYYYYYYYYCWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");

    map.emplace_back();
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("..........J.........");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");

    auto levelBuilder = LevelBuilder(map);

    levelBuilder.buildLevel();

    for (auto& go: levelBuilder.gameObjects) {
        scene.AddGameObject(std::move(go));
    }

    SceneManager::getInstance().setActiveScene(scene);
}

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));

    homescreen(brackEngine);

    brackEngine.Run();
    return 0;
}