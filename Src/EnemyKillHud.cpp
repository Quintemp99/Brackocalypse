//
// Created by jesse on 21/12/2023.
//

#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/TextComponent.hpp>
#include <EngineManagers/SceneManager.hpp>
#include "EnemyKillHud.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "../Scripts/PlayerProgressScript.hpp"

EnemyKillHud::EnemyKillHud() {
    setTag("EnemyKillHud");
    setName("EnemyKillHud");
    
    auto spriteComponent = std::make_unique<SpriteComponent>();
    spriteComponent->spritePath = "Sprites/character_zombie_sheet.png";
    spriteComponent->spriteSize = std::make_unique<Vector2>(96, 128);
    spriteComponent->sortingLayer = 0;
    spriteComponent->orderInLayer = 0;
    spriteComponent->tileOffset = std::make_unique<Vector2>(8, 4);
    
    auto screenSize = ConfigSingleton::getInstance().getInitialWindowSize();
    
    auto &transform = tryGetComponent<TransformComponent>();
    transform.scale = std::make_unique<Vector2>(0.75, 0.75);
    transform.position = std::make_unique<Vector2>(screenSize.getX() -75, -15);
    addComponent(std::move(spriteComponent));
    
    auto playerProgress = SceneManager::getInstance().getGameObjectByName("PlayerProgress");
    auto &playerProgressScript = playerProgress.value()->tryGetBehaviourScript<PlayerProgressScript>();
    auto textObject = std::make_unique<GameObject>();
    textObject->setTag("EnemyKillText");
    textObject->setName("EnemyKillText");
    auto textComponent = std::make_unique<TextComponent>();
    textComponent->text = std::to_string(playerProgressScript.getZombiesKilled());
    textComponent->orderInLayer = 0;
    textComponent->sortingLayer = 0;
    textComponent->fontSize = 40;
    textComponent->color = std::make_unique<Color>(255, 255, 255, 255);
    textComponent->alignment = Alignment::RIGHTTOP;
    textObject->addComponent(std::move(textComponent));
    
    auto &textTransform = textObject->tryGetComponent<TransformComponent>();
    textTransform.position = std::make_unique<Vector2>(-5, 25);
    
    addChild(std::move(textObject));
}
