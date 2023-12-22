//
// Created by Olaf van den Berg on 19-12-2023.
//

#ifndef BRACKOCALYPSE_ENEMYDAMAGE_HPP
#define BRACKOCALYPSE_ENEMYDAMAGE_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class EnemyDamage : public BehaviourScript {
public:
    EnemyDamage() : BehaviourScript() {
    }

    ~EnemyDamage() override = default;

    void onStart() override;

    void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<EnemyDamage>(*this);
    }

    EnemyDamage(const EnemyDamage &other) : BehaviourScript(other) {
        damage = other.damage;
        damageCooldown = other.damageCooldown;
        damageTimer = other.damageTimer;
    }

private:
    int damage = 1;
    milliseconds damageCooldown = 1000;
    milliseconds damageTimer = damageCooldown;
};


#endif //BRACKOCALYPSE_ENEMYDAMAGE_HPP
