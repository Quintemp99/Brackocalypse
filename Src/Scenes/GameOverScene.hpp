//
// Created by Olaf van den Berg on 19-12-2023.
//

#ifndef BRACKOCALYPSE_GAMEOVERSCENE_HPP
#define BRACKOCALYPSE_GAMEOVERSCENE_HPP


#include <Objects/Scene.hpp>

class GameOverScene : public Scene {
public:
    GameOverScene();
    void build() override;
};


#endif //BRACKOCALYPSE_GAMEOVERSCENE_HPP
