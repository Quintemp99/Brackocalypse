//
// Created by SKIKK on 19/12/2023.
//

#ifndef BRACKOCALYPSE_STORYSCENE_HPP
#define BRACKOCALYPSE_STORYSCENE_HPP


#include <Objects/Scene.hpp>

class StoryScene : public Scene {
public:
    StoryScene(std::vector<std::string> lines);
    void build() override;
private:
    Scene* nextScene;
    std::vector<std::string> lines_;
};


#endif //BRACKOCALYPSE_STORYSCENE_HPP
