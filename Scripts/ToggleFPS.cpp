//
// Created by Stef van Stipdonk on 15/12/2023.
//

#include "ToggleFPS.hpp"
#include "EngineManagers/InputManager.hpp"
#include "EngineManagers/SceneManager.hpp"
#include <Helpers/KeyMap.hpp>


void ToggleFPS::onStart() {
}

void ToggleFPS::onUpdate(float deltaTime) {
    if (InputManager::GetInstance().IsKeyClicked(KeyMap::f)) {
        SceneManager::getInstance().toggleFPS();
    }
}