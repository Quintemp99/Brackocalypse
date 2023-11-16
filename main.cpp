#include <iostream>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Text.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/RogueLikeSheetMap.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    auto scene = Scene(std::move(camera));

    int spriteMargin = 1;
    Vector2 spriteScale = Vector2(4,4);
    Vector2 spriteSize = Vector2(16,16);
    std::string spritePath = ConfigSingleton::GetInstance().GetBaseAssetPath() + "Sprites/roguelikeSheet_transparent_1.bmp";
    RogueLikeSheetMap rogueLikeSheetMap = RogueLikeSheetMap();

    std::vector<std::string> bottomLayer{};
    bottomLayer.push_back("LQQQQQQQQN");
    bottomLayer.push_back("UGGGGGGGGP");
    bottomLayer.push_back("UGGGGGGGGP");
    bottomLayer.push_back("UGGGGGGGGP");
    bottomLayer.push_back("UGGGGGGGGP");
    bottomLayer.push_back("UGGGGGGGGP");
    bottomLayer.push_back("UGGGGZXGGP");
    bottomLayer.push_back("UGGGGBMGGP");
    bottomLayer.push_back("UGGGGGGGGP");
    bottomLayer.push_back("VYYYYYYYYC");

    std::size_t y = 0;
    for (std::string row : bottomLayer) {
        std::size_t x = 0;
        for (char c : row) {
            auto object = std::make_unique<GameObject>();
            auto sprite = std::make_unique<SpriteComponent>();
            // dit kunnen header info dingen zijn voor de string map die je kan maken.
            sprite->spritePath = spritePath;
            sprite->spriteSize = std::make_unique<Vector2>(spriteSize);
            sprite->scale = std::make_unique<Vector2>(spriteScale);
            sprite->margin = spriteMargin;
            sprite->position = std::make_unique<Vector2>((x*64), (y*64));
            sprite->tileOffset = std::make_unique<Vector2>(rogueLikeSheetMap.map[static_cast<RogueLikeSheetType>(c)]);
            object->AddComponent(std::move(sprite));
            scene.AddGameObject(std::move(object));
            x++;
        }
        y++;
    }

    auto topWall = std::make_unique<GameObject>();
    auto topWallCollider = std::make_unique<BoxCollisionComponent>(Vector2(640,60));

    topWall->AddComponent(std::move(topWallCollider));

    scene.AddGameObject(std::move(topWall));

    SceneManager::GetInstance().SetActiveScene(scene);

    brackEngine.Run();
    return 0;
}