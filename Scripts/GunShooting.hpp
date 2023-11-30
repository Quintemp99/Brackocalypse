//
// Created by jesse on 30/11/2023.
//

#ifndef BRACKOCALYPSE_GUNSHOOTING_HPP
#define BRACKOCALYPSE_GUNSHOOTING_HPP


#include <Components/BehaviourScript.hpp>

class GunShooting : public BehaviourScript {
public:
    GunShooting() : BehaviourScript() {}

    ~GunShooting() override = default;

    virtual void onStart() override;

    virtual void onUpdate(float deltaTime) override;

    std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<GunShooting>(*this);
    }

    void accept(ComponentVisitor &visitor) override {
        visitor.visit(*this);
        onStart();
    }

    GunShooting(const GunShooting &other) :
            BehaviourScript(other) {};
private:
    float cameraShakeIntensity = 2.5f;
    float cameraShakeDuration = 0.1f;
    float cameraShakeTimer = 0.0f;
    bool shaking = false;
    Vector2 originalCameraPosition;
    std::mt19937 randomGenerator{std::random_device{}()};
    std::uniform_real_distribution<float> distribution{-1.0f, 1.0f};

    void shakeCamera();

};


#endif //BRACKOCALYPSE_GUNSHOOTING_HPP
