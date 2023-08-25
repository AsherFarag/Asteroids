#pragma once
#include "Component.h"
#include "RigidBody2D.h"
#include "Transformation.h"

class PlayerController :
    public Component
{
public:
    // Inherited via Component
    virtual void Update(float a_DeltaTime) override;
    virtual void Draw() override;
    virtual void SetUpComponent() override;

private:
    RigidBody2D* m_AttachedObjectRB;
    Transformation* m_AttachedObjectTransform;

#pragma region Movement

    Vec3 m_Acceleration = Vec3{ 100.0f, 100.0f, 0.0f };
    Vec3 m_MaxVelocity = Vec3{ 15.0f, 15.0f, 0.0f };

#pragma endregion
};

