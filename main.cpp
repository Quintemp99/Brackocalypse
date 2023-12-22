#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include <ConfigSingleton.hpp>
#include "EngineManagers/CollisionLayerManager.hpp"
#include "Src/Scenes/LevelManager.hpp"

int main() {
    Config config = new Config();
    config.showFPS = true;
    config.deltaTimeMultiplier = 1.0;
    config.windowTitle = "Brackocalypse";
    config.initialWindowSize = Vector2(1280, 720);

    BrackEngine brackEngine = BrackEngine(std::move(config));

    auto &collisionManager = CollisionLayerManager::getInstance();

    collisionManager.defineCollision("Player");
    collisionManager.defineCollision("Enemy");
    collisionManager.defineCollision("PlayerHitbox");
    collisionManager.defineCollision("EnemyHitbox");
    collisionManager.defineCollision("Bullet");
    collisionManager.defineCollision("Crate");
    collisionManager.defineCollision("Wall");
    collisionManager.defineCollision("SolidWall");
    collisionManager.defineCollision("Collectable");

    collisionManager.defineMask("PlayerHitbox", {"EnemyHitbox", "Collectable"});
    collisionManager.defineMask("Collectable", {"PlayerHitbox"});
    collisionManager.defineMask("EnemyHitbox", {"PlayerHitbox", "Bullet"});
    collisionManager.defineMask("Player", {"Wall", "SolidWall", "Crate", "Enemy"});
    collisionManager.defineMask("Enemy", {"Wall", "SolidWall", "Crate", "Player", "Enemy"});
    collisionManager.defineMask("Bullet", {"EnemyHitbox", "Crate", "SolidWall"});
    collisionManager.defineMask("Crate", {"Bullet", "Player", "Enemy", "Wall"});
    collisionManager.defineMask("Wall", {"Player", "Enemy", "Crate"});
    collisionManager.defineMask("SolidWall", {"Player", "Enemy", "Crate", "Bullet"});

    LevelManager::getInstance().startLoop(HOME_SCENE);
    try {
        brackEngine.Run();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
