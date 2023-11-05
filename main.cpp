#include <iostream>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"

int main() {
    BrackEngine brackEngine = BrackEngine();
    auto scene = Scene();
    SceneManager::GetInstance().SetActiveScene(scene);
    brackEngine.Update();
    return 0;
}
