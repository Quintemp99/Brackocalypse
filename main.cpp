#include <iostream>
#include "GameEngine.hpp"

int main() {
    GameEngine gameEngine = GameEngine();
    if (gameEngine.Initialize()) {
        gameEngine.Run();
        gameEngine.Cleanup();
    }

    return 0;
}
