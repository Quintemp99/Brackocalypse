#include <Components/TileMapComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/Helpers/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Scenes/HomeScene.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));

    auto scene = HomeScene();
    auto gameObject = std::make_unique<GameObject>();
    auto tileMap = std::make_unique<TileMapComponent>();

    tileMap->tileMapPath = "Sprites/roguelikeSheet_transparent_1.bmp";
    tileMap->tileSize = std::make_unique<Vector2>(16, 16);
    tileMap->margin = 1;

    auto row = std::vector<std::unique_ptr<Vector2>>();
    row.emplace_back(std::make_unique<Vector2>(2, 0));
    row.emplace_back(std::make_unique<Vector2>(4, 0));
    row.emplace_back(std::make_unique<Vector2>(6, 0));

    auto row2 = std::vector<std::unique_ptr<Vector2>>();
    row2.emplace_back(std::make_unique<Vector2>(2, 2));
    row2.emplace_back(nullptr);
    row2.emplace_back(std::make_unique<Vector2>(4, 2));
    tileMap->tileMap.emplace_back(std::move(row));
    tileMap->tileMap.emplace_back(std::move(row2));

    auto &transformComponent = gameObject->tryGetComponent<TransformComponent>();
    transformComponent.position = std::make_unique<Vector2>(100, 100);
    transformComponent.scale = std::make_unique<Vector2>(4, 4);

    gameObject->addComponent(std::move(tileMap));
    scene.addGameObject(std::move(gameObject));
    SceneManager::getInstance().setActiveScene(scene);

    brackEngine.Run();
    return 0;
}