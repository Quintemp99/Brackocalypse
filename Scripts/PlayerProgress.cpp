#include "PlayerProgress.hpp"
#include <EngineManagers/SceneManager.hpp>
#include <Components/RectangleComponent.hpp>
#include "../Src/Helpers/RogueLikeSheetMap.hpp"
#include "UserInputMovement.hpp"
#include "../Src/Scenes/EndScreen.hpp"

void PlayerProgress::onStart() {

}

void PlayerProgress::onUpdate(float deltaTime) {
    int totalProgress = beersCollected - foodCollected;

    auto& progressBar = getGameObjectByTag("ProgressBar")->tryGetComponent<RectangleComponent>();
    int progressWidth = 300 / 100 * (totalProgress * 10);
    progressBar.size->setX(progressWidth);

    if(totalProgress >= maxForLevel) {
        //TODO: Go to next level
        maxForLevel += 10;

        auto scene = new EndScreen();
        SceneManager::getInstance().goToNewScene(scene);
    }
}