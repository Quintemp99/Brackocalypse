#include <iostream>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"

int main() {
    BrackEngine brackEngine = BrackEngine();
    auto scene = Scene();
    SceneManager::GetInstance().SetActiveScene(scene);
    while(true){
        brackEngine.Update();
    }
    return 0;
}
