//
// Created by jesse on 21/12/2023.
//

#include "FullScreenHandler.hpp"
#include "EngineManagers/InputManager.hpp"
#include "Helpers/KeyMap.hpp"
#include <ConfigSingleton.hpp>

void FullScreenHandler::onStart() {
}

void FullScreenHandler::onUpdate(milliseconds deltaTime) {
    if (InputManager::GetInstance().IsKeyClicked(F11))
        ConfigSingleton::getInstance().toggleFullScreen();
}
