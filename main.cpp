#include <iostream>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"

int main() {
    BrackEngine brackEngine = BrackEngine(Config());
    auto camera = Camera();
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    auto scene = Scene(std::move(camera));

    GameObject object = GameObject();

    SpriteComponent *sprite = new SpriteComponent();

    object.AddComponent(sprite);

    scene.AddGameObject(object);

    SceneManager::GetInstance().SetActiveScene(scene);

    brackEngine.Run();
    return 0;
}
