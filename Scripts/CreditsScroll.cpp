//
// Created by stijn on 21-12-2023.
//

#include "CreditsScroll.hpp"
#include "Components/TransformComponent.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "../Src/Scenes/LevelManager.hpp"

void CreditsScroll::onStart() {

}

void CreditsScroll::onUpdate(milliseconds deltaTime) {
    auto credits = getGameObjectsByTag("Credit");

    for(int i = 0; i < credits.size(); ++i) {
        auto& credit = credits[i];
        auto& transform = credit->tryGetComponent<TransformComponent>();

        if(i == currentNewestIndex) {
            if(!credit->isActive())
                credit->setActive(true);

            auto spawnMin = (ConfigSingleton::getInstance().getWindowSize().getY() / 2) - 50;

            if(transform.position->getY() < spawnMin)
                if(credits.size() - 1 > currentNewestIndex)
                    ++currentNewestIndex;
        }

        if(credit->isActive()) {
            transform.position->setY(transform.position->getY() - 0.05);

            int topScreen = -1*(ConfigSingleton::getInstance().getWindowSize().getY()/2)-20;
            if(transform.position->getY() < topScreen) {
                if(currentNewestIndex == credits.size() - 1 && credit == credits[currentNewestIndex])
                    LevelManager::getInstance().goToSpecificLevel(0);
                else
                    credit->setActive(false);
            }
        }
    }
}
