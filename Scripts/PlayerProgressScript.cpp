#include "PlayerProgressScript.hpp"
#include <EngineManagers/SceneManager.hpp>
#include <Components/RectangleComponent.hpp>
#include <Components/TextComponent.hpp>
#include "../Src/Helpers/RogueLikeSheetMap.hpp"
#include "UserInputMovement.hpp"
#include "../Src/Components/HealthComponent.hpp"
#include "../Src/Scenes/GameOverScene.hpp"
#include "../Src/Scenes/LevelManager.hpp"
#include "RandomGenerator.hpp"

void PlayerProgressScript::onStart() {

}

void PlayerProgressScript::onUpdate(milliseconds deltaTime) {
    auto player = getGameObjectByTag("Player");
    if (!player.has_value())
        return;

    auto &health = player.value().tryGetComponent<HealthComponent>();

    if (health.health <= 0) {
        setBeersCollected(0);
        setZombiesKilled(0);
        auto scene = new GameOverScene();
        scene->build();
        SceneManager::getInstance().goToNewScene(scene);
    }

    auto progressBar = getGameObjectByTag("ProgressBar");
    if (!progressBar.has_value())
        return;

    auto &progressBarRectangle = progressBar.value().tryGetComponent<RectangleComponent>();
    auto &progressBarBackground = progressBar.value().getChildGameObjectByName(
            "ProgressBarBackground").value()->tryGetComponent<RectangleComponent>();

    if (progressBarRectangle.size->getX() < newWidth) {
        progressBarRectangle.size->setX(progressBarRectangle.size->getX() + 1);

        auto beerImage = progressBar.value().getChildGameObjectByName("BeerImage");
        if (beerImage.has_value()) {
            auto &beerImageTransform = beerImage.value()->tryGetComponent<TransformComponent>();
            beerImageTransform.position->setX(progressBarRectangle.size->getX() - 20);
        }
    }

    if (progressBarRectangle.size->getX() >= progressBarBackground.size->getX()) {
        setNumberOfLives(health.health);
        setBeersCollected(0);
        LevelManager::getInstance().goToNextLevel();
    }

}

void PlayerProgressScript::addBeer() {
    ++beersCollected;
    auto progressBar = getGameObjectByTag("ProgressBar");
    if (!progressBar.has_value())
        return;
    auto &progressBarBackground = progressBar.value().getChildGameObjectByName(
            "ProgressBarBackground").value()->tryGetComponent<RectangleComponent>();
    newWidth = progressBarBackground.size->getX() / 100 * (100 / beersNeeded * beersCollected);
    auto beerImage = progressBar.value().getChildGameObjectByName("BeerImage");
    if (!beerImage.has_value())
        return;
    auto &beerImageTransform = beerImage.value()->tryGetComponent<TransformComponent>();
    beerImageTransform.rotation = RandomGenerator::randomFloat(5, 25);
    if (beersCollected % 2 == 0)
        beerImageTransform.rotation *= -1;
}

void PlayerProgressScript::addZombieKill() {
    ++zombiesKilled;

    auto textObject = getGameObjectByName("EnemyKillText");
    if (!textObject.has_value())
        return;

    auto &textComponent = textObject.value()->tryGetComponent<TextComponent>();
    textComponent.text = std::to_string(zombiesKilled);
}

void PlayerProgressScript::setBeersCollected(int amount) {
    beersCollected = amount;
    auto progressBar = getGameObjectByTag("ProgressBar");
    if (!progressBar.has_value())
        return;
    auto &progressBarBackground = progressBar.value().getChildGameObjectByName(
            "ProgressBarBackground").value()->tryGetComponent<RectangleComponent>();
    newWidth = progressBarBackground.size->getX() / 100 * (100 / beersNeeded * beersCollected);
    auto beerImage = progressBar.value().getChildGameObjectByName("BeerImage");
    if (!beerImage.has_value())
        return;
    auto &beerImageTransform = beerImage.value()->tryGetComponent<TransformComponent>();
    beerImageTransform.rotation = RandomGenerator::randomFloat(5, 25);
    if (beersCollected % 2 == 0)
        beerImageTransform.rotation *= -1;
}
