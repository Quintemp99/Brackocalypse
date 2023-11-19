#include <iostream>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Text.hpp>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
//#include "../Brack-Engine/src/FPSSingleton.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Components/AudioComponent.hpp"
#include "Src/SaveLoad.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(800, 600);

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    auto scene = Scene(std::move(camera));

    SaveLoad saveLoad = SaveLoad(brackEngine);
    saveLoad.save();
    saveLoad.load();

    auto object = std::make_unique<GameObject>();
    auto audio = AudioComponent();
    object->AddComponent(audio);

    auto text = std::make_unique<Text>("Poepjes");

    scene.AddGameObject(std::move(object));
    scene.AddGameObject(std::move(text));

    for(int i = 0; i < 10; ++i) {
        auto object = std::make_unique<GameObject>();
        auto sprite = std::make_unique<SpriteComponent>();
        sprite->spritePath = ConfigSingleton::GetInstance().GetBaseAssetPath() + "Sprites/roguelikeSheet_transparent_1.bmp";
        sprite->spriteSize = std::make_unique<Vector2>(16, 16);
        sprite->tileOffset = std::make_unique<Vector2>(6,0);
        sprite->margin = 1;

        object->AddComponent(std::move(sprite));
        scene.AddGameObject(std::move(object));
    }

    SceneManager::GetInstance().SetActiveScene(scene);

    brackEngine.Run();
    return 0;
}