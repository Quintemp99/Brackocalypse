#include "PlayerProgress.hpp"
#include <EngineManagers/SceneManager.hpp>
#include <Components/RectangleComponent.hpp>
#include "../Src/Helpers/RogueLikeSheetMap.hpp"
#include "UserInputMovement.hpp"
#include "../Src/Components/HealthComponent.hpp"
#include "../Src/Scenes/GameOverScene.hpp"
#include "../Src/Scenes/InterludeOneScene.hpp"
#include "../Src/Scenes/LevelManager.hpp"
#include "RandomGenerator.hpp"

void PlayerProgress::onStart() {

}

void PlayerProgress::onUpdate(milliseconds deltaTime) {
    auto progressBar = getGameObjectByTag("ProgressBar");
    if (!progressBar.has_value())
        return;
    
    auto &progressBarRectangle = progressBar.value().tryGetComponent<RectangleComponent>();
    auto& progressBarBackground = progressBar.value().getChildGameObjectByName("ProgressBarBackground").value()->tryGetComponent<RectangleComponent>();
    int progressWidth = progressBarBackground.size->getX() / 100 * (beersCollected * beersNeeded);
    progressBarRectangle.size->setX(progressWidth);

    auto beerImage = progressBar.value().getChildGameObjectByName("BeerImage");
    if (beerImage.has_value()){
        auto& beerImageTransform = beerImage.value()->tryGetComponent<TransformComponent>();
        beerImageTransform.position->setX(progressWidth - 20);
        
    }
    
    auto &health = tryGetComponent<HealthComponent>();
    if (beersCollected >= beersNeeded ) {
        LevelManager::getInstance().goToNextLevel();
    }
    if (health.health <= 0) {
        auto scene = new GameOverScene();
        scene->build();
        SceneManager::getInstance().goToNewScene(scene);
    }
}

void PlayerProgress::addBeer() {
    beersCollected++;
    auto progressBar = getGameObjectByTag("ProgressBar");
    if (!progressBar.has_value())
        return;
    auto beerImage = progressBar.value().getChildGameObjectByName("BeerImage");
    if (!beerImage.has_value())
        return;
    auto& beerImageTransform = beerImage.value()->tryGetComponent<TransformComponent>();
    beerImageTransform.rotation = RandomGenerator::randomFloat(-20,20);
}
