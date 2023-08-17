#pragma once
#include "Component.h"
#include "raylib.h"
#include "Transformation.h"

class RigidBody2D :
    public Component
{
public:

    Transformation* m_AttachedObjectTransform;

    virtual void Update(float a_DeltaTime) override;
    virtual void Draw() override;

    virtual void SetUpComponent() override;

    #pragma region Movement Functions

    void SetLinearDrag(Vec3 a_LinearDrag) { m_LinearDrag = a_LinearDrag; }
    void SetAngularDrag(float a_AngularDrag) { m_AngularDrag = a_AngularDrag; }

    void SetLinearAcceleration(Vec3 a_LinearAcceleration) { m_LinearAcceleration = a_LinearAcceleration; }
    void SetLinearAcceleration(float a_LinearSpeed);
    void SetAngularAcceleration(float a_AngularAcceleration) { m_AngularAcceleration = a_AngularAcceleration; }

    void SetLinearVelocity(Vec3 a_LinearVelocity) { m_LinearVelocity = a_LinearVelocity; }
    void SetLinearVelocity(float a_LinearSpeed);
    void SetAngularVelocity(float a_AngularVelocity) { m_AngularVelocity = a_AngularVelocity; }

    #pragma endregion

private:
    float m_Mass;

    // ===== Linear =====
    Vec3  m_LinearDrag; // Don't ask how there is friction in a vacumn
    Vec3  m_LinearVelocity;
    Vec3  m_LinearAcceleration;

    // ===== Angular =====
    float m_AngularDrag;
    float m_AngularVelocity;
    float m_AngularAcceleration;
};

