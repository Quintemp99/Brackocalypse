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

    std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<BlockPlayer>(*this);
    }

    void accept(ComponentVisitor &visitor) override {
        visitor.visit(*this);
        onStart();
    }

    BlockPlayer(const BlockPlayer &other) : BehaviourScript(other) {}

};


#endif //BRACKOCALYPSE_BLOCKPLAYER_HPP
