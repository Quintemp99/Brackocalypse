//
// Created by SKIKK on 14/12/2023.
//

#ifndef BRACKOCALYPSE_ENEMYFOLLOWPLAYER_HPP
#define BRACKOCALYPSE_ENEMYFOLLOWPLAYER_HPP

#include <BehaviourScripts/BehaviourScript.hpp>
#include <utility>

class EnemyFollowPlayer : public BehaviourScript {
public:
    EnemyFollowPlayer(std::string graphName) : BehaviourScript(), graphName(std::move(graphName)) {}

    ~EnemyFollowPlayer() override = default;

    void onStart() override;

    void onUpdate(float deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<EnemyFollowPlayer>(*this);
    }

    EnemyFollowPlayer(const EnemyFollowPlayer &other) : BehaviourScript(other) {}

    std::string graphName;
};



#endif //BRACKOCALYPSE_ENEMYFOLLOWPLAYER_HPP
