//
// Created by Stijn Laptop on 14-12-2023.
//

#include "EndScreen.hpp"
#include "HomeScene.hpp"
#include <Components/AIComponent.hpp>
#include <Objects/Button.hpp>

EndScreen::EndScreen() {
    auto &camera = getCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(255, 0, 0, 255));

    //Start button
    auto backToHome = std::make_unique<Button>(Vector2(270, 70), "Back to Home");
    backToHome->setFontSize(40);
    backToHome->setClickEvent([](){
        auto homeScene = new HomeScene();
        SceneManager::getInstance().goToNewScene(homeScene);
    });
    this->addGameObject(std::move(backToHome));
}
