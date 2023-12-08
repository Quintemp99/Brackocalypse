//
// Created by SKIKK on 17/11/2023.
//

#ifndef BRACKOCALYPSE_PLAYER_HPP
#define BRACKOCALYPSE_PLAYER_HPP


#include <Objects/GameObject.hpp>

class Player : public GameObject {
public:
    Player(GameObject *spawnLocationMapTile);

    Player(size_t layer, Vector2 position);

    ~Player() = default;

private:
    void init(size_t layer, Vector2 position);
};


#endif //BRACKOCALYPSE_PLAYER_HPP
