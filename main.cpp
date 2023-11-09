#include <iostream>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Text.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
//#include "../Brack-Engine/src/FPSSingleton.hpp"

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

    SceneManager::GetInstance().SetActiveScene(scene);

    brackEngine.Run();
    return 0;
}
