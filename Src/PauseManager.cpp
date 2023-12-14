//
// Created by Stef van Stipdonk on 14/12/2023.
//

#include "PauseManager.hpp"
#include "../Scripts/PauseHandler.hpp"

PauseManager::PauseManager() {
    auto pauseHandler = std::make_unique<PauseHandler>();
    addBehaviourScript(std::move(pauseHandler));
    setName("PauseManager");
    setTag("PauseManager");
}