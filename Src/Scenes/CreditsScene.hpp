//
// Created by stijn on 21-12-2023.
//

#ifndef BRACKOCALYPSE_CREDITSSCENE_HPP
#define BRACKOCALYPSE_CREDITSSCENE_HPP

#include <Objects/Scene.hpp>
#include "Components/TextComponent.hpp"
#include "../Scripts/CreditsScroll.hpp"

class CreditsScene : public Scene {
public:
    CreditsScene() = default;

    void build() override;
private:
    std::vector<std::unique_ptr<GameObject>> credits;
    std::unique_ptr<GameObject> createText(std::string text);
    std::unique_ptr<GameObject> createImage(std::string filePath, Vector2 size);

    void add(std::unique_ptr<GameObject> component);
};


#endif //BRACKOCALYPSE_CREDITSSCENE_HPP
