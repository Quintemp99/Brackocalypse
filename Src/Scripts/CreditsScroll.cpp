//
// Created by stijn on 21-12-2023.
//

#include "CreditsScroll.hpp"
#include "Components/TransformComponent.hpp"
#include <ConfigSingleton.hpp>
#include "../Scenes/LevelManager.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TextComponent.hpp"
#include <EngineManagers/InputManager.hpp>
#include <Helpers/KeyMap.hpp>

void CreditsScroll::onStart() {

}

void CreditsScroll::onUpdate(milliseconds deltaTime) {
    if (InputManager::getInstance().IsKeyClicked(KeyMap::RETURN)) {
        LevelManager::getInstance().goToNextLevel();
    }

    auto credits = getGameObjectsByTag("Credit");

    for (int i = 0; i < credits.size(); ++i) {
        auto &credit = credits[i];
        auto &transform = credit->tryGetComponent<TransformComponent>();
        int body = getCreditHeight(*credit);

        if (i == currentNewestIndex) {
            if (!credit->isActive())
                credit->setActive(true);

            auto spawnMin = (ConfigSingleton::getInstance().getInitialWindowSize().getY()) - (extraSpace + body);

            if (transform.position->getY() < spawnMin)
                if (credits.size() - 1 > currentNewestIndex)
                    ++currentNewestIndex;
        }

        if (credit->isActive()) {
            transform.position->setY(transform.position->getY() - speed);

            int topScreen = (-1) * (ConfigSingleton::getInstance().getInitialWindowSize().getY() / 2) - (body / 2);
            if (transform.position->getY() < topScreen) {
                if (currentNewestIndex == credits.size() - 1 && credit == credits[currentNewestIndex])
                    LevelManager::getInstance().goToSpecificLevel(HOME_SCENE);
                else
                    credit->setActive(false);
            }
        }
    }
}

int CreditsScroll::getCreditHeight(GameObject &gameObject) {
    if (gameObject.hasComponent<SpriteComponent>()) {
        auto &spriteComp = gameObject.tryGetComponent<SpriteComponent>();
        return spriteComp.spriteSize->getY();
    }

    if (gameObject.hasComponent<TextComponent>()) {
        auto &textComp = gameObject.tryGetComponent<TextComponent>();
        return textComp.fontSize;
    }

    return 0;
}
