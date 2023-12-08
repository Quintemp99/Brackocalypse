#include "GoToNextLevel.hpp"
#include <EngineManagers/SceneManager.hpp>
#include <Components/ChildComponent.hpp>

#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Components/SoundTrackComponent.hpp>
#include <Objects/Button.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Src/Helpers/RogueLikeSheetMap.hpp"
#include "UserInputMovement.hpp"
#include "../Src/Player.hpp"
#include "FollowGameObject.hpp"
#include "../Src/LevelBuilder.hpp"
#include "../Src/Gun.hpp"
#include "../Src/Bullet.hpp"
#include "../Src/BulletPool.hpp"
#include "../Src/Scenes/HomeScene.hpp"

void GoToNextLevel::onStart() {

}

void GoToNextLevel::onUpdate(float deltaTime) {
    auto player = getGameObjectByTag("Player");
    auto beers = player->getChildrenWithTag("Beer");

    int totalProgress = beers.size();

    if(totalProgress >= maxForLevel) {
        //TODO: Go to next level

        auto camera = Camera();
        camera.addComponent(VelocityComponent());
        camera.SetBackgroundColor(Color(255, 0, 0, 255));
        auto scene = Scene(std::move(camera));

        //Start button
        auto backToHome = std::make_unique<Button>(Vector2(270, 70), "Back to Home");
        backToHome->setFontSize(40);
        backToHome->setClickEvent([](){
            auto scene = HomeScene();
            SceneManager::getInstance().setActiveScene(scene);
        });
        scene.addGameObject(std::move(backToHome));

        maxForLevel += 10;
        SceneManager::getInstance().setActiveScene(scene);
    }
}