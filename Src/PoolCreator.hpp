//
// Created by Olaf van den Berg on 11-12-2023.
//

#ifndef BRACKOCALYPSE_POOLCREATOR_HPP
#define BRACKOCALYPSE_POOLCREATOR_HPP

#include <Objects/GameObject.hpp>

class PoolCreator {
public:
    PoolCreator() = default;

    ~PoolCreator() = default;

    template<typename T>
    std::unique_ptr<GameObject> createPool(size_t layer, size_t poolSize) {
        auto gameObject = std::make_unique<GameObject>(layer);


        for (size_t i = 0; i < poolSize; i++) {
            auto obj = std::make_unique<T>(layer);
            obj->setActive(false);
            gameObject->addChild(std::move(obj));

        }
        return gameObject;
    }

};


#endif //BRACKOCALYPSE_POOLCREATOR_HPP
