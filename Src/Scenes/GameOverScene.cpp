//
// Created by Olaf van den Berg on 19-12-2023.
//

#include "GameOverScene.hpp"
#include "HomeScene.hpp"
#include <Helpers/Vector2.hpp>
#include <Objects/Button.hpp>

GameOverScene::GameOverScene() {
    auto &camera = getCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(255, 255, 0, 255));

    //Start button
    auto backToHome = std::make_unique<Button>(Vector2(270, 70), "Back to Home");
    backToHome->setFontSize(40);
    backToHome->setClickEvent([]() {
        auto homeScene = new HomeScene();
        SceneManager::getInstance().goToNewScene(homeScene);
    });
    this->addGameObject(std::move(backToHome));
}