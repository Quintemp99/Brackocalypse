#include "BeerPool.hpp"
#include "Beer.hpp"
#include "../Scripts/SpawnInBeers.hpp"

BeerPool::BeerPool(size_t poolSize) {
    setTag("BeerPool");
    setName("BeerPool");
    addBehaviourScript(SpawnInBeers());
    for (size_t i = 0; i < poolSize; i++) {
        auto beer = std::make_unique<Beer>();
        beer->setActive(false);
        addChild(std::move(beer));
    }
}