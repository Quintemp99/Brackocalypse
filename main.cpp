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

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(800, 600);

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    auto scene = Scene(std::move(camera));

    GameObject object = GameObject();

    SpriteComponent *sprite = new SpriteComponent();

    object.AddComponent(sprite);


    Text text = Text("Poepjes", 40);

    scene.AddGameObject(object);
    scene.AddGameObject(text);


    for(int i = 0; i < 10; ++i) {
        GameObject object = GameObject();
        SpriteComponent *sprite = new SpriteComponent();
        sprite->spritePath = ConfigSingleton::GetInstance().GetBaseAssetPath() + "Sprites/roguelikeSheet_transparent_1.bmp";
        sprite->spriteSize = std::make_unique<Vector2>(16, 16);
        sprite->position = std::make_unique<Vector2>(i*16, 10);
        sprite->tileOffset = std::make_unique<Vector2>(6,0);
        sprite->scale = std::make_unique<Vector2>(1, 1);
        sprite->margin = 1;

        object.AddComponent(sprite);
        scene.AddGameObject(object);
    }

    SceneManager::GetInstance().SetActiveScene(scene);

    brackEngine.Run();
    return 0;
}