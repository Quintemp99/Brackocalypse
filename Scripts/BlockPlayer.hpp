//
// Created by Olaf van den Berg on 28-11-2023.
//

#ifndef BRACKOCALYPSE_BLOCKPLAYER_HPP
#define BRACKOCALYPSE_BLOCKPLAYER_HPP


#include <Components/BehaviourScript.hpp>

class BlockPlayer : public BehaviourScript {
public:
    BlockPlayer() : BehaviourScript() {}

    ~BlockPlayer() override = default;

    void onStart() override;

    void onUpdate(float deltaTime) override;

    std::unique_ptr<BehaviourScript> clone() const override {
        return std::make_unique<BlockPlayer>(*this);
    }


    BlockPlayer(const BlockPlayer &other) : BehaviourScript(other) {}

    int getPriority() const { return priority; }

    int priority;

};


#endif //BRACKOCALYPSE_BLOCKPLAYER_HPP
