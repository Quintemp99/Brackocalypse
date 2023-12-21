#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/Helpers/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Scenes/HomeScene.hpp"
#include "EngineManagers/CollisionLayerManager.hpp"

int main()
{
    Config config = new Config();
    config.showFPS = true;
    config.deltaTimeMultiplier = 1.0;
    config.windowTitle = "Brackocalypse";
    config.initialWindowSize = Vector2(1280, 720);

    BrackEngine brackEngine = BrackEngine(std::move(config));

    auto& collisionManager = CollisionLayerManager::getInstance();

    collisionManager.defineCollision("Player");
    collisionManager.defineCollision("Enemy");
    collisionManager.defineCollision("PlayerHitbox");
    collisionManager.defineCollision("EnemyHitbox");
    collisionManager.defineCollision("Bullet");
    collisionManager.defineCollision("Crate");
    collisionManager.defineCollision("Wall");
    collisionManager.defineCollision("Collectable");

    collisionManager.defineMask("PlayerHitbox", {"EnemyHitbox", "Collectable"});
    collisionManager.defineMask("Collectable", {"PlayerHitbox"});
    collisionManager.defineMask("EnemyHitbox", {"PlayerHitbox", "Bullet"});
    collisionManager.defineMask("Player", {"Wall", "Crate", "Enemy"});
    collisionManager.defineMask("Enemy", {"Wall", "Crate", "Player", "Enemy"});
    collisionManager.defineMask("Bullet", {"EnemyHitbox", "Crate"});
    collisionManager.defineMask("Crate", {"Bullet", "Player", "Enemy", "Wall"});
    collisionManager.defineMask("Wall", {"Player", "Enemy", "Crate"});
    auto scene = new HomeScene();
    scene->build();
    SceneManager::getInstance().goToNewScene(scene);

    brackEngine.Run();
    return 0;
}
