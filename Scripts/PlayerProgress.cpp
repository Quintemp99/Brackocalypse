#include "PlayerProgress.hpp"
#include <EngineManagers/SceneManager.hpp>
#include <Components/ChildComponent.hpp>

#include <Components/AIComponent.hpp>
#include <Objects/Button.hpp>
#include "Objects/Scene.hpp"
#include "../Src/Helpers/RogueLikeSheetMap.hpp"
#include "UserInputMovement.hpp"
#include "../Src/Scenes/HomeScene.hpp"

void PlayerProgress::onStart() {

}

void PlayerProgress::onUpdate(float deltaTime) {
    int totalProgress = beersCollected - foodCollected;

    if(totalProgress >= maxForLevel) {
        //TODO: Go to next level

        auto camera = Camera();
        camera.addComponent(VelocityComponent());
        camera.SetBackgroundColor(Color(255, 0, 0, 255));
        auto scene = new Scene(std::move(camera));

        //Start button
        auto backToHome = std::make_unique<Button>(Vector2(270, 70), "Back to Home");
        backToHome->setFontSize(40);
        backToHome->setClickEvent([](){
            auto homeScene = new HomeScene();
            SceneManager::getInstance().goToNewScene(homeScene);
        });
        scene->addGameObject(std::move(backToHome));

        maxForLevel += 10;
        SceneManager::getInstance().goToNewScene(scene);
    }
}