#ifndef BRACKOCALYPSE_COLLECTBEERS_HPP
#define BRACKOCALYPSE_COLLECTBEERS_HPP

#include <BehaviourScripts/BehaviourScript.hpp>

class CollectBeers : public BehaviourScript {
public:
    CollectBeers() : BehaviourScript() {}
    ~CollectBeers() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<CollectBeers>(*this);
    }

    virtual void onStart() override;
    virtual void onUpdate(milliseconds deltaTime) override;
};


#endif //BRACKOCALYPSE_COLLECTBEERS_HPP
